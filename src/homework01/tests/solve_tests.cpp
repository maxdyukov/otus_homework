#include <gtest/gtest.h>
#include <vector>

std::vector<double> solve(double a, double b, double c);

TEST(SolveTest, NotRootWhenSecondCoefIsZero) { 
    auto roots = solve(1.0, 0.0, 1.0);
    EXPECT_TRUE(roots.empty());
}

TEST(SolveTest, RootsWhenSecondCoefIsZero){
    auto roots = solve(1.0, 0.0, -1.0);
    EXPECT_FALSE(roots.empty());
    EXPECT_EQ(2, roots.size());
    EXPECT_DOUBLE_EQ(1.0, roots[0]);
    EXPECT_DOUBLE_EQ(-1.0, roots[1]);
}

TEST(SolveTest, OneRoots) { 
    auto roots = solve(1.0, 2.0, 1.0);
    EXPECT_DOUBLE_EQ(-1.0, roots[0]);
    EXPECT_DOUBLE_EQ(-1.0, roots[1]);
}