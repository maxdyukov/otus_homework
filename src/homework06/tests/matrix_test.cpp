#include <gtest/gtest.h>
#include "adapter.h"

TEST(MatrixCalculatorAdapterTest, Sum) {
    MatrixCalculatorAdapter adapter(3, 3, "result.txt");
    TMatrix matrix;
    adapter.generate(matrix);
    adapter.write_to_file(matrix);

    ASSERT_EQ(matrix.size(), 3);
    ASSERT_EQ(matrix.front().size(), 3);
}