@echo off

cls

cd Blog

set path=%path%;%cd%\..\..\Support\git\bin\;%cd%\..\..\Support\npm\bin\;%cd%\..\..\Support\nodejs\;%cd%\..\..\Support\npm\;%cd%\..\..\Support\git\

hexo %1 %2 %3

cd ..\