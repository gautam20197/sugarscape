cmake_minimum_required (VERSION 2.8.11)
project(sugarscape)

set(SRC "../lodepng/lodepng.h" "../lodepng/lodepng.cpp")

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(sugarscape ${SOURCES} ${SRC})