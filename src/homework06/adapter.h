#pragma once

#include "calculate_matrix.h"
#include "generate_matrix.h"

class CalculateMatrixAdapter : public GenerateMatrix {
 public:
  CalculateMatrixAdapter(uint32_t row_size, uint32_t col_size,
                        std::string output_file);

 private:
  uint32_t row_size_;
  uint32_t col_size_;
  std::string output_file_;
  CalculateMatrix calc_matrix_;
};
