@echo off & goto:$Main

:$Main
setlocal EnableDelayedExpansion
    call "%~dp0build.bat" raddbg                            %*
    if errorlevel 1 goto:$MainError
    call "%~dp0build.bat" raddbgi_from_pdb                  %*
    if errorlevel 1 goto:$MainError
    call "%~dp0build.bat" raddbgi_from_dwarf                %*
    if errorlevel 1 goto:$MainError
    call "%~dp0build.bat" raddbgi_dump                      %*
    if errorlevel 1 goto:$MainError
    call "%~dp0build.bat" raddbgi_breakpad_from_pdb         %*
    if errorlevel 1 goto:$MainError
    call "%~dp0build.bat" ryan_scratch                      %*
    if errorlevel 1 goto:$MainError
    call "%~dp0build.bat" cpp_tests                         %*
    if errorlevel 1 goto:$MainError
    call "%~dp0build.bat" look_at_raddbg                    %*
    if errorlevel 1 goto:$MainError
    call "%~dp0build.bat" mule_main                         %*
    if errorlevel 1 goto:$MainError
    call "%~dp0build.bat" mule_module                       %*
    if errorlevel 1 goto:$MainError
    call "%~dp0build.bat" mule_hotload                      %*
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
    exit /b %errorlevel%
)
