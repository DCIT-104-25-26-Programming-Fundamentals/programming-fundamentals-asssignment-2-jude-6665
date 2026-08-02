// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


void displayMatrix(int matrix[10][10], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}


void transposeMatrix(int matrix[10][10], int rows, int cols)
{
    int transpose[10][10];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            transpose[j][i] = matrix[i][j];
        }
    }

    cout << "\nTransposed Matrix:\n";
    displayMatrix(transpose, cols, rows);
}


void addMatrices(int A[10][10], int B[10][10], int rows, int cols)
{
    int sum[10][10];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            sum[i][j] = A[i][j] + B[i][j];
        }
    }

    cout << "\nSum of Matrices:\n";
    displayMatrix(sum, rows, cols);
}


void multiplyMatrices(int A[10][10], int B[10][10], int result[10][10],
                      int rowsA, int colsA, int colsB)
{
    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++)
            {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "\nProduct of Matrices:\n";
    displayMatrix(result, rowsA, colsB);
}

int main()
{
    int matrix1[10][10], matrix2[10][10], result[10][10];
    int rows, cols;

    // ---------------- Part A ----------------
    cout << "PART A - Transpose Matrix\n";
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix1[i][j];
        }
    }

    cout << "\nOriginal Matrix:\n";
    displayMatrix(matrix1, rows, cols);
    transposeMatrix(matrix1, rows, cols);

    
    cout << "\nPART B - Add Two Matrices\n";

    cout << "Enter first matrix:\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix1[i][j];
        }
    }

    cout << "Enter second matrix:\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix2[i][j];
        }
    }

    addMatrices(matrix1, matrix2, rows, cols);

    
    cout << "\nPART C - Multiply Two Matrices\n";

    int rowsA, colsA, rowsB, colsB;

    cout << "Enter rows of Matrix A: ";
    cin >> rowsA;
    cout << "Enter columns of Matrix A: ";
    cin >> colsA;

    cout << "Enter rows of Matrix B: ";
    cin >> rowsB;
    cout << "Enter columns of Matrix B: ";
    cin >> colsB;

    if (colsA != rowsB)
    {
        cout << "Matrix multiplication is not possible." << endl;
        return 0;
    }

    cout << "Enter Matrix A:\n";
    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsA; j++)
        {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix1[i][j];
        }
    }

    cout << "Enter Matrix B:\n";
    for (int i = 0; i < rowsB; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix2[i][j];
        }
    }

    multiplyMatrices(matrix1, matrix2, result, rowsA, colsA, colsB);

    return 0;
}