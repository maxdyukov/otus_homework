#include <gtest/gtest.h>
#include <vector>
#include <cfloat>

std::vector<double> solve(double a, double b, double c);
bool isEqual(double x, double y, double eps);

TEST(SolveTest, Not_Root_When_Second_Coef_Is_Zero) { 
    auto roots = solve(1.0, 0.0, 1.0);
    EXPECT_TRUE(roots.empty());
}

TEST(SolveTest, Roots_When_Second_Coef_Is_Zero){
    auto roots = solve(1.0, 0.0, -1.0);
    EXPECT_FALSE(roots.empty());
    EXPECT_EQ(2, roots.size());
    EXPECT_DOUBLE_EQ(1.0, roots[0]);
    EXPECT_DOUBLE_EQ(-1.0, roots[1]);
}

TEST(SolveTest, One_Roots) { 
    auto roots = solve(1.0, 2.0, 1.0);
    EXPECT_DOUBLE_EQ(-1.0, roots[0]);
    EXPECT_DOUBLE_EQ(-1.0, roots[1]);
}

TEST(SolveTest, A_Is_Zerro) { 
    EXPECT_THROW(solve(0.0, 2.0, 1.0), std::invalid_argument);
}

TEST(SolveTest, D_Is_Very_Small) {
    // a = 1, b = 0.0002, c = 0.0001 
    double D =  4 * 1 * 0.0001;
    EXPECT_GE(D, 0.0);
    EXPECT_TRUE(isEqual(D, 0.0, 0.001));

    auto roots = solve(1, 0.0002, 0.0001);
    ASSERT_TRUE(roots.empty());
}

TEST(SolveTest, Coef_Is_Not_double) { 
    EXPECT_THROW(solve(DBL_MAX, 3423.0, 234.0), std::invalid_argument);
    EXPECT_THROW(solve(123.0, DBL_MAX, 234.0), std::invalid_argument);
    EXPECT_THROW(solve(123.0, 3423.0, DBL_MAX), std::invalid_argument);
 }