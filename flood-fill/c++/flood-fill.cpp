#include <iostream>
#include <vector>

using namespace std;

#include <iostream>
#include <vector>


using namespace std;

void graphDFS(vector<vector<int>>& image, int row, int col, int oldColor, int newColor) {
    if (image[row][col] == oldColor) {
        image[row][col] = newColor;
        int matrixHeight = image.size(), matrixWidth = image[0].size();

        if (row - 1 >= 0) graphDFS(image, row - 1, col, oldColor, newColor);
        if (col - 1 >= 0) graphDFS(image, row, col - 1, oldColor, newColor);
        if (row + 1 < matrixHeight) graphDFS(image, row + 1, col, oldColor, newColor);
        if (col + 1 < matrixWidth)  graphDFS(image, row, col + 1, oldColor, newColor);
    }
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int oldColor = image[sr][sc];
    // Perform DFS on the matrix and change all the pixels with the same color to the new color
    if (oldColor != newColor) graphDFS(image, sr, sc, oldColor, newColor);

    return image;
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

int main()
{
    vector<vector<int>> imagePixels = {{1,1,1} ,{1,1,0} ,{1,0,1}};
    int row = 1, col = 1, newColor = 2;
    
    floodFill(imagePixels, row, col, newColor);
    printMatrix(imagePixels);
}
