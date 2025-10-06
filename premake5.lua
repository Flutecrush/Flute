workspace "FluteEngine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "FluteEngine"
	location "FluteEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	buildoptions { "/utf-8" }

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.22621.0"

		defines
		{
			"FL_PLATFORM_WINDOWS",
			"FL_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPYFILE} ..\\bin\\" .. outputdir .. "\\FluteEngine\\FluteEngine.dll ..\\bin\\" .. outputdir .. "\\Sandbox\\ > nul")
		}

	filter "configurations:Debug"
		defines "FL_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "FL_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "FL_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	buildoptions { "/utf-8" }

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"FluteEngine/vendor/spdlog/include",
		"FluteEngine/src"
	}
	
	links
	{
		"FluteEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.22621.0"

		defines
		{
			"FL_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "FL_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "FL_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "FL_DIST"
		optimize "On"