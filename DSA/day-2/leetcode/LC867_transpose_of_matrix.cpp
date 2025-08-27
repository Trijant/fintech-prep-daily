#include <iostream>
#include <vector>
using namespace std;

// Time-complexity: O(rows*cols)
// Space-complexity: O(rows*cols)

vector<vector<int>> transpose(vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<int>> transpose_mat(cols, vector<int>(rows));
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            transpose_mat[j][i] = matrix[i][j];
        }
    }
    return transpose_mat;
}

int main(){
    int rows, cols;
    cout << "Enter no. of rows: ";
    cin >> rows;
    cout << "Enter no. of cols: ";
    cin >> cols;
    vector<vector<int>> matrix(rows, vector<int>(cols));
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> matrix[i][j];
        }
    }
    vector<vector<int>> transposed_matrix = transpose(matrix);
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            cout << transposed_matrix[i][j]<<" ";
        }
        cout << endl;
    }
}