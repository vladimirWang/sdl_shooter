cmake_minimum_required(VERSION 3.10.0)
project(SDLshooter VERSION 0.1.0 LANGUAGES C CXX)

include_directories("C:/sdl_library/sdl2/include")
link_directories("C:/sdl_library/sdl2/lib/x64")
add_executable(SDLshooter main.cpp)
# target_link_directories(SDLshooter SDL2main SDL2)

