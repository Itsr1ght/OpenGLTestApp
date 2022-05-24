include("conanbuildinfo.premake.lua")

workspace ("OpenGLTestApp")
    language "C++"
    location "build"
    warnings "Extra"
    cppdialect "C++17"
    toolset("clang")
    -- conan setup
    conan_basic_setup()
    configurations {"Debug", "Release"}

    filter {"configurations:Debug"}
        defines {"DEBUG"}
        optimize "Off"
        symbols "On"

    filter {"configurations:Release"}
        defines {"RELEASE"}
        optimize "Speed"
        symbols "Off"

------ Program
project ("OpenGLTestApp")
    targetdir "bin"
    kind "ConsoleApp"
    files {
        "src/**.cpp"
    }
    includedirs {
        "include"
    }
    linkoptions { 
        conan_exelinkflags
    }
    filter { "system:windows" }
		links { "OpenGL32" }
	filter { "system:linux" }
		links { "GL" }

