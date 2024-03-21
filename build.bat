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

:Command
::-------------------------------------------------
:: Run a command and echo that command to console
::-------------------------------------------------
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
        echo ##[cmd] !_cmd!
        call !_cmd!
    endlocal & exit /b %errorlevel%

    :$CommandRun
    call :CommandVar "_command"
endlocal & exit /b %errorlevel%

:Find
::-------------------------------------------------
:: Look for requested executable and set the provided variable to the full path
:: of that executable if found.
::-------------------------------------------------
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

:Build
setlocal EnableDelayedExpansion
    set "_var=%~1"
    shift
    set "_var_val=!%_var%!"
    if not "!_var_val!"=="1" goto:$BuildDone
    call :Command %1 %2 %3 %4 %5 %6 %7 %8 %9
    :$BuildDone
endlocal & exit /b %errorlevel%

::
::-------------------------------
:: Main
::-------------------------------
:$Main
setlocal EnableDelayedExpansion
    set "_error=0"
    set "_root=%~dp0"
    if "!_root:~-1!"=="\"                               set "_root=!_root:~0,-1!"

    :: --- Unpack Arguments -------------------------------------------------------
    for %%a in (%*) do                                  set "%%a=1"
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

    set "_build=!_root!\build\!_config!"
    if not exist "!_root!\build"                        mkdir "!_root!\build"
    if not exist "!_build!"                             mkdir "!_build!"

    :: --- Unpack Command Line Build Arguments ------------------------------------
    set "auto_compile_flags="
    if "%telemetry%"=="1" set "auto_compile_flags=!auto_compile_flags! -DPROFILE_TELEMETRY=1" && echo [telemetry profiling enabled]
    if "%asan%"=="1"      set "auto_compile_flags=!auto_compile_flags! -fsanitize=address" && echo [asan enabled]

    set "msvc_root=C:\Program Files\Microsoft Visual Studio\2022\Enterprise"
    if not exist "!msvc_root!" set "msvc_root=C:\Program Files\Microsoft Visual Studio\2022\Professional"
    if not exist "!msvc_root!" set "msvc_root=C:\Program Files\Microsoft Visual Studio\2022\Community"

    set "msvc_path="
    for /D %%x in ("!msvc_root!\VC\Tools\MSVC\*") do if not defined msvc_path set "msvc_path=%%x"
    echo [msvc_path] !msvc_path!

    set "_vcvarsall=!msvc_root!\VC\Auxiliary\Build\vcvarsall.bat"
    ::
    :: If needed, you can run `call "!_vcvarsall!" x64` to further setup the development environment. This
    :: will be much slower, though, so not enabled by default.
    ::

    set "winsdk_bin_path="
    for /D %%y in ("C:\Program Files (x86)\Windows Kits\10\Bin\*") do if not defined winsdk_bin_path set "winsdk_bin_path=%%y"
    echo [winsdk_bin_path] !winsdk_bin_path!
    set "path=!winsdk_bin_path!\x64;%path%"

    set "winsdk_include_path="
    for /D %%y in ("C:\Program Files (x86)\Windows Kits\10\Include\*") do if not defined winsdk_include_path set "winsdk_include_path=%%y"
    echo [winsdk_include_path] !winsdk_include_path!

    set "winsdk_lib_path="
    for /D %%z in ("C:\Program Files (x86)\Windows Kits\10\Lib\*") do if not defined winsdk_lib_path set "winsdk_lib_path=%%z"
    echo [winsdk_lib_path] !winsdk_lib_path!

    set "mingw_winlibs_llvm="
    for /D %%z in ("%USERPROFILE%\scoop\apps\mingw-winlibs-llvm\*") do if not defined mingw_winlibs_llvm set "mingw_winlibs_llvm=%%z"
    echo [mingw_winlibs_llvm] !mingw_winlibs_llvm!

    set "mingw_winlibs_llvm_ucrt="
    for /D %%z in ("%USERPROFILE%\scoop\apps\mingw-winlibs-llvm-ucrt\*") do if not defined mingw_winlibs_llvm_ucrt set "mingw_winlibs_llvm_ucrt=%%z"
    echo [mingw_winlibs_llvm_ucrt] !mingw_winlibs_llvm_ucrt!

    set "mingw_winlibs_llvm_ucrt_mcf="
    for /D %%z in ("%USERPROFILE%\scoop\apps\mingw-winlibs-llvm-ucrt-mcf\*") do if not defined mingw_winlibs_llvm_ucrt_mcf set "mingw_winlibs_llvm_ucrt_mcf=%%z"
    echo [mingw_winlibs_llvm] !mingw_winlibs_llvm!

    set "_inc=/I"!msvc_path!\include" /I"!winsdk_include_path!\ucrt" /I"!winsdk_include_path!\um" /I"!winsdk_include_path!\shared" "
    set "_lib=/LIBPATH:"!msvc_path!\lib\x64" /LIBPATH:"!winsdk_lib_path!\um\x64" /LIBPATH:"!winsdk_lib_path!\ucrt\x64" /LIBPATH:"!winsdk_lib_path!\shared" "

    call :Find                          cl_exe          "cl.exe"
    call :Find                          clang_cl_exe    "clang.exe"

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
    if "%msvc%"=="1"  set "only_compile=/c"
    if "%clang%"=="1" set "only_compile=-c"
    if "%msvc%"=="1"  set "EHsc=/EHsc"
    if "%clang%"=="1" set "EHsc="
    if "%msvc%"=="1"  call :Find rc_exe "rc.exe"
    if "%clang%"=="1" call :Find rc_exe "llvm-rc.exe"

    :: --- Choose Compile/Link Lines ----------------------------------------------
    if "%msvc%"=="1"      set "compile_debug=!cl_debug!"
    if "%msvc%"=="1"      set "compile_release=!cl_release!"
    if "%msvc%"=="1"      set "compile_link=!cl_link!"
    if "%msvc%"=="1"      set "out=!cl_out!"

    if "%clang%"=="1"     set "compile_debug=!clang_debug!"
    if "%clang%"=="1"     set "compile_release=!clang_release!"
    if "%clang%"=="1"     set "compile_link=!clang_link!"
    if "%clang%"=="1"     set "out=!clang_out!"

    if "%debug%"=="1"     set "compile=!compile_debug!"
    if "%release%"=="1"   set "compile=!compile_release!"

    :: --- Prep Directories -------------------------------------------------------
    if not exist "!_build!" mkdir "!_build!"
    if not exist "!_root!\local" mkdir "!_root!\local"

    :: --- Produce Logo Icon File -------------------------------------------------
    cd /d "!_build!"
    call :Command !rc_exe! /nologo %cl_obj%"!_build!\logo.res" "!_root!\data\logo.rc"
    if errorlevel 1 goto:$MainError

    :: --- Get Current Git Commit Id ----------------------------------------------
    for /f %%i in ('call "C:\Program Files\Git\bin\git.exe" describe --always --dirty') do (
      set "compile=!compile! -DRADDBG_GIT="%%i""
    )

    :: --- Build & Run Metaprogram ------------------------------------------------
    if "%no_meta%"=="1" (
      echo [skipped metagen]
      goto:$MainSkipMetagen
    )
    cd /d "!_build!"
    call :Command !compile_debug! "!_root!\src\metagen\metagen_main.c" !compile_link! !out!"!_build!\metagen.exe"
    echo [metagen][!errorlevel!] Done.
    if errorlevel 1 goto:$MainError
    :$MainSkipMetagen

    :: --- Build Everything (@build_targets) --------------------------------------
    :$StartBuild
    if "%raddbg%"=="1"                  call !compile! %gfx%                    "!_root!\src\raddbg\raddbg_main.cpp"                                !compile_link! !out!"!_build!\raddbg.exe"
    if errorlevel 1 goto:$MainError

    if "%raddbgi_from_pdb%"=="1"        call !compile!                          "!_root!\src\raddbgi_from_pdb\raddbgi_from_pdb_main.c"             !compile_link! !out!"!_build!\raddbgi_from_pdb.exe"
    if errorlevel 1 goto:$MainError

    if "%raddbgi_from_dwarf%"=="1"      call !compile!                          "!_root!\src\raddbgi_from_dwarf\raddbgi_from_dwarf.c"              !compile_link! !out!"!_build!\raddbgi_from_dwarf.exe"
    if errorlevel 1 goto:$MainError

    if "%raddbgi_dump%"=="1"            call !compile!                          "!_root!\src\raddbgi_dump\raddbgi_dump_main.c"                             !compile_link! !out!"!_build!\raddbgi_dump.exe"
    if errorlevel 1 goto:$MainError

    if "%raddbgi_breakpad_from_pdb%"=="1" call !compile!                          "!_root!\src\raddbgi_breakpad_from_pdb\raddbgi_breakpad_from_pdb_main.c"                             !compile_link! !out!"!_build!\raddbgi_breakpad_from_pdb.exe"
    if errorlevel 1 goto:$MainError

    if "%ryan_scratch%"=="1"            call !compile!                          "!_root!\src\scratch\ryan_scratch.c"                                !compile_link! !out!"!_build!\ryan_scratch.exe"
    if errorlevel 1 goto:$MainError

    if "%cpp_tests%"=="1"               call !compile!                          "!_root!\src\scratch\i_hate_c_plus_plus.cpp"                        !compile_link! !out!"!_build!\cpp_tests.exe"
    if errorlevel 1 goto:$MainError

    if "%look_at_raddbg%"=="1"          call !compile!                          "!_root!\src\scratch\look_at_raddbg.c"                              !compile_link! !out!"!_build!\look_at_raddbg.exe"
    if errorlevel 1 goto:$MainError

    if "%mule_main%"=="1"               call del                                "!_build!\vc*.pdb" "!_build!\mule*.pdb"
    if "%mule_main%"=="1"               call !compile_release! %only_compile%   "!_root!\src\mule\mule_inline.cpp"
    if "%mule_main%"=="1"               call !compile_release! %only_compile%   "!_root!\src\mule\mule_o2.cpp"
    if "%mule_main%"=="1"               call !compile_debug!   %EHsc%           "!_root!\src\mule\mule_main.cpp" "!_root!\src\mule\mule_c.c" "!_build!\mule_inline.obj" "!_build!\mule_o2.obj" !compile_link!    !out!"!_build!\mule_main.exe"
    if errorlevel 1 goto:$MainError

    if "%mule_module%"=="1"             call !compile!                          "!_root!\src\mule\mule_module.cpp"                                  !compile_link! %link_dll% "!out!mule_module.dll"
    if errorlevel 1 goto:$MainError

    if "%mule_hotload%"=="1"            call !compile!                          "!_root!\src\mule\mule_hotload_main.c" !compile_link! "!out!mule_hotload.exe"
    if "%mule_hotload%"=="1"            call !compile!                          "!_root!\src\mule\mule_hotload_module_main.c" !compile_link! %link_dll% !out!"!_build!\mule_hotload_module.dll"
    if errorlevel 1 goto:$MainError

    :: --- Unset ------------------------------------------------------------------
    for %%a in (%*) do set "%%a=0"
    set raddbg=
    set compile=
    set compile_link=
    set out=
    set msvc=
    set debug=
    echo RAD Debugger build complete.
    goto:$MainDone

    :$MainError
    set _error=%errorlevel%
    echo [ERROR][!_error!] Failed to build project.
    goto:$MainDone

    :$MainDone
endlocal & exit /b %_error%
