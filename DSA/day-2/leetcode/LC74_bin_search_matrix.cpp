#include <iostream>
#include <vector>
using namespace std;

// Time-complexity: O(log(rows*cols))
// Space-complexity: O(1)

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int left = 0, right = matrix.size() - 1, mid = 0;
    while (left <= right)
    {
        int mid_row = (int)((left + right) / 2);
        if (matrix[mid_row][0] > target)
        {
            right = mid_row - 1;
        }
        else if (matrix[mid_row][0] == target)
        {
            return true;
        }
        else
        {
            left = mid_row + 1;
            mid = mid_row;
        }
    }
    left = 0, right = matrix[0].size() - 1;
    while (left <= right)
    {
        int mid_col = (left + right) / 2;
        if (matrix[mid][mid_col] == target)
        {
            return true;
        }
        else if (matrix[mid][mid_col] > target)
        {
            right = mid_col - 1;
        }
        else
        {
            left = mid_col + 1;
        }
    }
    return false;
}

int main(){
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
    cout<< searchMatrix(matrix, target);
}