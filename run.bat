@echo off & goto:$Main

:$Main
setlocal
    call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat" x64
    call "%~dp0build.old.bat" raddbg msvc debug             || exit /b 1
    call "%~dp0build.old.bat" raddbg_from_pdb msvc debug    || exit /b 1
    call "%~dp0build.old.bat" raddbg_from_dwarf msvc debug  || exit /b 1
    call "%~dp0build.old.bat" raddbg clang debug            || exit /b 1
    call "%~dp0build.old.bat" raddbg_from_pdb clang debug   || exit /b 1
    call "%~dp0build.old.bat" raddbg_from_dwarf clang debug || exit /b 1
endlocal & exit /b %errorlevel%
