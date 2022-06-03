@echo off

REM generate the library from network using conan
conan install . --build missing

REM To Generate Windows Solution
premake5 vs2019