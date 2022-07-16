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

   includedirs {  "RaavanaEngine/src", }
   links {"RaavanaEngine"}

   files {  "Sandbox/src/**.h",
            "Sandbox/src/**.cpp" 
         }

   defines { "RE_IMPORT_DLL"}

   filter "configurations:Debug"
      defines { "RE_DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "RE_RELEASE" }
      optimize "On"



project "RaavanaEngine"

   location "RaavanaEngine"
   kind "SharedLib"
   language "C++"

   targetdir "bin/%{cfg.buildcfg}/%{prj.name}"
   objdir "bin-int/%{cfg.buildcfg}/%{prj.name}"

   includedirs {  "RaavanaEngine/src",
                  "RaavanaEngine/src/RE",
                  "RaavanaEngine/vendor",
                  "RaavanaEngine/vendor/GLFW/include",
                  "RaavanaEngine/vendor/GLEW/include"
               }

   libdirs {   "RaavanaEngine/vendor/GLFW/lib-vc2019",
               "RaavanaEngine/vendor/GLEW/lib/x64"
           }

   links {  "glfw3.lib",
            "glew32s.lib",
            "opengl32.lib"
         }

   files {  "RaavanaEngine/src/**.h",
            "RaavanaEngine/src/**.cpp",
            "RaavanaEngine/vendor/stb-image/**.h",
            "RaavanaEngine/vendor/stb-image/**.cpp",
            "RaavanaEngine/vendor/imgui/**.h",
            "RaavanaEngine/vendor/imgui/**.cpp"
         }

   removefiles{   "RaavanaEngine/vendor/imgui/main.cpp"  }

   defines {"GLEW_STATIC", "RE_EXPORT_DLL"}
   
   postbuildcommands { "{COPY} %{cfg.buildtarget.relpath} ../bin/%{cfg.buildcfg}/Sandbox" }

   filter "configurations:Debug"
      defines { "RE_DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "RE_RELEASE" }
      optimize "On"


