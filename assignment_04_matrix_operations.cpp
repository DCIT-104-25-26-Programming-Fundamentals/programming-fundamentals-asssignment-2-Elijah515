// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

vector<vector<int>> read_matrix(string name) {
    int rows, cols;
    cout << "Enter number of rows for " << name << ": ";
    cin >> rows;
    cout << "Enter number of columns for " << name << ": ";
    cin >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));
    for (int i = 0; i < rows; i++) {
        cout << "Enter row " << (i + 1) << " (" << cols << " numbers): ";
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
    return matrix;
}

void display_matrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << setw(6) << num;
        }
        cout << endl;
    }
}

vector<vector<int>> transpose(const vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<int>> result(cols, vector<int>(rows));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
    return result;
}

vector<vector<int>> add_matrices(const vector<vector<int>>& a, const vector<vector<int>>& b) {
    int rows = a.size();
    int cols = a[0].size();
    vector<vector<int>> result(rows, vector<int>(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
    return result;
}

vector<vector<int>> multiply_matrices(const vector<vector<int>>& a, const vector<vector<int>>& b) {
    int rows_a = a.size();
    int cols_a = a[0].size();
    int cols_b = b[0].size();
    vector<vector<int>> result(rows_a, vector<int>(cols_b, 0));
    for (int i = 0; i < rows_a; i++) {
        for (int j = 0; j < cols_b; j++) {
            int total = 0;
            for (int k = 0; k < cols_a; k++) {
                total = total + a[i][k] * b[k][j];
            }
            result[i][j] = total;
        }
    }
    return result;
}

int main() {
    cout << "PART A - Transpose" << endl;
    vector<vector<int>> matrix_a = read_matrix("Matrix");
    cout << "Original Matrix:" << endl;
    display_matrix(matrix_a);
    cout << "Transposed Matrix:" << endl;
    display_matrix(transpose(matrix_a));

    cout << "\nPART B - Addition" << endl;
    vector<vector<int>> m1 = read_matrix("Matrix 1");
    vector<vector<int>> m2 = read_matrix("Matrix 2");

    if (m1.size() != m2.size() || m1[0].size() != m2[0].size()) {
        cout << "Error: Both matrices must be the same size to add them." << endl;
    } else {
        cout << "Sum Matrix:" << endl;
        display_matrix(add_matrices(m1, m2));
    }

    cout << "\nPART C - Multiplication" << endl;
    vector<vector<int>> m3 = read_matrix("Matrix A");
    vector<vector<int>> m4 = read_matrix("Matrix B");

    if (m3[0].size() != m4.size()) {
        cout << "Error: Number of columns in Matrix A must equal number of rows in Matrix B." << endl;
    } else {
        cout << "Product Matrix:" << endl;
        display_matrix(multiply_matrices(m3, m4));
    }

    return 0;
}
