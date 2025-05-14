cmake_minimum_required(VERSION 3.10)
project(link-encoder VERSION 1.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(link-encoder
    src/main.cpp
    src/url_encoder.cpp
)

target_include_directories(link-encoder PRIVATE include) 