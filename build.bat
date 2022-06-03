@echo off

REM open the visual studio msbuild script
call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\Tools\VsMSBuildCmd.bat"

REM build the solution 
msbuild OpenGLTestApp.sln