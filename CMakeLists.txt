cmake_minimum_required(VERSION 3.23)
project(untitled2 C)

set(CMAKE_C_STANDARD 99)

add_executable(untitled2 main.c report.c report.h)
add_executable(untitled2 traversal.c text.c text.h report.c report.h)
