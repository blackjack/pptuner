cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(pptuner LANGUAGES C CXX VERSION 0.0.1)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

include(CompilerFlags)

configure_file(config.hpp.in ${CMAKE_CURRENT_BINARY_DIR}/config.hpp @ONLY)

add_subdirectory(src)
