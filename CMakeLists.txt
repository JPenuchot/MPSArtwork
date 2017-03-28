cmake_minimum_required(VERSION 2.8)
project(MPSArtwork)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O3")

find_package( OpenCV REQUIRED )
link_libraries(${OpenCV_LIBS})
include_directories(${OpenCV_INCLUDE_DIRECTORIES})

file(GLOB_RECURSE SOURCES "src/*")

add_executable(MPSArtwork ${SOURCES})