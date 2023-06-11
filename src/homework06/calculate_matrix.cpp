#include "calculate_matrix.h"

#include <iostream>

CalculateMatrix::CalculateMatrix(std::string input_file,
                                 std::string output_file)
    : input_file_(input_file),
      output_file_(output_file),
      rowsize_(0),
      colsize_(0){};

void CalculateMatrix::read_matrix_from_file(
    std::ifstream& infile, std::vector<std::vector<int>>& matrix) {
  infile >> rowsize_ >> colsize_;
  matrix.resize(rowsize_, std::vector<int>(colsize_, 0));
  for (uint i = 0; i < rowsize_; i++) {
    for (uint j = 0; j < colsize_; j++) {
      infile >> matrix[i][j];
    }
  }
}

void CalculateMatrix::read_two_matrixs_from_file() {
  std::ifstream in_file(input_file_);
  if (not in_file.is_open()) {
    throw std::runtime_error("Error open input file");
  }
  read_matrix_from_file(in_file, matrix1_);
  read_matrix_from_file(in_file, matrix2_);
  in_file.close();
}

void CalculateMatrix::write_result_to_file(const std::vector<std::vector<int>>& sum_vec) {
  std::ofstream out_file(output_file_);
  if (not out_file.is_open()) {
    throw std::runtime_error("Error open output file");
  }
  for (uint i = 0; i < rowsize_; i++) {
    for (uint j = 0; j < colsize_; j++) {
      out_file << sum_vec[i][j] << " ";
    }
    out_file << "\n";
  }
  out_file.close();
}

std::vector<std::vector<int>> CalculateMatrix::sum() {
  read_two_matrixs_from_file();

  if (matrix1_.size() not_eq matrix2_.size() or
      matrix1_.front().size() != matrix2_.front().size()) {
    throw std::invalid_argument("Size not matix");
  }

  std::vector<std::vector<int>> sum_vec;
  for (uint i = 0; i < rowsize_; i++) {
    for (uint j = 0; j < colsize_; j++) {
      sum_vec[i][j] = matrix1_[i][j] + matrix2_[i][j];
    }
  }
  return sum_vec;
}