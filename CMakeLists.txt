cmake_minimum_required(VERSION 3.29)
project(Zombie_Hunter)

include_directories("C:/Users/acsel/Documents/Programming/C++/Libs/SDL2-2.30.6/include") #sdl library

set(CMAKE_CXX_STANDARD 20)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static") #so you can build it statically
add_executable(Zombie_Hunter main.cpp
        Player.cpp
        Player.h
        Vector2i.h
)

target_link_libraries(Zombie_Hunter "C:/Users/acsel/Documents/Programming/C++/Libs/SDL2-2.30.6/lib/x64/SDL2.lib") #sdl library