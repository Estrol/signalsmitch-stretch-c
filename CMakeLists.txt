cmake_minimum_required(VERSION 3.10.0)
project(signalsmith-stretch-c-wrapper VERSION 0.1.0 LANGUAGES C CXX)

add_library(
    signalsmith-stretch-c-wrapper 
    signalsmith-stretch-c-wrapper.cpp
    signalsmith-stretch-c-wrapper.h
)
target_include_directories(signalsmith-stretch-c-wrapper PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

