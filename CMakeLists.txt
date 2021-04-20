cmake_minimum_required(VERSION 3.16)
project(UPick)

set(CMAKE_CXX_STANDARD 11)

add_executable(UPick main.cpp dataImporter.cpp dataImporter.h minHeap.cpp minHeap.h restaurant.cpp restaurant.h app.cpp app.h graph.cpp graph.h heapRestaurant.cpp heapRestaurant.h)