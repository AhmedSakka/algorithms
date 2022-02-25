#include <iostream>
#include <vector>

using namespace std;

void transposeMatrix(vector<vector<int>>& matrix) {
    int matrixSize = matrix.size();

    for (int i = 0; i < matrixSize; i++) {
        for (int j = i + 1; j < matrixSize; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}

void reverseMatrix(vector<vector<int>>& matrix) {
    int matrixSize = matrix.size();

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize / 2; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][matrixSize - 1 - j];
            matrix[i][matrixSize - 1 - j] = temp;
        }
    }
}

void printMatrix(const vector<vector<int>>& matrix) {
    int matrixSize = matrix.size();

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
void rotateMatrix(vector<vector<int>>& matrix) {
    transposeMatrix(matrix);
    reverseMatrix(matrix);
}

int main()
{
    vector<vector<int>> testMatrix = { {1, 2, 3},{4, 5, 6},{7, 8, 9} };
    rotateMatrix(testMatrix);
    printMatrix(testMatrix);
}
