cmake_minimum_required(VERSION 3.15)
project(SBDLProject)

set(CMAKE_CXX_STANDARD 14)

include_directories(/usr/local/Cellar/sdl2/2.0.10/include/SDL2)
include_directories(/usr/local/Cellar/sdl2_image/2.0.5/include/SDL2)
include_directories(/usr/local/Cellar/sdl2_mixer/2.0.4/include/SDL2)
include_directories(/usr/local/Cellar/sdl2_ttf/2.0.15/include/SDL2)

link_directories(/usr/local/Cellar/sdl2/2.0.10/lib)
link_directories(/usr/local/Cellar/sdl2_image/2.0.5/lib)
link_directories(/usr/local/Cellar/sdl2_mixer/2.0.4/lib)
link_directories(/usr/local/Cellar/sdl2_ttf/2.0.15/lib)

link_libraries(SDL2main SDL2 SDL2_ttf SDL2_image SDL2_mixer)

add_executable(SBDLProject main.cpp)