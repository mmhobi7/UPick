cmake_minimum_required(VERSION 3.17)
project(YouPickProject)

set(CMAKE_CXX_STANDARD 11)

add_executable(YouPickProject main.cpp dataImporter.cpp dataImporter.h maxHeap.cpp maxHeap.h Restaurant.cpp Restaurant.h unordered_map.cpp unordered_map.h App.cpp App.h Graph.cpp Graph.h)