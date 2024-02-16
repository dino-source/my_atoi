cmake_minimum_required(VERSION 3.28)

# Enable C++20 compiler support
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# BUILD_TESTING variable is created by include(CTest)
# It is set to ON by default
if (BUILD_TESTING)
    set(SOURCES "../solution.h" "../solution.cpp" "solution_test.cpp")
    add_executable(solution_test ${SOURCES})

    target_link_libraries(solution_test PRIVATE GTest::gtest_main)

    include(GoogleTest)
    # Finds all the Google tests associated with the executable
    gtest_discover_tests(solution_test)

    target_include_directories(solution_test PUBLIC tests)
endif()