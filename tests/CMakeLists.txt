# BUILD_TESTING variable is created by include(CTest)
# It is set to ON by default
if (BUILD_TESTING)
    add_executable(my_atoi_test my_atoi_test.cpp)
    target_link_libraries(my_atoi_test PRIVATE GTest::gtest_main)

    include(GoogleTest)
    # Finds all the Google tests associated with the executable
    gtest_discover_tests(my_atoi_test)

    target_include_directories(my_atoi_test PUBLIC tests)
endif()