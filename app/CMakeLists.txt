cmake_minimum_required(VERSION 3.22.1)

project("conanproject")

add_library(
        conanproject
        SHARED
        src/main/cpp/native-lib.cpp
)


find_library(log-lib log)

find_package(libyuv CONFIG)

target_link_libraries(
        conanproject
        libyuv::libyuv
)