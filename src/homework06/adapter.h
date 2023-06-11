#pragma once

#include "calculate_matrix.h"
#include "generate_matrix.h"

class GenerateMatrixAdapter : public CalculateMatrix {
 public:
  GenerateMatrixAdapter(uint32_t row_size, uint32_t col_size,
                        std::string output_file);

  std::vector<std::vector<int>> sum() override;

 private:
  uint32_t row_size_;
  uint32_t col_size_;
};
