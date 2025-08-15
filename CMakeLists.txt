cmake_minimum_required(VERSION 3.10)
project(Calculator)

set(CMAKE_CXX_STANDARD 11)

option(CODE_COVERAGE "Enable code coverage" OFF)

if(CODE_COVERAGE)
    message(STATUS "Code coverage enabled")
    if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
        add_compile_options(-fprofile-instr-generate -fcoverage-mapping -g)
        add_link_options(-fprofile-instr-generate)
    elseif(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
        add_compile_options(--coverage)
        add_link_options(--coverage)
    elseif(MSVC)
        message(WARNING "Code coverage with MSVC must be done externally (e.g., OpenCppCoverage).")
    else()
        message(WARNING "Code coverage not supported for this compiler.")
    endif()
endif()

# GoogleTest integration
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include_directories(include)

add_library(calculator src/calculator.cpp)
add_executable(main src/main.cpp)
target_link_libraries(main calculator)

enable_testing()
add_subdirectory(tests)
