#go to vendor file for generating library premake file
cd vendor

#generate the library from network using conan
conan install . --build missing 

#going back to main directory 
cd  ..

#To Generate MakeFiles 
premake5 gmake