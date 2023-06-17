#include "calculate_matrix.h"

#include <fstream>
#include <iostream>
#include <sstream>

TMatrix CalculateMatrix::readMatrixFromFile(const std::string& filePath) {
  std::ifstream file(filePath);
  std::vector<std::vector<int>> matrix;

  if (file.is_open()) {
    std::string line;
    while (std::getline(file, line)) {
      std::vector<int> row;
      std::istringstream iss(line);
      int num;
      while (iss >> num) {
        row.push_back(num);
      }
      matrix.push_back(row);
    }
    file.close();
  } else {
    std::cout << "Failed to open file: " << filePath << std::endl;
  }

  return matrix;
}

void CalculateMatrix::writeMatrixToFile(const TMatrix& matrix,
                                        const std::string& filePath) {
  std::ofstream file(filePath);

  if (file.is_open()) {
    for (const auto& row : matrix) {
      for (const auto& num : row) {
        file << num << " ";
      }
      file << std::endl;
    }
    file.close();
  } else {
    std::cout << "Failed to open file: " << filePath << std::endl;
  }
}

TMatrix CalculateMatrix::sum(const TMatrix& matrixA, const TMatrix& matrixB) {
  TMatrix result;

  if (matrixA.size() != matrixB.size() ||
      matrixA[0].size() != matrixB[0].size()) {
    std::cout << "Matrix dimensions do not match." << std::endl;
    return result;
  }

  for (size_t i = 0; i < matrixA.size(); ++i) {
    std::vector<int> row;
    for (size_t j = 0; j < matrixA[0].size(); ++j) {
      row.push_back(matrixA[i][j] + matrixB[i][j]);
    }
    result.push_back(row);
  }

  return result;
}

void CalculateMatrix::loadMatrices(const std::string& fileA,
                                   const std::string& fileB) {
  matrixA_ = readMatrixFromFile(fileA);
  matrixB_ = readMatrixFromFile(fileB);
}

// Функция для сложения матриц и сохранения результата в файл
void CalculateMatrix::calculateAndSave(const std::string& outputFile) {
  std::vector<std::vector<int>> resultMatrix = sum(matrixA_, matrixB_);
  writeMatrixToFile(resultMatrix, outputFile);
}