@echo off
gcc test.c -o ./output/test.exe
cd output
test.exe
cd ..
