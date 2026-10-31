cmake_minimum_required(VERSION 3.21)
project(stereo_width VERSION 0.1.0 LANGUAGES CXX)

add_library(stereo_width INTERFACE)
add_library(stereo_width::stereo_width ALIAS stereo_width)
target_include_directories(stereo_width INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_compile_features(stereo_width INTERFACE cxx_std_17)
