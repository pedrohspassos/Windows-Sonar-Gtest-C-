cmake_minimum_required(VERSION 3.10)

project(Calculator)

# GoogleTest integration
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(CMAKE_CXX_STANDARD 11)

# Flags de cobertura para GCC/Clang
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(--coverage)
    set(COVERAGE_LIBS --coverage)
endif()

include_directories(include)

add_library(calculator src/calculator.cpp)

add_executable(main src/main.cpp)
target_link_libraries(main calculator ${COVERAGE_LIBS})

add_executable(test_calculator tests/test_calculator.cpp)
target_link_libraries(test_calculator calculator gtest_main ${COVERAGE_LIBS})

enable_testing()
add_test(NAME CalculatorTests COMMAND test_calculator)

# Alvo customizado para gerar cobertura
add_custom_target(coverage
    COMMAND ${CMAKE_COMMAND} -E env
        gcovr
        -r ${CMAKE_SOURCE_DIR}
        --exclude '.*_deps/.*'
        --exclude '.*main\\.cpp'
        --xml-pretty -o coverage.xml
        --html --html-details -o coverage.html
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Gerando relatórios de cobertura com gcovr (HTML + XML)"
)
