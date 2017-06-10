cmake_minimum_required(VERSION 3.7)
project(Rpg)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        include/Door.hpp
        include/Entity.hpp
        include/EntityBase.hpp
        include/Furniture.hpp
        include/Inventory.hpp
        include/Item.hpp
        include/ItemFactory.hpp
        include/Location.hpp
        include/Misc.h
        include/Room.hpp
        include/Session.hpp
        lib/json.hpp
        lib/tinydir.h
        src/Door.cpp
        src/Entity.cpp
        src/EntityBase.cpp
        src/Furniture.cpp
        src/Inventory.cpp
        src/Item.cpp
        src/ItemFactory.cpp
        src/Location.cpp
        src/Room.cpp
        src/Session.cpp
        main.cpp)

add_executable(Rpg ${SOURCE_FILES})