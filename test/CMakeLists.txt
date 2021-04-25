include(GoogleTest)
find_package(GTest REQUIRED)

add_executable(run_tests test_main.cpp
        iv/int_vector.cpp
        bv/bit_vector.cpp
        bv/bit_vector_il.cpp
        rank/rank_support_v5.cpp
        wt/wt.cpp
        wt/wt_int.cpp
)
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