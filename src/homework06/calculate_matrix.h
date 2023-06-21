#pragma once

#include <vector>
#include <string>

using TMatrix = std::vector<std::vector<int>>;

class CalculateMatrix {
    public:
     CalculateMatrix() = default;
     TMatrix sum(const TMatrix& matrix1,const TMatrix& matrix2);
     TMatrix readMatrixFromFile(const std::string& filePath);
     void writeMatrixToFile(const TMatrix& matrix, const std::string& filePath);
     void loadMatrices(const std::string& fileA, const std::string& fileB);
     void calculateAndSave(const std::string& outputFile);


    private:
     TMatrix matrixA_;
     TMatrix matrixB_;
};