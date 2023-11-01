cmake_minimum_required(VERSION 3.16)
project(petri C)

set(CMAKE_C_STANDARD 99)

add_executable(petri main.c petri.c)