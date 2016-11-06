@Echo off

set path=%path%;%cd%\..\Support\MinGW\bin\

g++ -g -Wall Temp\Temp.cpp -o Temp\Temp.exe

echo =========

if exist Temp\Temp.exe Temp\Temp.exe

echo =========
pause


