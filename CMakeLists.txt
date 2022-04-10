cmake_minimum_required(VERSION 3.21)
project(proj1)

set(CMAKE_CXX_STANDARD 14)

add_executable(proj1 main.cpp src/DeliveryPackage.cpp src/DeliveryPackage.h src/DeliveryVan.cpp src/DeliveryVan.h src/problem2.cpp src/problem2.h)
