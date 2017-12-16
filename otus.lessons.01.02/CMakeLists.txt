add_executable(
    otus.lessons.01.02 
        "src/otus.lessons.01.02.cpp"
)

target_link_libraries(otus.lessons.01.02 spdlog::spdlog ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(otus.lessons.01.02 fmt::fmt fmt::fmt-header-only)