#include "matrix.hpp"

namespace matrix {
	Matrix::Matrix() : rows(0), columns(0) {}

	Matrix::Matrix(uint32_t rows, uint32_t columns)
		: rows(rows), columns(columns), data(rows, std::vector<int>(columns, 0)) {}

	Matrix::Matrix(const std::vector<std::vector<int>>& data)
		: rows(data.size()), columns(data[0].size()), data(data) {}

    uint32_t Matrix::getRows() const {
        return rows;
    }

    uint32_t Matrix::getColumns() const {
        return columns;
    }


    Matrix Matrix::operatorP(const Matrix& other) const {
        if (this->getRows() != other.getRows() || this->getColumns() != other.getColumns()) {
            throw std::invalid_argument("Matrices must have the same dimensions for addition");
        }

        Matrix result(this->getRows(), this->getColumns());
        for (uint32_t i = 0; i < this->getRows(); ++i) {
            for (uint32_t j = 0; j < this->getColumns(); ++j) {
                result.data[i][j] = this->data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    Matrix Matrix::operatorM(const Matrix& other) const {
        if (this->getColumns() != other.getRows()) {
            throw std::invalid_argument("Matrices cannot be multiplied due to incompatible dimensions");
        }

        Matrix result(this->getRows(), other.getColumns());
        for (uint32_t i = 0; i < this->getRows(); ++i) {
            for (uint32_t j = 0; j < other.getColumns(); ++j) {
                for (uint32_t k = 0; k < this->getColumns(); ++k) {
                    result.data[i][j] += this->data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    std::istream& operator>>(std::istream& in, Matrix& matrix) {
        for (uint32_t i = 0; i < matrix.getRows(); ++i) {
            for (uint32_t j = 0; j < matrix.getColumns(); ++j) {
                in >> matrix.data[i][j];
            }
        }
        return in;
    }

    std::ostream& operator<<(std::ostream& out, const Matrix& matrix) {
        for (uint32_t i = 0; i < matrix.getRows(); ++i) {
            for (uint32_t j = 0; j < matrix.getColumns(); ++j) {
                out << matrix.data[i][j] << " ";
            }
            out << std::endl;
        }
        return out;
    }
}