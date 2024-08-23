cmake_minimum_required(VERSION 3.29)
project(Boids_sdl2)

set(CMAKE_CXX_STANDARD 20)
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
set(MY_SOURCE_FILES src/main.cpp
        src/init.cpp
        src/GetMedia.cpp
        src/Renderer.cpp
        include/Renderer.hpp
)
set(SDL2 /usr/include/SDL2)
add_executable(Boids_sdl2 ${MY_SOURCE_FILES})

target_link_libraries(Boids_sdl2 PUBLIC SDL2::SDL2 SDL2_image::SDL2_image)


target_include_directories(Boids_sdl2 PUBLIC include)

