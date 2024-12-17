workspace "Soma"
    architecture "x64"

    configurations {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Soma"
    location "Soma"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    includedirs {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include"
    }

    buildoptions{"/utf-8"}

    filter "system:windows" 
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines {
            "SOMA_PLATFORM_WINDOWS",
            "SOMA_BUILD_DLL"
        }

        postbuildcommands {
            ("{COPYFILE} %[./bin/" .. outputdir .. "/%{prj.name}/%{prj.name}.dll] %[./bin/" .. outputdir .. "/Sandbox/%{prj.name}.dll]")
        }

    filter "configurations:Debug"
        defines "SOMA_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "SOMA_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "SOMA_DIST"
        optimize "On"



project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    includedirs {
        "Soma/vendor/spdlog/include",
        "Soma/src"
    }

    links {
        "Soma"
    }

    buildoptions{"/utf-8"}

    filter "system:windows" 
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines {
            "SOMA_PLATFORM_WINDOWS",
        }

    filter "configurations:Debug"
        defines "SOMA_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "SOMA_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "SOMA_DIST"
        optimize "On"