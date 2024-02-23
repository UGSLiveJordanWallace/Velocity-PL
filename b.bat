@ECHO OFF

gcc main.c debug.c chunk.c memory.c value.c -o build
build.exe
