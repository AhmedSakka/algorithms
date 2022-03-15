#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
    map<int, priority_queue<int, vector<int>, greater<int>>> diagonalsMap;

    int rows = mat.size();
    int cols = mat[0].size();

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            diagonalsMap[i - j].push(mat[i][j]);
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            mat[i][j] = diagonalsMap[i - j].top();
            diagonalsMap[i - j].pop();
        }
    }

    return mat;
}

void printMatrix(vector<vector<int>>& matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> inputMatrix = { {3, 3, 1, 1},{2, 2, 1, 2},{1, 1, 1, 2} };
    vector<vector<int>> outputMatrix = diagonalSort(inputMatrix);

    printMatrix(outputMatrix);

    return 0;
}