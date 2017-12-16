cmake_minimum_required(VERSION 3.2)

project(otus.lessons.01.02)

find_package(spdlog CONFIG REQUIRED)
find_package(Threads)
find_package(fmt REQUIRED)

add_subdirectory("otus.lessons.01.02")
