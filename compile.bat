@Echo off

set path=%path%;%cd%\..\Support\MinGW\bin\;%cd%\..\Support\MinGW\lib\;%cd%\..\Support\MinGW\include\

if exist %1.exe del %1.exe 

g++ -g -Wall %1 -o %1.exe

if exist %1.exe  start run.bat %1 /B

echo Finished

