#include "generate_matrix.h"

#include <cstdlib>
#include <ctime>
#include <fstream>

GenerateMatrix::GenerateMatrix(uint32_t row_size, uint32_t col_size,
                               std::string output_file)
    : rowsize_(row_size), colsize_(col_size), output_file_(output_file) {}

void GenerateMatrix::write_to_file(std::vector<std::vector<int>>& matrix) {
  std::ofstream out_file(output_file_, std::ios::out | std::ios ::app);

  if (not out_file.is_open()) {
    throw std::runtime_error("Error open file for write matrix");
  }

  out_file << matrix.size() << " " << matrix.front().size() << std::endl;
  for (uint i = 0; i < matrix.size(); i++) {
    for (uint j = 0; j < matrix.front().size(); j++) {
      out_file << matrix[i][j] << " ";
    }
    out_file << std::endl;
  }
  out_file.close();
}

void GenerateMatrix::generate(std::vector<std::vector<int>>& matrix) {
  ::srand(time(0));

  matrix.resize(rowsize_);
  for (auto& v : matrix) {
    v.resize(colsize_);
  }

  for (auto& r : matrix) {
    for (auto& c : r) {
      c = ::rand();
    }
  }
}
