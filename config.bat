@echo off

REM generate the library from network using conan
conan install . --build missing

REM To Generate Windows Solution
premake5 vs2019

REM call Solution File
cd build

REM open the visual studio msbuild script
call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\Tools\VsMSBuildCmd.bat"

REM build the solution 
msbuild OpenGLTestApp.sln
