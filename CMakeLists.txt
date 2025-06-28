cmake_minimum_required(VERSION 3.10.0)
project(signalsmitch-stretch-c-wrapper VERSION 0.1.0 LANGUAGES C CXX)

add_library(signalsmitch-stretch-c-wrapper signalsmitch-stretch-c-wrapper.cpp)
target_include_directories(signalsmitch-stretch-c-wrapper PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

