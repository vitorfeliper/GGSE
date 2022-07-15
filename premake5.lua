workspace "GGSE"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "GGSE"
	location "GGSE"
	kind "SharedLib"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "ggpch.h"
	pchsource "GGSE/src/ggpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"GGE_PLATFORM_WINDOWS",
			"GGE_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/NenequinhoAdventure_Sandbox")
		}

	filter "configurations:Debug"
		defines "GGSE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "GGSE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "GGSE_DIST"
		optimize "On"

project "NenequinhoAdventure_Sandbox"
	location "NenequinhoAdventure_Sandbox"
	kind "ConsoleApp"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"GGSE/vendor/spdlog/include",
		"GGSE/src"
	}

	links
	{
		"GGSE"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"GGE_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "GGSE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "GGSE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "GGSE_DIST"
		optimize "On"