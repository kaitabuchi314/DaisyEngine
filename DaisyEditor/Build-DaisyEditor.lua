project "DaisyEditor"
   kind "ConsoleApp"
   language "C++"
   cppdialect "C++20"
   targetdir "Binaries/%{cfg.buildcfg}"
   staticruntime "off"

   files { "src/**.h", "src/**.cpp", "vendor/ImGui/**.h", "vendor/ImGui/**.cpp" }
   defines { 'PROJECTPATH="../Game/"'}
   includedirs
   {
	
	"src",
	"../DaisyEngine/GLFW",
	"../DaisyEngine/glew",
	"../DaisyEngine/vendor/glm",
	"../DaisyEngine/vendor/stb_image",
	"../DaisyEngine/vendor/glm",
	"../DaisyEngine/src",
	"vendor",
	"../Petunia/src",
    "../Game"

   }

   links
   {
	"DaisyEngine"
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