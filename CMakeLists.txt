cmake_minimum_required(VERSION 3.17)
project(projectCpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(projectCpp main.cpp userData.cpp userData.h newOrder.cpp newOrder.h deliveryMen.cpp deliveryMen.h)
