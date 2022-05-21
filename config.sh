#generate the library from network using conan
conan install . --build missing 

#To Generate MakeFiles 
premake5 gmake

#go to the build directory 
cd build
make

