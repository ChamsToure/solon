cmake_minimum_required(VERSION 3.5)

project(solon)
include_directories(search/)
set(SOURCES main.cpp search/search.cpp)
add_executable(solon ${SOURCES})

