cmake_minimum_required(VERSION 3.12.0)
project(popo VERSION 0.1.0)

include(CTest)
enable_testing()
set(CMAKE_CXX_STANDARD 17)

set(SPDLOG_INCLUDE /home/popo/work/javafx/Pilot-main/engine/3rdparty/spdlog/include)
include_directories(${SPDLOG_INCLUDE})

include_directories("/home/popo/work/include")

set(imgui_SOURCE_DIR_ /home/popo/work/javafx/Pilot-main/engine/3rdparty/imgui)

file(GLOB imgui_sources CONFIGURE_DEPENDS  "${imgui_SOURCE_DIR_}/*.cpp")
file(GLOB imgui_impl CONFIGURE_DEPENDS  
"${imgui_SOURCE_DIR_}/backends/imgui_impl_glfw.cpp" 
"${imgui_SOURCE_DIR_}/backends/imgui_impl_glfw.h"
"${imgui_SOURCE_DIR_}/backends/imgui_impl_opengl3.cpp" 
"${imgui_SOURCE_DIR_}/backends/imgui_impl_opengl3.h")
add_library(imgui STATIC ${imgui_sources} ${imgui_impl})
target_include_directories(imgui PUBLIC $<BUILD_INTERFACE:${imgui_SOURCE_DIR_}>)
target_link_libraries(imgui PUBLIC GL glfw -ldl)

include_directories("${imgui_SOURCE_DIR_}/backends>")

add_executable(popo main.cpp
Application.cpp
./platforms/LinuxWindows.cpp
glad.c
Layers.cpp
LayerStack.cpp
Imgui/ImguiLayer.cpp
)
target_include_directories(popo PUBLIC "${imgui_SOURCE_DIR_}/backends")

target_link_libraries(popo ${VK_LIB} GL glfw -lGL -lm -ldl -lXrandr -lX11 imgui)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
