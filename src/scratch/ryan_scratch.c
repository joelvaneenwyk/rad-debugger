// Copyright (c) 2024 Epic Games Tools
// Licensed under the MIT license (https://opensource.org/license/mit/)

////////////////////////////////
//~ rjf: Build Options

#define BUILD_TITLE "ryan_scratch"
#define BUILD_CONSOLE_INTERFACE 1

////////////////////////////////
//~ rjf: Includes

//- rjf: [lib]
#include "lib_rdi_format/rdi_format.h"
#include "lib_rdi_format/rdi_format.c"
#include "third_party/rad_lzb_simple/rad_lzb_simple.h"
#include "third_party/rad_lzb_simple/rad_lzb_simple.c"

//- rjf: [h]
#include "base/base_inc.h"
#include "os/os_inc.h"
#include "task_system/task_system.h"
#include "rdi_make/rdi_make_local.h"
#include "coff/coff.h"
#include "codeview/codeview.h"
#include "codeview/codeview_stringize.h"
#include "msf/msf.h"
#include "pdb/pdb.h"
#include "pdb/pdb_stringize.h"

//- rjf: [c]
#include "base/base_inc.c"
#include "os/os_inc.c"
#include "task_system/task_system.c"
#include "rdi_make/rdi_make_local.c"
#include "coff/coff.c"
#include "codeview/codeview.c"
#include "codeview/codeview_stringize.c"
#include "msf/msf.c"
#include "pdb/pdb.c"
#include "pdb/pdb_stringize.c"

////////////////////////////////
//~ rjf: Entry Point

internal void
entry_point(CmdLine *cmdline)
{
  Arena *arena = arena_alloc();
  RDIM_SortKey keys_unsorted[] = {{1, (void *)2}, {2}, {3}, {1, (void *)1}, {2}, {3}, {1, (void *)3}, {2}, {3}, {1, (void *)4}, {2}, {3}, {1, (void *)5}, {2}, {3}};
  U64 keys_count = ArrayCount(keys_unsorted);
  RDIM_SortKey *keys_sorted = rdim_sort_key_array(arena, keys_unsorted, keys_count);
  for(U64 idx = 0; idx < keys_count; idx += 1)
  {
    printf("%I64u (%I64u),", keys_sorted[idx].key, (U64)keys_sorted[idx].val);
  }
  printf("\n");
}
