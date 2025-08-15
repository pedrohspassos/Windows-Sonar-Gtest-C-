cmake_minimum_required(VERSION 3.10)

project(Calculator)

set(CMAKE_CXX_STANDARD 11)

# Opção para ativar cobertura (usada apenas em GCC/Clang)
option(CODE_COVERAGE "Enable code coverage" OFF)

if(CODE_COVERAGE)
    message(STATUS "Code coverage enabled")
    if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
        add_compile_options(--coverage)
        add_link_options(--coverage)
    else()
        message(WARNING "Code coverage only supported with GCC or Clang")
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

# Alvo da biblioteca
add_library(calculator src/calculator.cpp)

# Executável principal
add_executable(main src/main.cpp)
target_link_libraries(main calculator)

# Testes
enable_testing()
add_subdirectory(tests)
