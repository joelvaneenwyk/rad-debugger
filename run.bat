@echo off & goto:$Main

:$Main
setlocal EnableDelayedExpansion
    call :Clear

    :: --- Unpack Arguments -------------------------------------------------------
    for %%a in (%*) do                                 set "%%a=1"
    if not "%msvc%"=="1" if not "%clang%"=="1"         set "msvc=1"
    if not "%release%"=="1"                            set "debug=1"

    if "!release!"=="1"                                set "_config=release"
    if "!debug!"=="1"                                  set "_config=debug"

    if "!msvc!"=="1"                                   set "_compiler=msvc"
    if "!clang!"=="1"                                  set "_compiler=clang"

    call "%~dp0build.bat" raddbg                       "!_compiler!" "!_config!"
    if errorlevel 1 goto:$MainError
    call "%~dp0build.bat" raddbgi_from_pdb             "!_compiler!" "!_config!"
    if errorlevel 1 goto:$MainError
    call "%~dp0build.bat" raddbgi_from_dwarf           "!_compiler!" "!_config!"
    if errorlevel 1 goto:$MainError
    call "%~dp0build.bat" raddbgi_dump                 "!_compiler!" "!_config!"
    if errorlevel 1 goto:$MainError
    call "%~dp0build.bat" raddbgi_breakpad_from_pdb    "!_compiler!" "!_config!"
    if errorlevel 1 goto:$MainError
    call "%~dp0build.bat" ryan_scratch              "!_compiler!" "!_config!"
    if errorlevel 1 goto:$MainError
    call "%~dp0build.bat" cpp_tests                    "!_compiler!" "!_config!"
    if errorlevel 1 goto:$MainError
    call "%~dp0build.bat" look_at_raddbg            "!_compiler!" "!_config!"
    if errorlevel 1 goto:$MainError
    call "%~dp0build.bat" mule_main                    "!_compiler!" "!_config!"
    if errorlevel 1 goto:$MainError
    call "%~dp0build.bat" mule_module                  "!_compiler!" "!_config!"
    if errorlevel 1 goto:$MainError
    call "%~dp0build.bat" mule_hotload                 "!_compiler!" "!_config!"
    if errorlevel 1 goto:$MainError

    set _error=%errorlevel%
    echo [INFO][!_error!] Built all projects with '!_compiler!' compiler and '!_config!' configuration.
    goto:$MainDone

    :$MainError
    set _error=%errorlevel%
    echo [ERROR][!_error!] Failed to build projects.
    goto:$MainDone

    :$MainDone
endlocal & (
    call :Clear
    exit /b %errorlevel%
)

:Clear
    set "_build="
    set "_error="
    set "_exe="
    set "_inc="
    set "_root="
    set "_var="
    set "__DOTNET_ADD_64BIT="
    set "__DOTNET_PREFERRED_BITNESS="
    set "__VSCMD_PREINIT_PATH="
    set "release="
    set "raddbg="
    set "msvc="
    set "link_dll="
    set "net="
    set "INCLUDE="
    set "gfx="
    set "LINES="
    set "clink_dummy_capture_env="
    set "LIB="
    set "Ehsc="
    set "cl_obj="
    set "cl_link="
    set "cl_common="
    set "clang_out="
    set "cl="
    set "clang="
exit /b 0
