cmake_minimum_required(VERSION 3.7)
project(rush00)

set(CMAKE_CXX_STANDARD 11)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

set(SOURCE_FILES
        main.cpp
        Player.cpp
        Player.hpp
        Enemy.cpp
        Enemy.hpp
        Map.cpp
        Map.hpp RealPlayer.cpp RealPlayer.hpp)
add_executable(rush00 ${SOURCE_FILES})
target_link_libraries(rush00 ${CURSES_LIBRARIES})