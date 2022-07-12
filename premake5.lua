-- premake5.lua

workspace "RaavanaEngine"

configurations { "Debug", "Release" }
platforms { "Windows" }
architecture "x64"
cppdialect "C++17"
startproject "Sandbox"

filter "system:Windows"
systemversion "latest"



project "Sandbox"

   location "Sandbox"
   kind "ConsoleApp"
   language "C++"

   targetdir "bin/%{cfg.buildcfg}/%{prj.name}"
   objdir "bin-int/%{cfg.buildcfg}/%{prj.name}"

   includedirs {  "RaavanaEngine/src"}
   links {"RaavanaEngine"}

   files { "Sandbox/src/**.h", "Sandbox/src/**.cpp" }

   defines { "IMPORT_DLL"}

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "RELEASE" }
      optimize "On"



project "RaavanaEngine"

   location "RaavanaEngine"
   kind "SharedLib"
   language "C++"

   targetdir "bin/%{cfg.buildcfg}/%{prj.name}"
   objdir "bin-int/%{cfg.buildcfg}/%{prj.name}"

   includedirs {  "RaavanaEngine/src",
                  "RaavanaEngine/vendor",
                  "RaavanaEngine/vendor/GLFW/include",
                  "RaavanaEngine/vendor/GLEW/include"
               }

   files { "RaavanaEngine/src/**.h", "RaavanaEngine/src/**.cpp" }

   defines {"GLEW_STATIC", "EXPORT_DLL"}
   
   postbuildcommands { "{COPY} %{cfg.buildtarget.relpath} ../bin/%{cfg.buildcfg}/Sandbox" }

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "RELEASE" }
      optimize "On"


