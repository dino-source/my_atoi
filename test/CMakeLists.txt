cmake_minimum_required(VERSION 3.28)

# Enable C++20 compiler support
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# BUILD_TESTING variable is created by include(CTest)
# It is set to ON by default
if (BUILD_TESTING)
    set(SOURCES
        "../src/solution.h"
        "../src/solution.cpp"
        "fixBoundsTest.cpp"
        "hasSignTest.cpp"
        "isNegativeTest.cpp"
        "isPositiveTest.cpp")

    add_executable(my_atoi_test ${SOURCES})

    target_link_libraries(my_atoi_test PRIVATE GTest::gtest_main)

    include(GoogleTest)
    # Finds all the Google tests associated with the executable
    gtest_discover_tests(my_atoi_test)

    target_include_directories(my_atoi_test PUBLIC test src)
endif()