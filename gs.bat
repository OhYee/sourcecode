@echo off

cls

cd blog

set path=%path%;%cd%\..\..\Support\git\bin\;%cd%\..\..\Support\npm\bin\;%cd%\..\..\Support\nodejs\;%cd%\..\..\Support\npm\;%cd%\..\..\Support\git\

start git-bash "%cd%\..\..\Support\script\generateAndServer.sh"

