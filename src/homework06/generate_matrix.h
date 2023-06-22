#pragma once

#include <vector>
#include <string>

class GenerateMatrix {
    public:
     GenerateMatrix(uint32_t row_size, uint32_t col_size, std::string output_file);
     virtual void generate(std::vector<std::vector<int>>&);
     virtual void write_to_file(std::vector<std::vector<int>>&);
    private:
     private:
      uint32_t rowsize_;
      uint32_t colsize_;
      std::string output_file_;
};