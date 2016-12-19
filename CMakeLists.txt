cmake_minimum_required(VERSION 3.6)
project(MPSArtwork)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O3")

set(SOURCE_FILES main.cpp Grid.cpp Grid.h Renderer.cpp Renderer.h StateDataStructure.h CellsBehaviorConstants.h)
add_executable(MPSArtwork ${SOURCE_FILES})

find_package( OpenCV REQUIRED )
target_link_libraries(MPSArtwork ${OpenCV_LIBS})