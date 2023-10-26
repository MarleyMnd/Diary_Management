cmake_minimum_required(VERSION 3.26)
project(Diary_Management_Project C)

set(CMAKE_C_STANDARD 11)

add_executable(Diary_Management_Project main.c
        level_cells.c
        level_cells.h
        level_lists.c
        level_lists.h
        colors.c
        colors.h
        color_management.c
        color_management.h)
