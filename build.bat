@echo off && goto:$Main
:: --- Usage Notes (2024/1/10) ------------------------------------------------
::
:: This is a central build script for the RAD Debugger project. It takes a list
:: of simple alphanumeric-only arguments which control (a) what is built, (b)
:: which compiler & linker are used, and (c) extra high-level build options. By
:: default, if no options are passed, then the main "raddbg" graphical debugger
:: is built.
::
:: Below is a non-exhaustive list of possible ways to use the script:
:: `build raddbg`
:: `build raddbg clang`
:: `build raddbg release`
:: `build raddbg asan telemetry`
:: `build raddbgi_from_pdb`
::
:: For a full list of possible build targets and their build command lines,
:: search for @build_targets in this file.
::
:: Below is a list of all possible non-target command line options:
::
:: - `asan`: enable address sanitizer
:: - `telemetry`: enable RAD telemetry profiling support
::
:: cspell:ignore raddbg,asan,raddbgi,setlocal,endlocal,msvc,windsdk,errorlevel
:: cspell:ignore winsdk,winlibs,ucrt,hostx,bitness,vscmd,preinit,ehsc
:: cspell:ignore vcvarsall,libpath,nologo,bitfield,xclang,fdiagnostics
:: cspell:ignore dstrdup,dprofile,fsanitize,gcodeview,strdup,flto,dndebug
:: cspell:ignore userprofile,natvis,metagen,breakpad,hotload,dgnu,xlinker
:: cspell:ignore draddbg,endgroup,metaprogram

::-------------------------------------------------
:: Run a command and echo that command to console
::-------------------------------------------------
:Command
setlocal EnableExtensions
    set "_command=%*"
    goto:$CommandRun

    :CommandVar
    setlocal EnableDelayedExpansion
        set "_cmd=!%~1!"
        set "_cmd=!_cmd:      = !"
        set "_cmd=!_cmd:    = !"
        set "_cmd=!_cmd:   = !"
        set "_cmd=!_cmd:  = !"
        echo ##[command]!_cmd!
        call !_cmd!
    endlocal & exit /b %errorlevel%

    :$CommandRun
    call :CommandVar "_command"
endlocal & exit /b %errorlevel%

::-------------------------------------------------
:: Look for requested executable and set the provided variable to the full path
:: of that executable if found.
::-------------------------------------------------
:Find
setlocal EnableDelayedExpansion
    set "_var=%~1"
    set "_exe=%~2"
    if ["!_exe!"]==[""] set "_exe=%_var%"

    goto:$StartFind
    :$InnerFind
    setlocal EnableDelayedExpansion
        set "_variable=%~1"
        set "_executable=%~2"
        shift
        shift
        :$InnerFindLoop
            set "_vv=%~1"
            if "!_vv!"=="" goto:$InnerFindDone
            set "_out=!_vv!\%_executable%"
            shift
            if not exist "!_out!" goto:$InnerFindLoop

        :$InnerFindDone
    endlocal & (
      set "%_variable%=%_out%"
      exit /b 0
    )

    :$StartFind
    call :$InnerFind "!_var!" "!_exe!" ^
      "%msvc_path%\bin\Hostx64\x64" ^
      "%msvc_root%\VC\Tools\Llvm\x64\bin" ^
      "%winsdk_bin_path%\x64" ^
      "%mingw_winlibs_llvm%\bin" "%mingw_winlibs_llvm_ucrt%\bin" "%mingw_winlibs_llvm_ucrt_mcf%\bin"

    set "_result=!%_var%!"
    if not exist "!_result!" (
      set "_result=!_exe!"
    ) else (
      set _result="!_result!"
    )
    echo !_var!: !_result!
endlocal & (
  set %_var%=%_result%
)
exit /b %errorlevel%

