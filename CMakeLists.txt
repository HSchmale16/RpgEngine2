cmake_minimum_required(VERSION 3.7)
project(Rpg)

if(MSVC)
  # Force to always compile with W4
  if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
    string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
  else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
  endif()
elseif(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
  # Update if necessary
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wno-long-long -pedantic")
endif()

# set the standard used
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")
set(CMAKE_BUILD_TYPE Debug)

# Find the source files
file(GLOB_RECURSE USR_SRC "src/*")
file(GLOB_RECURSE LIB_SRC "lib/*")
set(SOURCE_FILES ${USR_SRC} ${LIB_SRC})

# Add the include directories)
include_directories(include)
include_directories(lib)

# Create a library from source, as it will allow easier updating of the core
add_library(RpgEngine SHARED ${SOURCE_FILES})

# Primary Executable
add_executable(RpgEngine.out main.cpp)
target_link_libraries(RpgEngine.out RpgEngine)

# Executable to fiddle with the requirements engine
#add_executable(RequirementsEngineTest.out testprogs/RequirementEngineTest.cpp)
#target_link_libraries(RequirementsEngineTest.out RpgEngine)