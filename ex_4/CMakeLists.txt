cmake_minimum_required(VERSION 3.28)

project(RandomNumber
    VERSION 1.0
    DESCRIPTION "Random Number generator"
    LANGUAGES C )

add_executable(RandomNumber
    c_files/main.c
    c_files/random.c
    h_files/random.h)

#specifying that target requires C17
target_compile_features(RandomNumber PRIVATE c_std_17)

# Add compiler flags
target_compile_options(RandomNumber PRIVATE
    -Wall
    -Wextra
    -Wpedantic)

target_include_directories(RandomNumber PRIVATE h_files)



