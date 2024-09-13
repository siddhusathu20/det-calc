#include <iostream>
#include <vector>
#include <cmath>

using Matrix = std::vector<std::vector<double>>;

double determinant(Matrix matrix);
double cofactor(Matrix matrix, int row, int column);
void print_matrix(Matrix matrix);

int main() {
    Matrix matrix;
    std::cout << "Enter matrix order: ";
    int order;
    std::cin >> order;
    std::cout << "Enter matrix elements:\n";
    for (int i = 0; i < order; i++) {
        std::vector<double> row;
        for (int j = 0; j < order; j++) {
            double cell;
            std::cin >> cell;
            row.push_back(cell);
        }
        matrix.push_back(row);
    }
    std::cout << "Entered matrix:\n";
    print_matrix(matrix);
    std::cout << "Determinant: " << determinant(matrix);
}

double cofactor(Matrix matrix, int row, int column) {
    Matrix minor_matrix;
    for (int i = 0; i < matrix.size(); i++) {
        if (i != row) {
            std::vector<double> row;
            for (int j = 0; j < matrix.size(); j++) {
                if (j != column) {
                    row.push_back(matrix[i][j]);
                }
            }
            minor_matrix.push_back(row);
        }
    }
    double cf = std::pow(-1, row + column) * determinant(minor_matrix);
    return cf;
}

double determinant(Matrix matrix) {
    if (matrix.size() == 1) return matrix[0][0];
    else {
        double det;
        for (int j = 0; j < matrix.size(); j++) {
            det += matrix[0][j] * cofactor(matrix, 0, j);
        }
        return det;
    }
}

void print_matrix(Matrix matrix) {
    for (auto row : matrix) {
        for (double cell : row) {
            std::cout << cell << " ";
        }
        std::cout << "\n";
    }
}