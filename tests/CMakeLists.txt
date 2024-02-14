# BUILD_TESTING variable is created by include(CTest)
# It is set to ON by default
if (BUILD_TESTING)
    add_executable(tests tests.cpp)
    target_link_libraries(tests PRIVATE GTest::gtest_main)

    include(GoogleTest)
    # Finds all the Google tests associated with the executable
    gtest_discover_tests(tests)
endif()