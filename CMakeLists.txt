cmake_minimum_required(VERSION 3.28)
project(try_googletest VERSION 0.0.1
    DESCRIPTION "Try googletest"
    LANGUAGES CXX)
# Update the submodules here
include(cmake/UpdateSubmodules.cmake)
# Enable testing for this project
include(CTest)
# Add subdirectories with code
add_subdirectory(external)
