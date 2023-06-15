#include "calculate_matrix.h"

#include <iostream>

CalculateMatrix::CalculateMatrix(std::string input_file,
                                 std::string output_file)
    : input_file_(input_file),
      output_file_(output_file){}

std::string CalculateMatrix::get_input_file() const { return input_file_; }
std::string CalculateMatrix::get_output_file() const { return output_file_; }

void CalculateMatrix::read_matrixs_from_file(const std::string& file_name) {
  uint rowsize{0}, colsize{0};
  std::string v_file_name{file_name};
  if (v_file_name.empty()){
    v_file_name = get_input_file();
  }
  std::ifstream v_file(v_file_name);
  if (not v_file.is_open()){
    throw std::runtime_error("Error open input file");
  }
  v_file >> rowsize >> colsize;
  matrix1_.resize(rowsize, std::vector<int>(colsize, 0));
  for (uint i = 0; i < rowsize; i++) {
    for (uint j = 0; j < colsize; j++) {
      v_file >> matrix1_[i][j];
    }
  }
  v_file >> rowsize >> colsize;
  matrix2_.resize(rowsize, std::vector<int>(colsize, 0));
  for (uint i = 0; i < rowsize; i++) {
    for (uint j = 0; j < colsize; j++) {
      v_file >> matrix2_[i][j];
    }
  }
}

void CalculateMatrix::write_result_to_file(const TMatrix& sum_vec) {
  std::ofstream out_file(output_file_);
  if (not out_file.is_open()) {
    throw std::runtime_error("Error open output file");
  }
  for (uint i = 0; i < sum_vec.size(); i++) {
    for (uint j = 0; j < sum_vec[i].size(); j++) {
      out_file << sum_vec[i][j] << " ";
    }
    out_file << "\n";
  }
  out_file.close();
}

TMatrix CalculateMatrix::sum(const TMatrix& matrix1, const TMatrix matrix2) {
  if (matrix1.size() not_eq matrix2.size() or
      matrix1.front().size() != matrix2.front().size()) {
    throw std::invalid_argument("Size not matix");
  }

  std::vector<std::vector<int>> sum_vec;
  for (uint i = 0; i < matrix1.size(); i++) {
    for (uint j = 0; j < matrix1.front().size(); j++) {
      sum_vec[i][j] = matrix1_[i][j] + matrix2_[i][j];
    }
  }
  return sum_vec;
}