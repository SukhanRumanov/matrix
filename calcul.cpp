#include "calcul.hpp"

namespace calculator {

    void MatrixCalculator::run() {
        int choice;
        std::cout << "�������� ��������:\n";
        std::cout << "1. �������� ������\n";
        std::cout << "2. ��������� ������\n";
        std::cout << "0. �����\n";
        std::cin >> choice;

        switch (choice) {
        case 1:
            addMatrices();
            break;
        case 2:
            multiplyMatrices();
            break;
        case 0:
            std::cout << "����� �� ���������.\n";
            return;
        default:
            std::cout << "�������� �����, ���������� ��� ���.\n";
            break;
        }

        run(); 
    }

    matrix::Matrix MatrixCalculator::readMatrixFromInput() {
        uint32_t rows, columns;
        std::cout << "������� ���������� ����� � �������� �������: ";
        std::cin >> rows >> columns;

        matrix::Matrix matrix(rows, columns);
        std::cout << "������� �������� �������:\n";
        std::cin >> matrix; 

        return matrix;
    }

    matrix::Matrix MatrixCalculator::readMatrixFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            throw std::runtime_error("�� ������� ������� ����: " + filename);
        }

        uint32_t rows, columns;
        file >> rows >> columns;
        matrix::Matrix matrix(rows, columns);
        file >> matrix; 

        return matrix;
    }

    std::string MatrixCalculator::getFileName() {
        std::string filename;
        std::cout << "������� ��� �����: ";
        std::cin >> filename; 
        return filename;
    }

    void MatrixCalculator::addMatrices() {
        std::cout << "�������� ������ �����:\n";
        std::cout << "1. ���� �� �������\n";
        std::cout << "2. ���� �� �����\n";

        int inputChoice;
        std::cin >> inputChoice;

        matrix::Matrix matrix1, matrix2;

        if (inputChoice == 1) {
            std::cout << "������ ������ ������� �� �����:\n";
            matrix1 = readMatrixFromInput();
            std::cout << "������ ������ ������� �� �����:\n";
            matrix2 = readMatrixFromInput();
        }
        else if (inputChoice == 2) {
            std::string filename1 = getFileName();
            std::cout << "������ ������ ������� �� �����: " << filename1 << std::endl;
            matrix1 = readMatrixFromFile(filename1);

            std::string filename2 = getFileName();
            std::cout << "������ ������ ������� �� �����: " << filename2 << std::endl;
            matrix2 = readMatrixFromFile(filename2);
        }
        else {
            std::cout << "�������� �����. �������� ��������.\n";
            return;
        }

        try {
            matrix::Matrix result = matrix1.operatorP(matrix2);
            std::cout << "���������:\n" << result; 
        }
        catch (const std::invalid_argument& e) {
            std::cerr << "������: " << e.what() << std::endl;
        }
    }

    void MatrixCalculator::multiplyMatrices() {
        std::cout << "�������� ������ �����:\n";
        std::cout << "1. ���� �� �������\n";
        std::cout << "2. ���� �� �����\n";

        int inputChoice;
        std::cin >> inputChoice;

        matrix::Matrix matrix1, matrix2;

        if (inputChoice == 1) {
            std::cout << "������ ������ ������� �� �����:\n";
            matrix1 = readMatrixFromInput();
            std::cout << "������ ������ ������� �� �����:\n";
            matrix2 = readMatrixFromInput();
        }
        else if (inputChoice == 2) {
            std::string filename1 = getFileName();
            std::cout << "������ ������ ������� �� �����: " << filename1 << std::endl;
            matrix1 = readMatrixFromFile(filename1);

            std::string filename2 = getFileName();
            std::cout << "������ ������ ������� �� �����: " << filename2 << std::endl;
            matrix2 = readMatrixFromFile(filename2);
        }
        else {
            std::cout << "�������� �����. �������� ��������.\n";
            return;
        }

        try {
            matrix::Matrix result = matrix1.operatorM(matrix2);
            std::cout << "���������:\n" << result; 
        }
        catch (const std::invalid_argument& e) {
            std::cerr << "������: " << e.what() << std::endl;
        }
    }
}
