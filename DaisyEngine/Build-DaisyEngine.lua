project "DaisyEngine"
   kind "StaticLib"
   language "C++"
   cppdialect "C++20"
   targetdir "Binaries/%{cfg.buildcfg}"
   staticruntime "off"

   files { "src/**.h", "src/**.cpp", "vendor/stb_image/**.h", "vendor/stb_image/**.cpp", "vendor/glm/**.hpp", "vendor/glm/detail/**.hpp", "vendor/glm/detail/**.hpp", "vendor/glm/ext/**.hpp", "vendor/glm/gtc/**.hpp", "vendor/glm/gtx/**.hpp", "vendor/glm/simd/**.hpp" }

   includedirs
   {
	
	"src",
	"GLFW",
	"glew",
	"vendor/glm",
	"vendor/stb_image",
	"vendor/glm",
	"../Petunia/src"

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