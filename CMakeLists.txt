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


# Target custom para gerar relatório de cobertura (e excluir)
add_custom_target(coverage
    COMMAND gcovr -r ${CMAKE_SOURCE_DIR}
        --exclude '.*_deps/.*'
        --exclude '.*main\.cpp'
        --xml-pretty -o coverage.xml
    COMMAND gcovr -r ${CMAKE_SOURCE_DIR}
        --exclude '.*_deps/.*'
        --exclude '.*main\.cpp'
        --html --html-details -o coverage.html
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Gerando relatório de cobertura com gcovr"
    VERBATIM
)