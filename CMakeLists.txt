cmake_minimum_required(VERSION 3.10)
project(Calculator)

set(CMAKE_CXX_STANDARD 11)

# GoogleTest
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Flags de cobertura
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-O0 -g --coverage)
    add_link_options(--coverage)
endif()

include_directories(include)

# Biblioteca principal
add_library(calculator src/calculator.cpp)

# Executável principal
add_executable(main src/main.cpp)
target_link_libraries(main calculator)

# Testes
add_executable(test_calculator tests/test_calculator.cpp)
target_link_libraries(test_calculator calculator gtest_main)

enable_testing()
add_test(NAME CalculatorTests COMMAND test_calculator)

# Alvo para cobertura
add_custom_target(coverage
    DEPENDS test_calculator
    COMMAND ctest --output-on-failure
    COMMAND gcovr
        -r ${CMAKE_SOURCE_DIR}
        --exclude 'tests/.*'
        --exclude 'src/main.cpp'
        --xml-pretty -o coverage/coverage.xml
        --html --html-details -o coverage/coverage.html
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Gerando relatórios de cobertura com gcovr"
)
