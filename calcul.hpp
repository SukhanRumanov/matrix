#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "matrix.hpp"

namespace calculator {
    class MatrixCalculator {
    public:
        void run();

    private:
        matrix::Matrix readMatrixFromInput();
        matrix::Matrix readMatrixFromFile(const std::string& filename);
        void addMatrices();
        void multiplyMatrices();
        std::string getFileName(); 
    };
}
