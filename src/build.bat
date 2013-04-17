del out\bin2vb.exe
del out\result.txt
rmdir out

tcc bin2vb.c -Iinclude -Llib
mkdir out

copy bin2vb.exe out\bin2vb.exe
del bin2vb.exe
copy sub.txt out\result.txt
out\bin2vb tcc.exe >>  out\result.txt
out\bin2vb libtcc.dll >>  out\result.txt
out\bin2vb docompile.bat >>  out\result.txt
out\bin2vb lib\libtcc1.a >>  out\result.txt
out\bin2vb include\_mingw.h >>  out\result.txt
out\bin2vb include\limits.h >>  out\result.txt
out\bin2vb include\malloc.h >>  out\result.txt
out\bin2vb include\stdarg.h >>  out\result.txt
out\bin2vb include\stddef.h >>  out\result.txt
out\bin2vb include\stdio.h >>  out\result.txt
out\bin2vb include\stdlib.h >>  out\result.txt
out\bin2vb include\string.h >>  out\result.txt
out\bin2vb include\vadefs.h >>  out\result.txt
out\bin2vb include\float.h >>  out\result.txt
out\bin2vb include\math.h >>  out\result.txt

