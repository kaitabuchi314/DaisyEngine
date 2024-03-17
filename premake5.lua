workspace "DaisyEngine"
   architecture "x64"
   configurations { "Debug", "Release", "Dist" }
   startproject "SandboxProject"

   -- Workspace-wide build options for MSVC
   filter "system:windows"
      buildoptions { "/EHsc", "/Zc:preprocessor", "/Zc:__cplusplus" }

OutputDir = "%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}"

include "DaisyEngine/Build-DaisyEngine.lua"

include "SandboxProject/Build-SandboxProject.lua"
