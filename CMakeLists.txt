cmake_minimum_required(VERSION 2.6)

project(game)
find_package(Threads)
include_directories(gtest/include)
link_directories(mybuild)

add_executable(test_counting_allocator test_counting_allocator.cpp)
target_link_libraries(test_counting_allocator gtest gtest_main)
target_link_libraries(test_counting_allocator ${CMAKE_THREAD_LIBS_INIT})

add_executable(test_default_allocator test_default_allocator.cpp)
target_link_libraries(test_default_allocator gtest gtest_main)
target_link_libraries(test_default_allocator ${CMAKE_THREAD_LIBS_INIT})

add_executable(test_trivial test_trivial.cpp)
target_link_libraries(test_trivial gtest gtest_main)
target_link_libraries(test_trivial ${CMAKE_THREAD_LIBS_INIT})

add_executable(game game.m.cpp)
