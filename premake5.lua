workspace "Shade"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }


outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
project "Shade"
    location "Shade"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir    ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "sdpch.h"
    pchsource "Shade/src/sdpch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/vendor/spdlog/include",
        "%{prj.name}/src"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "SD_PLATFORM_WINDOWS",
            "SD_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

        flags { "MultiProcessorCompile" }
        buildoptions { "/utf-8" }


    filter "configurations:Debug"
        defines "SD_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "SD_RELEASE"
        optimize "On"
    
    filter "configurations:Dist"
        defines "SD_DIST"
        optimize "On"


project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir    ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "Shade/vendor/spdlog/include",
        "Shade/src"
    }

    links
    {
        "Shade"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "SD_PLATFORM_WINDOWS"
        }

        flags { "MultiProcessorCompile" }
        buildoptions { "/utf-8" }

        
    filter "configurations:Debug"
        defines "SD_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "SD_RELEASE"
        optimize "On"
    
    filter "configurations:Dist"
        defines "SD_DIST"
        optimize "On"