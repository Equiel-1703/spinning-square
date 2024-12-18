@echo off

set bin-folder=bin
set obj-folder=objs
set src-folder=src
set headers-folder=headers
set program-name=spinning-square.exe

cl.exe /EHsc /utf-8 /Fo: "%obj-folder%\\" /Fe: "%bin-folder%\\" %src-folder%\\*.cpp /I "%headers-folder%" /link /out:%bin-folder%\\%program-name%

if %ERRORLEVEL% NEQ 0 (
	exit /b 1
) else (
	%bin-folder%\\%program-name%
)