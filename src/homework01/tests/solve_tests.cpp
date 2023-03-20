#include <gtest/gtest.h>
#include <vector>

std::vector<double> solve(double a, double b, double c);

TEST(SolveTest, NotRootWhenSecondCoefIsZero) { 
    auto roots = solve(1, 0, 1);
    EXPECT_TRUE(roots.empty());
}