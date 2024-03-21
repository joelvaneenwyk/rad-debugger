@echo on & goto:$Main

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

:$Main
setlocal EnableDelayedExpansion
    call :Clear

    set "_compiler=%~1"
    if "%_compiler%"=="" set "_compiler=msvc"
    set "_config=%~2"
    if "%_config%"=="" set "_config=debug"

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
    :: call "%~dp0build.bat" ryan_scratch              "!_compiler!" "!_config!"
    :: if errorlevel 1 goto:$MainError
    call "%~dp0build.bat" cpp_tests                    "!_compiler!" "!_config!"
    if errorlevel 1 goto:$MainError
    :: call "%~dp0build.bat" look_at_raddbg            "!_compiler!" "!_config!"
    :: if errorlevel 1 goto:$MainError
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
endlocal
call :Clear
exit /b %errorlevel%
