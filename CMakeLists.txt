cmake_minimum_required(VERSION 3.10)
project(SnakeCPP)

set(CMAKE_CXX_STANDARD 11)
set(SDL_DIR /usr/local/Cellar/sdl2/2.0.8) # SDL库所在路径

include_directories(${SDL_DIR}/include/) # 添加头文件目录
link_directories(${SDL_DIR}/lib/) # 添加动态链接库目录

add_executable(SnakeCPP main.cpp)
target_link_libraries(SnakeCPP -lSDL2) # 链接编译