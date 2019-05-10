@echo off 
setlocal enableDelayedExpansion 

cd src
for /F %%d in ('dir /B/S *.java') do (
  javah -d ../bin/headers/ %%d
)