project "DaisyEngine"
   kind "ConsoleApp"
   language "C++"
   cppdialect "C++20"
   targetdir "Binaries/%{cfg.buildcfg}"
   staticruntime "off"

   files { "src/**.h", "src/**.cpp", "vendor/stb_image/**.h", "vendor/stb_image/**.cpp", "vendor/ImGui/**.h", "vendor/ImGui/**.cpp" }

   includedirs
   {
	
	"src",
	"GLFW",
	"glew",
	"vendor/glm",
	"vendor/stb_image",
	"vendor/ImGui"

   }

   links
   {
	"glew/lib/glew32.lib",
	"glew/lib/glew32s.lib",
	"GLFW/glfw3.lib",
	"GLFW/glfw3_mt.lib",
	"GLFW/glfw3dll.lib",
	"opengl32.lib"
   }

   targetdir ("../Binaries/" .. OutputDir .. "/%{prj.name}")
   objdir ("../Binaries/Intermediates/" .. OutputDir .. "/%{prj.name}")

   filter "system:windows"
       systemversion "latest"
       defines { "WINDOWS" }

   filter "configurations:Debug"
       defines { "DEBUG" }
       runtime "Debug"
       symbols "On"

   filter "configurations:Release"
       defines { "RELEASE" }
       runtime "Release"
       optimize "On"
       symbols "On"

   filter "configurations:Dist"
       defines { "DIST" }
       runtime "Release"
       optimize "On"
       symbols "Off"