workspace ("OpenGLTestApp")
    language "C++"
    location "build"
    warnings "Extra"
    cppdialect "C++17"
    -- platforms {"Static", "Shared"}
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
    files {"src/main.cpp"}
    includedirs {"include"}
    -- links {"library"}

