@echo off

set bin-folder=bin
set obj-folder=objs
set src-folder=src
set program-name=spinning-square.exe

cl.exe /EHsc /Fo: "%obj-folder%\\" /Fe: "%bin-folder%\\" %src-folder%\\*.cpp /link /out:%bin-folder%\\%program-name%

if %errorlevel%==0 (
	cls
	%bin-folder%\\%program-name%
)