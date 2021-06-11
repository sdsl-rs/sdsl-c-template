cmake_minimum_required(VERSION 3.8)
project(sdsl_c)
set(CMAKE_CXX_STANDARD 14)

# Build sdsl-lite
set(SDSL_LITE_DIR ${PROJECT_SOURCE_DIR}/lib/sdsl-lite)
set(SDSL_LITE_BUILD_DIR ${SDSL_LITE_DIR}/cmake-build-debug)
# TODO: Will probably need this: https://stackoverflow.com/questions/6351609/cmake-linking-to-library-downloaded-from-externalproject-add
set(SDSL_LITE_LIB ${SDSL_LITE_BUILD_DIR}/lib/libsdsl.a)
include(${CMAKE_ROOT}/Modules/ExternalProject.cmake)
ExternalProject_Add(sdsl_lite
    SOURCE_DIR ${SDSL_LITE_DIR}
    STEP_TARGETS build
    BINARY_DIR ${SDSL_LITE_BUILD_DIR}
    INSTALL_COMMAND cmake -E echo "Skipping install step."
)

file(GLOB SOURCE_FILES "src/*.cpp")
set(INCLUDE_DIRS
        ${PROJECT_SOURCE_DIR}/include
        ${SDSL_LITE_BUILD_DIR}/include
)

# Shared library
add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})
add_dependencies(${PROJECT_NAME} sdsl_lite)
target_link_libraries(${PROJECT_NAME}
    pthread
    ${SDSL_LITE_LIB}
)
target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_DIRS})
set_target_properties(${PROJECT_NAME} PROPERTIES
        COMPILE_FLAGS "-shared -fPIC"
)

# Static library
add_library(static_${PROJECT_NAME} STATIC ${SOURCE_FILES})
add_dependencies(static_${PROJECT_NAME} sdsl_lite)
target_link_libraries(static_${PROJECT_NAME}
        pthread
        ${SDSL_LITE_LIB}
)
target_include_directories(static_${PROJECT_NAME} PUBLIC ${INCLUDE_DIRS})
set_target_properties(static_${PROJECT_NAME} PROPERTIES
        OUTPUT_NAME ${PROJECT_NAME}
)

# Tests
enable_testing()
add_subdirectory(test)
add_test(run_tests run_tests)
