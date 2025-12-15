# 标题
cmake_minimum_required(VERSION 3.10.0)
project(SDLshooter VERSION 0.1.0 LANGUAGES C CXX)

# 查找并载入cmake预设
find_package(SDL2 REQUIRED)

# 添加可执行文件
add_executable(SDLshooter main.cpp)

# 链接
target_link_libraries(SDLshooter SDL2::SDL2main SDL2::SDL2)