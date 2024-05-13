#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

using namespace std;

// Функция для считывания матрицы из файла
vector<vector<int>> readMatrixFromFile(const string& filename) {
    ifstream file(filename);
    vector<vector<int>> matrix;
    int value;
    while (file >> value) {
        matrix.emplace_back();
        matrix.back().push_back(value);
        while (file.peek() != '\n' && file >> value) {
            matrix.back().push_back(value);
        }
    }
    return matrix;
}

// Функция для записи матрицы в файл
void writeMatrixToFile(const vector<vector<int>>& matrix, const string& filename) {
    ofstream file(filename);
    for (const auto& row : matrix) {
        for (int value : row) {
            file << value << '\t';
        }
        file << '\n';
    }
}

// Функция для перемножения матриц
vector<vector<int>> matrixMultiplication(const vector<vector<int>>& matrix1, const vector<vector<int>>& matrix2) {
    int rows1 = matrix1.size();
    int cols1 = matrix1[0].size();
    int cols2 = matrix2[0].size();

    vector<vector<int>> result(rows1, vector<int>(cols2, 0));

    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols2; ++j) {
            for (int k = 0; k < cols1; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return result;
}

int main() {
    setlocale(LC_ALL, "Russian");
   // Чтение матриц из файлов
    vector<vector<int>> matrix1 = readMatrixFromFile("D:/parallel programming/python_pp/matrix_1000x1000.txt");
    vector<vector<int>> matrix2 = readMatrixFromFile("D:/parallel programming/python_pp/matrix_1000x1000_1.txt");

    // Выполнение перемножения матриц и замер времени
    auto start = chrono::high_resolution_clock::now();
    vector<vector<int>> result = matrixMultiplication(matrix1, matrix2);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    // Запись результата и информации о времени выполнения в файл
    writeMatrixToFile(result, "D:/parallel programming/result/res_1000.txt");
    ofstream timeFile("D:/parallel programming/result/stats.txt", std::ios::app);

    auto mat_size = result.size() * result[0].size();
    timeFile << mat_size << "\t" << duration.count() << "\n";
    cout << "Матрица результатов и информация о времени выполнения записаны в файлы." << endl;

    return 0;
}
