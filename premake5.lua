include("conanbuildinfo.premake.lua")

workspace ("OpenGLTestApp")
    language "C++"
    location "build"
    cppdialect "C++11"
    toolset("clang")
    -- conan setup
    conan_basic_setup()
    configurations {"Debug", "Release"}



------ Program
project ("OpenGLTestApp")
    targetdir "bin"
    kind "ConsoleApp"
    files {
        "**.cpp",
        "**.h"
    }
    includedirs {
        "include"
    }
    linkoptions { 
        conan_exelinkflags
    }
    filter { "system:windows" }
		links {
            "opengl32.lib" 
        }

	filter { "system:not windows" }
		links { 
            "GL"
        }

    filter {"configurations:Debug"}
        defines {"DEBUG"}
        optimize "Off"
        symbols "On"

    filter {"configurations:Release"}
        defines {"RELEASE"}
        optimize "Speed"
        symbols "Off"

