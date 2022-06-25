# OpenGLTestApp
just a simple repos for creating and test opengl code for me :)


## Build Instruction 

### <b>Windows</b>

Download Conan client using 
```
pip install conan
```
or download from their website <a href="https://conan.io/downloads">conan</a>

also download the premake binary from the <a href="https://premake.github.io/download">premake website</a>
add it to the project directory or add it as a environment variable in windows

and call ``` config.bat ```
for generate the basic solution for windows <div>
and call ``` build.bat ```
for build the application (if you install the visual studio)

### <b>Linux</b>

#### Arch

install the following
```
sudo pacman -S premake5

yay -S conan
```
and call ``` config.sh ```
for generate MakeFiles for the program <div>
and call ``` build.bat ```
for build the application
