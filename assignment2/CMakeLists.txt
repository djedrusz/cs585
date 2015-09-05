cmake_minimum_required(VERSION 2.6)
project(assignment2)
add_executable(assignment2 src/engine/memory/allocator.cpp src/engine/memory/default_allocator.cpp src/engine/memory/counting_allocator.cpp src/engine/containers/dynamic_array.cpp game.m.cpp)
