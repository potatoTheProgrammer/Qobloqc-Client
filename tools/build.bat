:: yeah im using a .bat file to compile, cry about it
:: and yeah im using mingw cry about it

@echo off
cd ..

echo Press any key to compile!
pause > nul

echo.
echo Compiling...
g++ -std=c++17 -o build/Qobloqc.exe -I headers -I data/generated source/main.cpp source/display.cpp misc/icon.res -static-libgcc -static-libstdc++
echo.

echo Done! Press any key to close the builder.
pause > nul