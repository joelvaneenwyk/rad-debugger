// Copyright (c) 2024 Epic Games Tools
// Licensed under the MIT license (https://opensource.org/license/mit/)

////////////////////////////////
//~ rjf: Frontend Entry Points

internal void
update_and_render(OS_Handle repaint_window_handle, void *user_data)
{
  ProfTick(0);
  ProfBeginFunction();
  Temp scratch = scratch_begin(0, 0);
  
  //- rjf: tick cache layers
  txt_user_clock_tick();
  geo_user_clock_tick();
  tex_user_clock_tick();
  
  //- rjf: pick target hz
  // TODO(rjf): maximize target, given all windows and their monitors
  F32 target_hz = os_default_refresh_rate();
  if(frame_time_us_history_idx > 32)
  {
    // rjf: calculate average frame time out of the last N
    U64 num_frames_in_history = Min(ArrayCount(frame_time_us_history), frame_time_us_history_idx);
    U64 frame_time_history_sum_us = 0;
    for(U64 idx = 0; idx < num_frames_in_history; idx += 1)
    {
      frame_time_history_sum_us += frame_time_us_history[idx];
    }
    U64 frame_time_history_avg_us = frame_time_history_sum_us/num_frames_in_history;
    
    // rjf: pick among a number of sensible targets to snap to, given how well
    // we've been performing
    F32 possible_alternate_hz_targets[] = {target_hz, 60.f, 120.f, 144.f, 240.f};
    F32 best_target_hz = target_hz;
    S64 best_target_hz_frame_time_us_diff = max_S64;
    for(U64 idx = 0; idx < ArrayCount(possible_alternate_hz_targets); idx += 1)
    {
      F32 candidate = possible_alternate_hz_targets[idx];
      if(candidate <= target_hz)
      {
        U64 candidate_frame_time_us = 1000000/(U64)candidate;
        S64 frame_time_us_diff = (S64)frame_time_history_avg_us - (S64)candidate_frame_time_us;
        if(abs_s64(frame_time_us_diff) < best_target_hz_frame_time_us_diff)
        {
          best_target_hz = candidate;
          best_target_hz_frame_time_us_diff = frame_time_us_diff;
        }
      }
    }
    target_hz = best_target_hz;
  }
  
  //- rjf: target Hz -> delta time
  F32 dt = 1.f/target_hz;
  
  //- rjf: last frame before sleep -> disable txti change detection
  if(df_gfx_state->num_frames_requested == 0)
  {
    txti_set_external_change_detection_enabled(0);
  }
  
  //- rjf: get events from the OS
  OS_EventList events = {0};
  if(os_handle_match(repaint_window_handle, os_handle_zero()))
  {
    events = os_get_events(scratch.arena, df_gfx_state->num_frames_requested == 0);
  }
  
  //- rjf: enable txti change detection
  txti_set_external_change_detection_enabled(1);
  
  //- rjf: begin measuring actual per-frame work
  U64 begin_time_us = os_now_microseconds();
  
  //- rjf: bind change
  if(!df_gfx_state->confirm_active && df_gfx_state->bind_change_active)
  {
    if(os_key_press(&events, os_handle_zero(), 0, OS_Key_Esc))
    {
      df_gfx_request_frame();
      df_gfx_state->bind_change_active = 0;
    }
    if(os_key_press(&events, os_handle_zero(), 0, OS_Key_Delete))
    {
      df_gfx_request_frame();
      df_unbind_spec(df_gfx_state->bind_change_cmd_spec, df_gfx_state->bind_change_binding);
      df_gfx_state->bind_change_active = 0;
      DF_CmdParams p = df_cmd_params_from_gfx();
      df_push_cmd__root(&p, df_cmd_spec_from_core_cmd_kind(df_g_cfg_src_write_cmd_kind_table[DF_CfgSrc_User]));
    }
    for(OS_Event *event = events.first, *next = 0; event != 0; event = next)
    {
      if(event->kind == OS_EventKind_Press &&
         event->key != OS_Key_Esc &&
         event->key != OS_Key_Return &&
         event->key != OS_Key_Backspace &&
         event->key != OS_Key_Delete &&
         event->key != OS_Key_LeftMouseButton &&
         event->key != OS_Key_RightMouseButton &&
         event->key != OS_Key_Ctrl &&
         event->key != OS_Key_Alt &&
         event->key != OS_Key_Shift)
      {
        df_gfx_state->bind_change_active = 0;
        DF_Binding binding = zero_struct;
        {
          binding.key = event->key;
          binding.flags = event->flags;
        }
        df_unbind_spec(df_gfx_state->bind_change_cmd_spec, df_gfx_state->bind_change_binding);
        df_bind_spec(df_gfx_state->bind_change_cmd_spec, binding);
        U32 codepoint = os_codepoint_from_event_flags_and_key(event->flags, event->key);
        os_text(&events, os_handle_zero(), codepoint);
        os_eat_event(&events, event);
        DF_CmdParams p = df_cmd_params_from_gfx();
        df_push_cmd__root(&p, df_cmd_spec_from_core_cmd_kind(df_g_cfg_src_write_cmd_kind_table[DF_CfgSrc_User]));
        df_gfx_request_frame();
        break;
      }
    }
  }
  
  //- rjf: take hotkeys
  {
    for(OS_Event *event = events.first, *next = 0;
        event != 0;
        event = next)
    {
      next = event->next;
      DF_Window *window = df_window_from_os_handle(event->window);
      DF_CmdParams params = window ? df_cmd_params_from_window(window) : df_cmd_params_from_gfx();
      if(event->kind == OS_EventKind_Press)
      {
        DF_Binding binding = {event->key, event->flags};
        DF_CmdSpecList spec_candidates = df_cmd_spec_list_from_binding(scratch.arena, binding);
        if(spec_candidates.first != 0 && !df_cmd_spec_is_nil(spec_candidates.first->spec))
        {
          DF_CmdSpec *run_spec = df_cmd_spec_from_core_cmd_kind(DF_CoreCmdKind_RunCommand);
          DF_CmdSpec *spec = spec_candidates.first->spec;
          if(run_spec != spec)
          {
            params.cmd_spec = spec;
            df_cmd_params_mark_slot(&params, DF_CmdParamSlot_CmdSpec);
          }
          U32 hit_char = os_codepoint_from_event_flags_and_key(event->flags, event->key);
          os_eat_event(&events, event);
          df_push_cmd__root(&params, run_spec);
          if(event->flags & OS_EventFlag_Alt)
          {
            window->menu_bar_focus_press_started = 0;
          }
        }
        df_gfx_request_frame();
      }
      else if(event->kind == OS_EventKind_Text)
      {
        String32 insertion32 = str32(&event->character, 1);
        String8 insertion8 = str8_from_32(scratch.arena, insertion32);
        DF_CmdSpec *spec = df_cmd_spec_from_core_cmd_kind(DF_CoreCmdKind_InsertText);
        params.string = insertion8;
        df_cmd_params_mark_slot(&params, DF_CmdParamSlot_String);
        df_push_cmd__root(&params, spec);
        df_gfx_request_frame();
        os_eat_event(&events, event);
        if(event->flags & OS_EventFlag_Alt)
        {
          window->menu_bar_focus_press_started = 0;
        }
      }
    }
  }
  
  //- rjf: menu bar focus
  {
    for(OS_Event *event = events.first, *next = 0; event != 0; event = next)
    {
      next = event->next;
      DF_Window *ws = df_window_from_os_handle(event->window);
      if(ws == 0)
      {
        continue;
      }
      B32 take = 0;
      if(event->kind == OS_EventKind_Press && event->key == OS_Key_Alt && event->flags == 0 && event->is_repeat == 0)
      {
        take = 1;
        df_gfx_request_frame();
        ws->menu_bar_focused_on_press = ws->menu_bar_focused;
        ws->menu_bar_key_held = 1;
        ws->menu_bar_focus_press_started = 1;
      }
      if(event->kind == OS_EventKind_Release && event->key == OS_Key_Alt && event->flags == 0 && event->is_repeat == 0)
      {
        take = 1;
        df_gfx_request_frame();
        ws->menu_bar_key_held = 0;
      }
      if(ws->menu_bar_focused && event->kind == OS_EventKind_Press && event->key == OS_Key_Alt && event->flags == 0 && event->is_repeat == 0)
      {
        take = 1;
        df_gfx_request_frame();
        ws->menu_bar_focused = 0;
      }
      else if(ws->menu_bar_focus_press_started && !ws->menu_bar_focused && event->kind == OS_EventKind_Release && event->flags == 0 && event->key == OS_Key_Alt && event->is_repeat == 0)
      {
        take = 1;
        df_gfx_request_frame();
        ws->menu_bar_focused = !ws->menu_bar_focused_on_press;
        ws->menu_bar_focus_press_started = 0;
      }
      else if(event->kind == OS_EventKind_Press && event->key == OS_Key_Esc && ws->menu_bar_focused && !ui_any_ctx_menu_is_open())
      {
        take = 1;
        df_gfx_request_frame();
        ws->menu_bar_focused = 0;
      }
      if(take)
      {
        os_eat_event(&events, event);
      }
    }
  }
  
  //- rjf: gather root-level commands
  DF_CmdList cmds = df_core_gather_root_cmds(scratch.arena);
  
  //- rjf: begin frame
  df_core_begin_frame(scratch.arena, &cmds, dt);
  df_gfx_begin_frame(scratch.arena, &cmds);
  
  //- rjf: queue drop for drag/drop
  if(df_drag_is_active())
  {
    for(OS_Event *event = events.first; event != 0; event = event->next)
    {
      if(event->kind == OS_EventKind_Release && event->key == OS_Key_LeftMouseButton)
      {
        df_queue_drag_drop();
        break;
      }
    }
  }
  
  //- rjf: auto-focus moused-over windows while dragging
  if(df_drag_is_active())
  {
    B32 over_focused_window = 0;
    {
      for(DF_Window *window = df_gfx_state->first_window; window != 0; window = window->next)
      {
        Vec2F32 mouse = os_mouse_from_window(window->os);
        Rng2F32 rect = os_client_rect_from_window(window->os);
        if(os_window_is_focused(window->os) && contains_2f32(rect, mouse))
        {
          over_focused_window = 1;
          break;
        }
      }
    }
    if(!over_focused_window)
    {
      for(DF_Window *window = df_gfx_state->first_window; window != 0; window = window->next)
      {
        Vec2F32 mouse = os_mouse_from_window(window->os);
        Rng2F32 rect = os_client_rect_from_window(window->os);
        if(!os_window_is_focused(window->os) && contains_2f32(rect, mouse))
        {
          os_window_focus(window->os);
          break;
        }
      }
    }
  }
  
  //- rjf: update & render
  {
    d_begin_frame();
    for(DF_Window *w = df_gfx_state->first_window; w != 0; w = w->next)
    {
      df_window_update_and_render(scratch.arena, &events, w, &cmds);
    }
  }
  
  //- rjf: end frontend frame, send signals, etc.
  df_gfx_end_frame();
  df_core_end_frame();
  
  //- rjf: submit rendering to all windows
  {
    r_begin_frame();
    for(DF_Window *w = df_gfx_state->first_window; w != 0; w = w->next)
    {
      r_window_begin_frame(w->os, w->r);
      d_submit_bucket(w->os, w->r, w->draw_bucket);
      r_window_end_frame(w->os, w->r);
    }
    r_end_frame();
  }
  
  //- rjf: take window closing events
  for(OS_Event *e = events.first, *next = 0; e; e = next)
  {
    next = e->next;
    if(e->kind == OS_EventKind_WindowClose)
    {
      for(DF_Window *w = df_gfx_state->first_window; w != 0; w = w->next)
      {
        if(os_handle_match(w->os, e->window))
        {
          DF_CmdParams params = df_cmd_params_from_window(w);
          df_push_cmd__root(&params, df_cmd_spec_from_core_cmd_kind(DF_CoreCmdKind_CloseWindow));
          break;
        }
      }
      os_eat_event(&events, e);
    }
  }
  
  //- rjf: determine frame time, record into history
  U64 end_time_us = os_now_microseconds();
  U64 frame_time_us = end_time_us-begin_time_us;
  frame_time_us_history[frame_time_us_history_idx%ArrayCount(frame_time_us_history)] = frame_time_us;
  frame_time_us_history_idx += 1;
  
  scratch_end(scratch);
  ProfEnd();
}

internal CTRL_WAKEUP_FUNCTION_DEF(wakeup_hook)
{
  os_send_wakeup_event();
}
