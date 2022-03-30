cmake_minimum_required(VERSION 3.21)
project(proj1)

set(CMAKE_CXX_STANDARD 14)

add_executable(proj1 main.cpp src/DeliveryPackage.cpp src/DeliveryPackage.h src/Courier.cpp src/Courier.h)
