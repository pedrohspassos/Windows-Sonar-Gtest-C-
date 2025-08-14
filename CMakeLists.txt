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

# Adiciona flags de cobertura apenas para GCC/Clang
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(--coverage)
    set(COVERAGE_LIBS --coverage)
endif()

include_directories(include)

# Alvo da biblioteca
add_library(calculator src/calculator.cpp)

# Executável principal
add_executable(main src/main.cpp)
target_link_libraries(main calculator ${COVERAGE_LIBS})

# Testes
enable_testing()
add_subdirectory(tests)