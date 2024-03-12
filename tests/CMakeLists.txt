cmake_minimum_required(VERSION 3.28)

# Enable C++20 compiler support
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# BUILD_TESTING variable is created by include(CTest)
# It is set to ON by default
if (BUILD_TESTING)
    set(SOURCES
        "discard_leading_spaces_test.cpp"
        "has_sign_test.cpp"
        "is_negative_test.cpp"
        "is_positive_test.cpp"
        "my_atoi_test.cpp"
        "number_of_digits_test.cpp"
        "../src/solution.h"
        "../src/solution.cpp")
    add_executable(solution_test ${SOURCES})

    target_link_libraries(solution_test PRIVATE GTest::gtest_main)

    include(GoogleTest)
    # Finds all the Google tests associated with the executable
    gtest_discover_tests(solution_test)

    target_include_directories(solution_test PUBLIC tests src)
endif()