cmake_minimum_required(VERSION 3.10)

project(Calculator)

# GoogleTest integration
include(FetchContent)
FetchContent_Declare(
	googletest
	URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_library(calculator src/calculator.cpp)
add_executable(main src/main.cpp)
target_link_libraries(main calculator)

add_executable(test_calculator tests/test_calculator.cpp)

target_link_libraries(test_calculator calculator gtest_main)

enable_testing()
add_test(NAME CalculatorTests COMMAND test_calculator)
