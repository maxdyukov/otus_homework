#pragma once

#include <vector>
#include <fstream>

using TMatrix = std::vector<std::vector<int>>;

class CalculateMatrix {
    public:
     CalculateMatrix(std::string input_file, std::string output_file);
     TMatrix sum(TMatrix& matrix1, TMatrix matrix2);
     void read_matrixs_from_file(const std::string& file_name = "");
     void write_result_to_file(const TMatrix& sum_vec);
     std::string get_input_file() const;
     std::string get_output_file() const;

    private:
     void read_matrix_from_file(std::ifstream &infile, std::vector<std::vector<int>>& matrix);
    protected:
     std::vector<std::vector<int>> matrix1_;
     std::vector<std::vector<int>> matrix2_;
     const std::string input_file_;
     const std::string output_file_;
};