::-------------------------------------------------
:: Clear known variables
::-------------------------------------------------
:Clear
    for %%a in ("__DOTNET_ADD_64BIT" "__DOTNET_PREFERRED_BITNESS" "__VSCMD_PREINIT_PATH" "_build" "_exe" "_inc" "_root" "_var" "cl_common" "cl_link" "cl_obj" "cl" "clang_out" "clang" "clink_dummy_capture_env" "compile_link" "compile" "debug" "Ehsc" "gfx" "INCLUDE" "LIB" "LINES" "link_dll" "msvc" "net" "out" "raddbg" "release") do (
        set "%%a="
    )
exit /b 0

::
::-------------------------------
:: Build
::-------------------------------
:Build
setlocal EnableDelayedExpansion
    set "_error=0"
    set "_variables=%*"
    set "_root=%~dp0"
    if "!_root:~-1!"=="\"                               set "_root=!_root:~0,-1!"

    :: --- Unpack Arguments -------------------------------------------------------
    set "_variables=%*"
    set "_variables=%*"
    for %%a in (!_variables!) do                        set "%%a=1"
    if not "%msvc%"=="1" if not "%clang%"=="1"          set "msvc=1"
    if not "%release%"=="1"                             set "debug=1"
    if "%debug%"=="1"                                   set "release=0" && echo [debug mode]
    if "%release%"=="1"                                 set "debug=0" && echo [release mode]
    if "%msvc%"=="1"                                    set "clang=0" && echo [msvc compile]
    if "%clang%"=="1"                                   set "msvc=0" && echo [clang compile]
    if "%~1"==""                                        echo [default mode, assuming `raddbg` build] && set raddbg=1

    if "!release!"=="1"                                 set "_config=release"
    if "!debug!"=="1"                                   set "_config=debug"
    if "!_config!"==""                                  set "_config=debug"

    if "!msvc!"=="1"                                    set "_compiler=msvc"
    if "!clang!"=="1"                                   set "_compiler=clang"
    if "!_compiler!"==""                                set "_compiler=msvc"

    if not exist "!_root!\build"                        mkdir "!_root!\build"
    if not exist "!_root!\build\!_compiler!"            mkdir "!_root!\build\!_compiler!"
    if not exist "!_root!\build\!_compiler!\!_config!"  mkdir "!_root!\build\!_compiler!\!_config!"
    set                                                 "_build=!_root!\build\!_compiler!\!_config!"

    :: --- Unpack Command Line Build Arguments ------------------------------------
    set "auto_compile_flags="
    if "%telemetry%"=="1"      set "auto_compile_flags=!auto_compile_flags! -DPROFILE_TELEMETRY=1" && echo [telemetry profiling enabled]
    if "%asan%"=="1"           set "auto_compile_flags=!auto_compile_flags! -fsanitize=address" && echo [asan enabled]

    goto:$MainSetPaths

    :GetPath
    setlocal EnableDelayedExpansion
        set "_var=%~1"
        set "_path_search=%~2"
        if not exist "!_path_search!" goto:$GetPathDone

        set "%_var%="
        set "_var_dir=%_var%_dir"
        set "%_var_dir%=%_path_search%"
        for /F "tokens=*" %%A IN ('dir /b /o-d /a:d "%_path_search%\*"') do (
            set "%_var%=%_path_search%\%%A"
            goto:$GetPathDone
        )

        :$GetPathDone
            set "_out_var=!%_var%!"
            set "_out_var_dir=!%_var_dir%!"
            echo [%_var%] "!_out_var!"
    endlocal & (
        set "%_var%=%_out_var%"
        exit /b 0
    )

    :$MainSetPaths
    call :GetPath "msvc_root"                      "C:\Program Files\Microsoft Visual Studio\2022"
    call :GetPath "winsdk_include_path"            "C:\Program Files (x86)\Windows Kits\10\Include"
    call :GetPath "winsdk_lib_path"                "C:\Program Files (x86)\Windows Kits\10\Lib"
    call :GetPath "mingw_winlibs_llvm"             "%USERPROFILE%\scoop\apps\mingw-winlibs-llvm"
    call :GetPath "mingw_winlibs_llvm_ucrt"        "%USERPROFILE%\scoop\apps\mingw-winlibs-llvm-ucrt"
    call :GetPath "mingw_winlibs_llvm_ucrt_mcf"    "%USERPROFILE%\scoop\apps\mingw-winlibs-llvm-ucrt-mcf"

    call :GetPath "winsdk_bin_path"                "C:\Program Files (x86)\Windows Kits\10\Bin"
    if exist "!winsdk_bin_path!\x64"                set "path=!winsdk_bin_path!\x64;%path%"

    ::
    :: If needed, you can run `call "!_vcvarsall!" x64` to further setup the development environment. This
    :: will be much slower, though, so not enabled by default.
    ::
    call :GetPath "msvc_path" "!msvc_root!\VC\Tools\MSVC"
    set "_vcvarsall=!msvc_root!\VC\Auxiliary\Build\vcvarsall.bat"

    set "_inc=/I"!msvc_path!\include" /I"!winsdk_include_path!\ucrt" /I"!winsdk_include_path!\um" /I"!winsdk_include_path!\shared" "
    set "_lib=/LIBPATH:"!msvc_path!\lib\x64" /LIBPATH:"!winsdk_lib_path!\um\x64" /LIBPATH:"!winsdk_lib_path!\ucrt\x64" /LIBPATH:"!winsdk_lib_path!\shared" "

    call :Find win_rc_exe "rc.exe"
    call :Find llvm_rc_exe "llvm-rc.exe"

    if "!msvc!"=="1"    set "rc_exe=!win_rc_exe!"
    if "!clang!"=="1"   set "rc_exe=!llvm_rc_exe!"

    call :Find                          cl_exe          "cl.exe"
    call :Find                          clang_cl_exe    "clang.exe"
    call :Find                          lld_exe         "lld.exe"

    if "!clang!"=="1"                   set "path=%msvc_root%\VC\Tools\Llvm\x64\bin;%path%"

    :: --- Compile/Link Line Definitions ------------------------------------------
    set      cl_common=/I"!_root!\src" /I"!_root!\local" !_inc! /nologo /FC /Z7
    set   clang_common=-I"!_root!\src" -I"!_root!\local" -gcodeview -fdiagnostics-absolute-paths -Wall -Wno-unknown-warning-option -Wno-missing-braces -Wno-unused-function -Wno-writable-strings -Wno-unused-value -Wno-unused-variable -Wno-unused-local-typedef -Wno-deprecated-register -Wno-deprecated-declarations -Wno-unused-but-set-variable -Wno-single-bit-bitfield-constant-conversion -Xclang -flto-visibility-public-std -D_USE_MATH_DEFINES -Dstrdup=_strdup -Dgnu_printf=printf

    set       cl_debug=!cl_exe! /Od !cl_common! !auto_compile_flags!
    set     cl_release=!cl_exe! /O2 /DNDEBUG !cl_common! !auto_compile_flags!

    set    clang_debug=!clang_cl_exe! -g -O0 !clang_common! !auto_compile_flags!
    set  clang_release=!clang_cl_exe! -g -O2 -DNDEBUG !clang_common! !auto_compile_flags!

    set        cl_link=/link /MANIFEST:EMBED /INCREMENTAL:NO !_lib! /natvis:"!_root!\src\natvis\base.natvis" "!_build!\logo.res"
    set     clang_link=-fuse-ld=lld -Xlinker /MANIFEST:EMBED -Xlinker /natvis:"!_root!\src\natvis\base.natvis" "!_build!\logo.res"

    set         "cl_out=/out:"
    set      "clang_out=-o"
    set         "cl_obj=/Fo"
    set      "clang_obj=/Fo"

    :: --- Per-Build Settings -----------------------------------------------------
    set "gfx=-DOS_FEATURE_GRAPHICAL=1"
    set "net=-DOS_FEATURE_SOCKET=1"
    set "link_dll=-DLL"
    if "!msvc!"=="1"  set "only_compile=/c"
    if "!clang!"=="1" set "only_compile=-c"
    if "!msvc!"=="1"  set "EHsc=/EHsc"
    if "!clang!"=="1" set "EHsc="

    :: --- Choose Compile/Link Lines ----------------------------------------------
    if "!msvc!"=="1"      set "compile_debug=!cl_debug!"
    if "!msvc!"=="1"      set "compile_release=!cl_release!"
    if "!msvc!"=="1"      set "compile_link=!cl_link!"
    if "!msvc!"=="1"      set "out=!cl_out!"
    if "!msvc!"=="1"      set "obj=!cl_obj!"

    if "!clang!"=="1"     set "compile_debug=!clang_debug!"
    if "!clang!"=="1"     set "compile_release=!clang_release!"
    if "!clang!"=="1"     set "compile_link=!clang_link!"
    if "!clang!"=="1"     set "out=!clang_out!"
    if "!clang!"=="1"     set "obj=!clang_obj!"

    if "!debug!"=="1"     set "compile=!compile_debug!"
    if "!release!"=="1"   set "compile=!compile_release!"

    :: --- Prep Directories -------------------------------------------------------
    if not exist "!_build!" mkdir "!_build!"
    if not exist "!_root!\local" mkdir "!_root!\local"

    :: --- Produce Logo Icon File -------------------------------------------------
    cd /d "!_build!"
    call :Command !rc_exe! /nologo !obj!"!_build!\logo.res" "!_root!\data\logo.rc"
    if errorlevel 1 goto:$BuildError

    :: --- Get Current Git Commit Id ----------------------------------------------
    for /f  %%i in ('call "C:\Program Files\Git\bin\git.exe" describe --always --dirty') do (
      set "compile=!compile! -DRADDBG_GIT="%%i""
    )

    :: --- Build & Run Metaprogram ------------------------------------------------
    if "!no_meta!"=="1" (
      echo [skipped metagen]
      goto:$BuildSkipMetagen
    )
    cd /d "!_build!"
    call :Command !compile_debug! "!_root!\src\metagen\metagen_main.c" !compile_link! !out!"!_build!\metagen.exe"
    echo [metagen][!errorlevel!] Done.
    if errorlevel 1 goto:$BuildError
    :$BuildSkipMetagen

    :: --- Build Everything (@build_targets) --------------------------------------
    :$StartBuild
    if "!raddbg!"=="1"                      call !compile! !gfx!                    "!_root!\src\raddbg\raddbg_main.cpp"                                !compile_link! !out!"!_build!\raddbg.exe"
    if errorlevel 1 goto:$BuildError

    if "!raddbgi_from_pdb!"=="1"            call !compile!                          "!_root!\src\raddbgi_from_pdb\raddbgi_from_pdb_main.c"             !compile_link! !out!"!_build!\raddbgi_from_pdb.exe"
    if errorlevel 1 goto:$BuildError

    if "!raddbgi_from_dwarf!"=="1"          call !compile!                          "!_root!\src\raddbgi_from_dwarf\raddbgi_from_dwarf.c"              !compile_link! !out!"!_build!\raddbgi_from_dwarf.exe"
    if errorlevel 1 goto:$BuildError

    if "!raddbgi_dump!"=="1"                call !compile!                          "!_root!\src\raddbgi_dump\raddbgi_dump_main.c"                             !compile_link! !out!"!_build!\raddbgi_dump.exe"
    if errorlevel 1 goto:$BuildError

    if "!raddbgi_breakpad_from_pdb!"=="1"   call !compile!                          "!_root!\src\raddbgi_breakpad_from_pdb\raddbgi_breakpad_from_pdb_main.c"                             !compile_link! !out!"!_build!\raddbgi_breakpad_from_pdb.exe"
    if errorlevel 1 goto:$BuildError

    if "!ryan_scratch!"=="1"                call !compile!                          "!_root!\src\scratch\ryan_scratch.c"                                !compile_link! !out!"!_build!\ryan_scratch.exe"
    if errorlevel 1 goto:$BuildError

    if "!cpp_tests!"=="1"                   call !compile!                          "!_root!\src\scratch\i_hate_c_plus_plus.cpp"                        !compile_link! !out!"!_build!\cpp_tests.exe"
    if errorlevel 1 goto:$BuildError

    if "!look_at_raddbg!"=="1"              call !compile!                          "!_root!\src\scratch\look_at_raddbg.c"                              !compile_link! !out!"!_build!\look_at_raddbg.exe"
    if errorlevel 1 goto:$BuildError

    if "!mule_main!"=="1"                   call del                                "!_build!\vc*.pdb" "!_build!\mule*.pdb" > nul 2>&1
    if "!mule_main!"=="1"                   call :Command call !compile_release! !only_compile!   "!_root!\src\mule\mule_inline.cpp" !out!"!_build!\mule_inline.obj"
    if "!mule_main!"=="1"                   call :Command call !compile_release! !only_compile!   "!_root!\src\mule\mule_o2.cpp" !out!"!_build!\mule_o2.obj"
    if "!mule_main!"=="1"                   call :Command call !compile_debug!   !EHsc!           "!_root!\src\mule\mule_main.cpp" "!_root!\src\mule\mule_c.c" "!_build!\mule_inline.obj" "!_build!\mule_o2.obj" !compile_link!    !out!"!_build!\mule_main.exe"
    if errorlevel 1 goto:$BuildError

    if "!mule_module!"=="1"                 call :Command !compile!                          "!_root!\src\mule\mule_module.cpp"                                  !compile_link! !link_dll! !out!"!_build!\mule_module.dll"
    if errorlevel 1 goto:$BuildError

    if "!mule_hotload!"=="1"                call :Command !compile!                          "!_root!\src\mule\mule_hotload_main.c" !compile_link! !out!"!_build!\mule_hotload.exe"
    if "!mule_hotload!"=="1"                call :Command !compile!                          "!_root!\src\mule\mule_hotload_module_main.c" !compile_link! !link_dll! !out!"!_build!\mule_hotload_module.dll"
    if errorlevel 1 goto:$BuildError

    echo ##[info]Project build complete.
    goto:$BuildDone

    :$BuildError
        if "!look_at_raddbg!"=="1" goto:$BuildErrorIgnore
        if "!ryan_scratch!"=="1" goto:$BuildErrorIgnore

        if not "!clang!"=="1" goto:$BuildSkipClangOverrides
            if "!mule_module!"=="1" goto:$BuildErrorIgnore
            if "!mule_hotload!"=="1" goto:$BuildErrorIgnore
        :$BuildSkipClangOverrides

        set _error=%errorlevel%
        echo ##[error]Failed to build project. Error code: !_error!
        goto:$BuildDone

    :$BuildErrorIgnore
        set "_error=0"
        echo ##[warning]Ignored known build error for current project.
        goto:$BuildDone

    :$BuildDone
        echo ##[endgroup]
        :: --- Unset ------------------------------------------------------------------
        for %%a in (!_variables!) do set "%%a=0"
        call :Clear
endlocal & exit /b %_error%

:$Main
    echo ##[group]%0 %~1 %~2 %~3 %~4 %~5 %~6 %~7 %~8 %~9
    echo ##[command]%0 %~1 %~2 %~3 %~4 %~5 %~6 %~7 %~8 %~9

    :$MainBuild
        if "%~1"=="all" goto:$MainBuildAll
        call :Build %*
        if errorlevel 1 goto:$MainError
        goto:$MainDone

    :$MainBuildAll
        for %%a in ("raddbg" "raddbgi_from_pdb" "raddbgi_from_dwarf" "raddbgi_dump" "raddbgi_breakpad_from_pdb" "ryan_scratch" "cpp_tests" "look_at_raddbg" "mule_main" "mule_module" "mule_hotload") do (
            call :Build "%%a" %*
            if errorlevel 1 goto:$MainError
        )
        echo ##[info]Built all projects successfully.
        goto:$MainDone

    :$MainError
        echo ##[error]Failed to build projects. Error code: %errorlevel%
        goto:$MainDone

    :$MainDone
goto:eof
