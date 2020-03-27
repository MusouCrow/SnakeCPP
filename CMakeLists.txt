cmake_minimum_required(VERSION 3.10)
project(SnakeCPP)

set(CMAKE_CXX_STANDARD 11)
set(SDL_DIR /usr/local/Cellar/sdl2/2.0.10) # SDL库所在路径

aux_source_directory(src/. SRC_DIR) # 把src目录下的所有cpp文件加入到SRC_DIR变量

# 添加头文件目录
include_directories(${SDL_DIR}/include/)
include_directories(include/)

link_directories(${SDL_DIR}/lib/) # 添加动态链接库目录

add_executable(SnakeCPP main.cpp ${SRC_DIR})
target_link_libraries(SnakeCPP -lSDL2) # 链接编译