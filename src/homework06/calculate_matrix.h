#pragma once

#include <vector>
#include <fstream>

class CalculateMatrix {
    public:
     CalculateMatrix(std::string input_file, std::string output_file);
     virtual std::vector<std::vector<int>> sum();
     void read_two_matrixs_from_file();
     void write_result_to_file(const std::vector<std::vector<int>>& sum_vec);
    private:
     void read_matrix_from_file(std::ifstream &infile, std::vector<std::vector<int>>& matrix);
    protected:
     std::vector<std::vector<int>> matrix1_;
     std::vector<std::vector<int>> matrix2_;
     const std::string input_file_;
     const std::string output_file_;

     uint rowsize_;
     uint colsize_;
};