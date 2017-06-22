cmake_minimum_required(VERSION 3.7)
project(Rpg)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE USR_SRC "src/*" main.cpp)
file(GLOB_RECURSE LIB_SRC "lib/*")
set(SOURCE_FILES ${USR_SRC} ${LIB_SRC})


add_executable(RpgEngine.out ${SOURCE_FILES})
