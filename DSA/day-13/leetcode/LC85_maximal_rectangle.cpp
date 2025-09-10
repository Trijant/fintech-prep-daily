#include<iostream>
#include<vector>
using namespace std;

// topic: stack
// time-complexity: O(row*col)
// space-complexity: O(col)

int maximalRectangle(vector<vector<char>> &matrix)
{
    int rows = matrix.size();
    if (rows == 0)
    {
        return 0;
    }
    int cols = matrix[0].size();
    vector<int> heights(cols + 1, 0);
    int st[201];
    int top = -1;
    int maxArea = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j <= cols; j++)
        {
            if (j >= cols || matrix[i][j] == '0')
            {
                heights[j] = 0;
            }
            else
            {
                ++heights[j];
            }
            int curHeight = heights[j];
            while (top >= 0 && heights[st[top]] > curHeight)
            {
                int idx = st[top];
                top--;
                int left = (top < 0 ? -1 : st[top]);
                maxArea = max(maxArea, heights[idx] * (j - left - 1));
            }
            st[++top] = j;
        }
        top = -1;
    }
    return maxArea;
}

int main(){
    int rows, cols;
    cout << "Enter no. of rows: ";
    cin >> rows;
    cout << "Enter no. of cols: ";
    cin >> cols;
    vector<vector<char>> matrix(rows,vector<char>(cols));
    cout << "Enter elements: " << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> matrix[i][j];
        }
    }
    cout << "Maximal rectangle area: " << maximalRectangle(matrix);
}