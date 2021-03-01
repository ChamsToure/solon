cmake_minimum_required(VERSION 3.5)

project(solon)
include_directories()
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#set(SOURCES main.cpp deck/deck.cpp search/search.cpp)

#add_executable(solon ${SOURCES})
add_executable(${PROJECT_NAME} main.cpp)
add_subdirectory(deck)
add_subdirectory(search)

target_link_libraries(${PROJECT_NAME} deck search )
