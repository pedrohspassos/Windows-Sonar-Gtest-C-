# Executável de teste
add_executable(test_calculator test_calculator.cpp)
target_link_libraries(test_calculator calculator gtest_main ${COVERAGE_LIBS})
add_test(NAME CalculatorTests COMMAND test_calculator)

## Caso eu queira mostrar cada teste de maneira unica (so funciona para o googletest)
## include(GoogleTest)
## gtest_discover_tests(test_calculator)
