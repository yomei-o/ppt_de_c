echo off
del testmain.exe > nul
tcc testmain.c
testmain
del libtcc.dll
del tcc.exe
del lib\libtcc1.a
del include\_mingw.h
del include\float.h
del include\limits.h
del include\malloc.h
del include\math.h
del include\stdarg.h
del include\stddef.h
del include\stdio.h
del include\stdlib.h
del include\string.h
del include\vadefs.h
rmdir include
rmdir lib
pause


