cmake_minimum_required(VERSION 3.10)

project(Calculator)

set(CMAKE_CXX_STANDARD 11)

# Opção para cobertura (só ativa para GCC/Clang)
option(CODE_COVERAGE "Enable code coverage" OFF)

if(CODE_COVERAGE)
    message(STATUS "Code coverage enabled")
    if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
        add_compile_options(--coverage)
        add_link_options(--coverage)
    elseif(MSVC)
        message(WARNING "Cobertura com MSVC será controlada externamente (ex: OpenCppCoverage)")
    else()
        message(WARNING "Code coverage not supported for this compiler.")
    endif()
endif()

# GoogleTest
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include_directories(include)

# Biblioteca
add_library(calculator src/calculator.cpp)

# Executável principal
add_executable(main src/main.cpp)
target_link_libraries(main calculator)

# Testes
enable_testing()
add_subdirectory(tests)
