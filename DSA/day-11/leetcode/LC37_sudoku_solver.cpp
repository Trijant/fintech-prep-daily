#include<iostream>
#include<vector>
using namespace std;

// Topic: backtracking
// time-complexity: O(9^n); n=no. of empty cells
// space-complexity: O(1)

class Solution
{
private:
    bool canPlace(int row, int col, int target, bool rowUsed[9][10], bool colUsed[9][10], bool boxUsed[9][10])
    {
        if (rowUsed[row][target])
        {
            return false;
        }
        else if (colUsed[col][target])
        {
            return false;
        }
        else if (boxUsed[(row / 3) * 3 + col / 3][target])
        {
            return false;
        }
        return true;
    }
    bool helper(vector<vector<char>> &board, int row, int col, bool rowUsed[9][10], bool colUsed[9][10], bool boxUsed[9][10])
    {
        // base case
        if (col >= 9)
        {
            col = 0;
            row++;
        }
        if (row >= 9)
        {
            return true;
        }
        if (board[row][col] != '.')
        {
            return helper(board, row, col + 1, rowUsed, colUsed, boxUsed);
        }
        // describing choices
        for (int i = 1; i <= 9; i++)
        {
            // pruning
            if (!canPlace(row, col, i, rowUsed, colUsed, boxUsed))
            {
                continue;
            }
            // making choice
            board[row][col] = '0' + i;
            rowUsed[row][i] = true;
            colUsed[col][i] = true;
            boxUsed[(row / 3) * 3 + col / 3][i] = true;
            // exploring recursions
            if (helper(board, row, col + 1, rowUsed, colUsed, boxUsed))
            {
                return true;
            }
            // undo choice
            board[row][col] = '.';
            rowUsed[row][i] = false;
            colUsed[col][i] = false;
            boxUsed[(row / 3) * 3 + col / 3][i] = false;
        }
        return false;
    }

public:
    void solveSudoku(vector<vector<char>> &board)
    {
        // lookup array
        bool rowUsed[9][10]={}, colUsed[9][10]={false}, boxUsed[9][10]={false};
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    int num = board[i][j] - '0';
                    rowUsed[i][num] = true;
                    colUsed[j][num] = true;
                    boxUsed[(i / 3) * 3 + j / 3][num] = true;
                }
            }
        }
        bool isSolvable=helper(board, 0, 0, rowUsed, colUsed, boxUsed);
        if (!isSolvable)
        {
            cout << "Given sudoku is not solvable!"<<endl;
        }
        
    }
};

int main(){
    vector<vector<char>> board(9, vector<char>(9));
    cout << "Enter sudoku elements: " << endl;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> board[i][j];
        }
    }
    cout << "Unsolved sudoku: " << endl;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    Solution s;
    s.solveSudoku(board);
    cout << "Solved sudoku: " << endl;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    
}