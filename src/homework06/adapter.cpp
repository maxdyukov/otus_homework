#include "adapter.h"

  GenerateMatrixAdapter::GenerateMatrixAdapter(uint32_t row_size, uint32_t col_size,
                        std::string output_file)
      : CalculateMatrix("", output_file),
        row_size_(row_size),
        col_size_(col_size) {}

  std::vector<std::vector<int>> GenerateMatrixAdapter::sum() {
    GenerateMatrix generator(row_size_, col_size_, "");
    std::vector<std::vector<int>> matrix;
    generator.generate(matrix);
    matrix1_ = matrix;
    generator.generate(matrix);
    matrix2_ = matrix;
    return CalculateMatrix::sum();
  }