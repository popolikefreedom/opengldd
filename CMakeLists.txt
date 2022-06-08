cmake_minimum_required(VERSION 3.12.0)
project(popo VERSION 0.1.0)

include(CTest)
enable_testing()
set(CMAKE_CXX_STANDARD 17)

set(SPDLOG_INCLUDE /home/popo/work/javafx/Pilot-main/engine/3rdparty/spdlog/include)
include_directories(${SPDLOG_INCLUDE})

add_executable(popo main.cpp
    Application.cpp
    ./platforms/LinuxWindows.cpp
)

target_link_libraries(popo ${VK_LIB} GL glfw -lGL -lm -ldl -lXrandr -lX11)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
