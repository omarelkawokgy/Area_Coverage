@echo off
set COMPILER=gcc
				set COMPFLAGS=-c -fexceptions -fno-omit-frame-pointer -m64 -DMATLAB_MEX_FILE  -DMATLAB_MEX_FILE  
				set OPTIMFLAGS=-O -DNDEBUG 
				set DEBUGFLAGS=-g 
				set LINKER=gcc 
				set LINKFLAGS=-m64 -Wl,--no-undefined -shared -L"C:\TOOLS\MATLAB\extern\lib\win64\mingw64" -llibmx -llibmex -llibmat -lm -llibmwlapack -llibmwblas -Wl,"C:\TOOLS\MATLAB/extern/lib/win64/mingw64/mexFunction.def" 
				set LINKDEBUGFLAGS=-g
				set NAME_OUTPUT=-o "%OUTDIR%%MEX_NAME%%MEX_EXT%"
set PATH=C:\mingw-w64\x86_64-5.3.0-posix-seh-rt_v4-rev0\mingw64\bin;C:\TOOLS\MATLAB\extern\include\win64;C:\TOOLS\MATLAB\extern\include;C:\TOOLS\MATLAB\simulink\include;C:\TOOLS\MATLAB\lib\win64;%MATLAB_BIN%;%PATH%
set INCLUDE=C:\mingw-w64\x86_64-5.3.0-posix-seh-rt_v4-rev0\mingw64\include;;%INCLUDE%
set LIB=C:\mingw-w64\x86_64-5.3.0-posix-seh-rt_v4-rev0\mingw64\lib;;%LIB%
set LIBPATH=C:\TOOLS\MATLAB\extern\lib\win64;%LIBPATH%

gmake SHELL="cmd" -f RobotControl_sfun.gmk
