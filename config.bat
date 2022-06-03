@echo off

REM go to vendor dir for generating the library premake file
cd vendor

REM generate the library from network using conan
conan install . --build missing

cd ..

REM To Generate Windows Solution
premake5 vs2019