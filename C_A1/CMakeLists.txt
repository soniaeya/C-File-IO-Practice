cmake_minimum_required(VERSION 3.23)
project(C_A1 C)

set(CMAKE_C_STANDARD 99)

add_executable(C_A1 replace.c text.c text.h traversal.c traversal.h report.c report.h)
