
#include <gtest/gtest.h>
#include "../include/calculator.h"

TEST(CalculatorTest, Add) {
    Calculator calc;
    EXPECT_EQ(calc.add(2, 3), 5);
}

TEST(CalculatorTest, Subtract) {
    Calculator calc;
    EXPECT_EQ(calc.subtract(5, 3), 2);
}

// TEST(CalculatorTest, Multiply) {
//     Calculator calc;
//     EXPECT_EQ(calc.multiply(4, 3), 12);
// }

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
