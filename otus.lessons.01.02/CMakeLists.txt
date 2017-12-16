add_executable(
    otus.lessons.01.02 
        "src/otus.lessons.01.02.cpp"
)

add_executable(
    otus.lessons.01.02.test 
        "src/otus.lessons.01.02.test.cpp"
)

if (NOT WIN32)
	set_target_properties(otus.lessons.01.02 otus.lessons.01.02.test PROPERTIES
		CXX_STANDARD 14
		CXX_STANDARD_REQUIRED ON
		COMPILE_OPTIONS -Wpedantic -Wall -Wextra
	)

endif()

set_target_properties(otus.lessons.01.02.test PROPERTIES
	COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
	INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

target_link_libraries(otus.lessons.01.02 spdlog::spdlog ${CMAKE_THREAD_LIBS_INIT})
if (WIN32)
	target_link_libraries(otus.lessons.01.02 fmt::fmt fmt::fmt-header-only)
endif()

target_link_libraries(otus.lessons.01.02.test ${Boost_LIBRARIES})

add_test(test otus.lessons.01.02.test)