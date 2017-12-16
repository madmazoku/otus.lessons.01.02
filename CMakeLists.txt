cmake_minimum_required(VERSION 3.2)

project(otus.lessons.01.02)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(Threads)

if (WIN32)
	find_package(fmt REQUIRED)
endif()

add_subdirectory("otus.lessons.01.02")
