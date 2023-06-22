#include "adapter.h"

void MatrixCalculatorAdapter::generate(TMatrix& matrix) {
  TMatrix matrix1, matrix2;
  GenerateMatrix::generate(matrix1);
  GenerateMatrix::generate(matrix2);

  matrix = calc_matrix_.sum(matrix1, matrix2);
}
void MatrixCalculatorAdapter::write_to_file(TMatrix& matrix) {
  GenerateMatrix::write_to_file(matrix);
}