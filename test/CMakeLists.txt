include(GoogleTest)
find_package(GTest REQUIRED)

file(GLOB SOURCE_FILES "*.cpp")
add_executable(run_tests test_main.cpp ${SOURCE_FILES})
target_link_libraries(run_tests
        static_sdsl_c
        GTest::GTest
)
target_include_directories(run_tests PUBLIC
        ${INCLUDE_DIRS}
        ${GTEST_INCLUDE_DIR}
)
gtest_add_tests(
        TARGET      run_tests
        TEST_SUFFIX .noArgs
        TEST_LIST   noArgsTests
)