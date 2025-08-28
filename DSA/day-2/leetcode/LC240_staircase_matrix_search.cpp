#include <iostream>
#include <vector>
using namespace std;

// Time-complexity: O(rows+cols)
// Space-complexity: O(1)
// It's staircase search , it works when matrix is sorted in rows and cols but not sorted in flattern array.

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int row = 0, col = m - 1;
    while (row < n && col >= 0)
    {
        if (target == matrix[row][col])
            return true;
        else if (target > matrix[row][col])
            row++;
        else
            col--;
    }
    return false;
}

int main()
{
    int rows, cols, target;
    cout << "Enter no. of rows: ";
    cin >> rows;
    cout << "Enter no. of cols: ";
    cin >> cols;
    vector<vector<int>> matrix(rows, vector<int>(cols));
    cout << "Enter elements: ";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> matrix[i][j];
        }
    }
    cout << "Enter target: ";
    cin >> target;
    cout << searchMatrix(matrix, target);
}