#pragma once
#include <iostream>
#include <vector>

namespace matrix{
	class Matrix {
	std::vector<std::vector<int>> data;
	uint32_t rows;
	uint32_t columns;
public:
	Matrix();
	Matrix(uint32_t rows, uint32_t columns);
	Matrix(const std::vector<std::vector<int>>& data);

	uint32_t getRows() const;
	uint32_t getColumns() const;

	Matrix operatorP(const Matrix& other) const;
	Matrix operatorM(const Matrix& other) const;

	friend std::istream& operator>>(std::istream& in, Matrix& matrix);
	friend std::ostream& operator<<(std::ostream& out, const Matrix& matrix);
};
}