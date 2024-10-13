#include "calcul.hpp"

namespace calculator {

    void MatrixCalculator::run() {
        int choice;
        std::cout << "Выберите действие:\n";
        std::cout << "1. Сложение матриц\n";
        std::cout << "2. Умножение матриц\n";
        std::cout << "0. Выход\n";
        std::cin >> choice;

        switch (choice) {
        case 1:
            addMatrices();
            break;
        case 2:
            multiplyMatrices();
            break;
        case 0:
            std::cout << "Выход из программы.\n";
            return;
        default:
            std::cout << "Неверный выбор, попробуйте еще раз.\n";
            break;
        }

        run(); 
    }

    matrix::Matrix MatrixCalculator::readMatrixFromInput() {
        uint32_t rows, columns;
        std::cout << "Введите количество строк и столбцов матрицы: ";
        std::cin >> rows >> columns;

        matrix::Matrix matrix(rows, columns);
        std::cout << "Введите элементы матрицы:\n";
        std::cin >> matrix; 

        return matrix;
    }

    matrix::Matrix MatrixCalculator::readMatrixFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Не удалось открыть файл: " + filename);
        }

        uint32_t rows, columns;
        file >> rows >> columns;
        matrix::Matrix matrix(rows, columns);
        file >> matrix; 

        return matrix;
    }

    std::string MatrixCalculator::getFileName() {
        std::string filename;
        std::cout << "Введите имя файла: ";
        std::cin >> filename; 
        return filename;
    }

    void MatrixCalculator::addMatrices() {
        std::cout << "Выберите способ ввода:\n";
        std::cout << "1. Ввод из консоли\n";
        std::cout << "2. Ввод из файла\n";

        int inputChoice;
        std::cin >> inputChoice;

        matrix::Matrix matrix1, matrix2;

        if (inputChoice == 1) {
            std::cout << "Чтение первой матрицы из ввода:\n";
            matrix1 = readMatrixFromInput();
            std::cout << "Чтение второй матрицы из ввода:\n";
            matrix2 = readMatrixFromInput();
        }
        else if (inputChoice == 2) {
            std::string filename1 = getFileName();
            std::cout << "Чтение первой матрицы из файла: " << filename1 << std::endl;
            matrix1 = readMatrixFromFile(filename1);

            std::string filename2 = getFileName();
            std::cout << "Чтение второй матрицы из файла: " << filename2 << std::endl;
            matrix2 = readMatrixFromFile(filename2);
        }
        else {
            std::cout << "Неверный выбор. Операция прервана.\n";
            return;
        }

        try {
            matrix::Matrix result = matrix1.operatorP(matrix2);
            std::cout << "Результат:\n" << result; 
        }
        catch (const std::invalid_argument& e) {
            std::cerr << "Ошибка: " << e.what() << std::endl;
        }
    }

    void MatrixCalculator::multiplyMatrices() {
        std::cout << "Выберите способ ввода:\n";
        std::cout << "1. Ввод из консоли\n";
        std::cout << "2. Ввод из файла\n";

        int inputChoice;
        std::cin >> inputChoice;

        matrix::Matrix matrix1, matrix2;

        if (inputChoice == 1) {
            std::cout << "Чтение первой матрицы из ввода:\n";
            matrix1 = readMatrixFromInput();
            std::cout << "Чтение второй матрицы из ввода:\n";
            matrix2 = readMatrixFromInput();
        }
        else if (inputChoice == 2) {
            std::string filename1 = getFileName();
            std::cout << "Чтение первой матрицы из файла: " << filename1 << std::endl;
            matrix1 = readMatrixFromFile(filename1);

            std::string filename2 = getFileName();
            std::cout << "Чтение второй матрицы из файла: " << filename2 << std::endl;
            matrix2 = readMatrixFromFile(filename2);
        }
        else {
            std::cout << "Неверный выбор. Операция прервана.\n";
            return;
        }

        try {
            matrix::Matrix result = matrix1.operatorM(matrix2);
            std::cout << "Результат:\n" << result; 
        }
        catch (const std::invalid_argument& e) {
            std::cerr << "Ошибка: " << e.what() << std::endl;
        }
    }
}
