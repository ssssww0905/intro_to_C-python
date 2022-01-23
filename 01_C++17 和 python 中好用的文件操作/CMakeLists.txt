cmake_minimum_required(VERSION 3.21)
project(intro_to_C_python)

add_executable(filesystem_test main.cpp)
target_compile_features(filesystem_test PUBLIC cxx_std_17)
