:: yeah im using a .bat file to compile, cry about it
:: and yeah im using mingw cry about it

@echo off
cd ..

echo Press any key to compile!
pause > nul

echo.
echo Compiling...
g++ -o build/Qobloqc.exe source/main.cpp
echo.

echo Done! Press any key to close the builder.
pause > nul