cmake_minimum_required(VERSION 3.8)
project(sdsl_c)
set(CMAKE_CXX_STANDARD 14)


set(SDSL_LITE_BUILD ${PROJECT_SOURCE_DIR}/lib/sdsl-lite/cmake-build-debug/)
set(SDSL_LITE_LIB ${SDSL_LITE_BUILD}/lib/libsdsl.a)

include(${CMAKE_ROOT}/Modules/ExternalProject.cmake)
ExternalProject_Add(sdsl_lite
        SOURCE_DIR ${PROJECT_SOURCE_DIR}/lib/sdsl-lite
        STEP_TARGETS build
        BINARY_DIR ${PROJECT_SOURCE_DIR}/lib/sdsl-lite/cmake-build-debug
        INSTALL_COMMAND cmake -E echo "Skipping install step.")


set(SOURCE_FILES
        src/bv/bit_vector.cpp
        src/rank/rank_support_v5.cpp
        src/wt/wt.cpp
        src/wt/wt_int.cpp)
set(INCLUDE_DIRS
        ${PROJECT_SOURCE_DIR}/include
        ${SDSL_LITE_BUILD}/include)

add_library(sdsl_c SHARED
        ${SOURCE_FILES})
add_dependencies(sdsl_c sdsl_lite)
target_link_libraries(sdsl_c
    pthread
    ${SDSL_LITE_LIB})
target_include_directories(sdsl_c PUBLIC
        ${INCLUDE_DIRS})
set_target_properties(sdsl_c PROPERTIES
        COMPILE_FLAGS "-shared -fPIC")

add_library(static_sdsl_c STATIC
        ${SOURCE_FILES})
add_dependencies(static_sdsl_c sdsl_lite)
target_link_libraries(static_sdsl_c
        pthread
        ${SDSL_LITE_LIB})
target_include_directories(static_sdsl_c PUBLIC
        ${INCLUDE_DIRS})
set_target_properties(static_sdsl_c PROPERTIES
        OUTPUT_NAME sdsl_c)

enable_testing()
add_subdirectory(test)
add_test(run_tests run_tests)
