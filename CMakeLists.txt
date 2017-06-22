cmake_minimum_required(VERSION 3.7)
project(Rpg)

# set the standard used
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")
set(CMAKE_BUILD_TYPE Debug)

# Find the source files
file(GLOB_RECURSE USR_SRC "src/*" main.cpp)
file(GLOB_RECURSE LIB_SRC "lib/*")
set(SOURCE_FILES ${USR_SRC} ${LIB_SRC})


add_executable(RpgEngine.out ${SOURCE_FILES})
