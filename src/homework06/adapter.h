#pragma once

#include "calculate_matrix.h"
#include "generate_matrix.h"

class MatrixCalculatorAdapter : public GenerateMatrix {
 public:
  MatrixCalculatorAdapter(uint32_t row_size, uint32_t col_size,
                          std::string output_file)
      : GenerateMatrix(row_size, col_size, std::move(output_file)) {}

  virtual void generate(TMatrix&) override;
  virtual void write_to_file(TMatrix&) override;

 private:
  CalculateMatrix calc_matrix_;
};