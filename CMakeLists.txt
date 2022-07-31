
option(ALGORITHMIC_LIBRARY_BUILD_TESTS "Build all of algorithmic's own tests." OFF)

cmake_minimum_required(VERSION 3.14)

project(algorithmic-library VERSION 0.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# place binaries and libraries according to GNU standards
include(GNUInstallDirs)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})

include(FetchContent)

FetchContent_Declare(
    lodash_cpp
    GIT_REPOSITORY https://github.com/Dup4/lodash-cpp.git
    GIT_TAG v0.0.1
)

FetchContent_MakeAvailable(lodash_cpp)
FetchContent_GetProperties(lodash_cpp)
set(LODASH_CPP_INCLUDE_DIR ${lodash_cpp_SOURCE_DIR}/include)

include_directories(
    ${PROJECT_SOURCE_DIR}/include/
    ${LODASH_CPP_INCLUDE_DIR}
)

add_library(algorithmic-library INTERFACE)
target_include_directories(algorithmic-library INTERFACE
    ${PROJECT_SOURCE_DIR}/include/
    ${LODASH_CPP_INCLUDE_DIR}
)

if (ALGORITHMIC_LIBRARY_BUILD_TESTS)

enable_testing()

add_subdirectory(test/)

endif()
