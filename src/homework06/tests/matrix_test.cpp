#include <gtest/gtest.h>
#include "adapter.h"

TEST(GenerateMatrixAdapterTest, Sum) {
    GenerateMatrixAdapter adapter(3, 3, "result.txt");
    adapter.sum();
    std::vector<std::vector<int>> expected = {{2, 2, 2}, {2, 2, 2}, {2, 2, 2}};
    std::vector<std::vector<int>> actual = adapter.sum();
    ASSERT_EQ(expected, actual);
}