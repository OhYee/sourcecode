@echo off

cls

cd Blog

set path=%path%;%cd%\..\..\Support\git\bin\;%cd%\..\..\Support\npm\bin\;%cd%\..\..\Support\nodejs\;%cd%\..\..\Support\npm\;%cd%\..\..\Support\git\

REM start git-bash "%cd%\..\..\Support\script\generateAndDelpoy.sh"

hexo %1 %2 %3

cd ..\