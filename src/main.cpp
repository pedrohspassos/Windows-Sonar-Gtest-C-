#include <iostream>
#include "../include/calculator.h"

int main() {
    Calculator calc;
    int a = 10, b = 5;
    std::cout << "Add: " << calc.add(a, b) << std::endl;
    std::cout << "Subtract: " << calc.subtract(a, b) << std::endl;
    std::cout << "Multiply: " << calc.multiply(a, b) << std::endl;
    return 0;
}
