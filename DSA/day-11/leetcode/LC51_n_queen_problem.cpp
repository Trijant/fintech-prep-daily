#include<iostream>
#include<vector>
using namespace std;

// topic: backtracking + bitmasking
// time-complexity: O(2^(n^2))
// space-complexity: O(n!)

class Solution
{
private:
    void makeCurMask(int row, int col, int n, int &curRowMask, int &curColMask,
                     int &curLeftToRightDiagonalMask,
                     int &curRightToLeftDiagonalMask)
    {
        // making current bitmasks
        curRowMask = 1 << (row), curColMask = 1 << (col),
        curLeftToRightDiagonalMask = 1 << (row - col + n - 1),
        curRightToLeftDiagonalMask = 1 << (row + col);
    }
    bool canPlace(int &curRowMask, int &curColMask,
                  int &curLeftToRightDiagonalMask,
                  int &curRightToLeftDiagonalMask, int &rowMask, int &colMask,
                  int &leftToRightDiagonalMask, int &rightToLeftDiagonalMask)
    {
        // current masks has only one bit '1' if our original masks has same bit
        // '1' then we can't place queen
        if (curRowMask & rowMask || curColMask & colMask ||
            curLeftToRightDiagonalMask & leftToRightDiagonalMask ||
            curRightToLeftDiagonalMask & rightToLeftDiagonalMask)
        {
            return false;
        }

        return true;
    }
    void makeChoice(int &curRowMask, int &curColMask,
                    int &curLeftToRightDiagonalMask,
                    int &curRightToLeftDiagonalMask, int &rowMask, int &colMask,
                    int &leftToRightDiagonalMask,
                    int &rightToLeftDiagonalMask)
    {
        // current masks has only one bit '1' by doing &(AND) we can update our
        // masks and flip current choice position to '1'
        rowMask |= curRowMask;
        colMask |= curColMask;
        leftToRightDiagonalMask |= curLeftToRightDiagonalMask;
        rightToLeftDiagonalMask |= curRightToLeftDiagonalMask;
    }
    void undoChoice(int &curRowMask, int &curColMask,
                    int &curLeftToRightDiagonalMask,
                    int &curRightToLeftDiagonalMask, int &rowMask, int &colMask,
                    int &leftToRightDiagonalMask,
                    int &rightToLeftDiagonalMask)
    {
        // only at 1 place bit will be same which is our choice place by doing
        // ^(xor)we can flip that to '0'
        rowMask ^= curRowMask;
        colMask ^= curColMask;
        leftToRightDiagonalMask ^= curLeftToRightDiagonalMask;
        rightToLeftDiagonalMask ^= curRightToLeftDiagonalMask;
    }
    void helper(vector<vector<string>> &ans, vector<string> &path, int row,
                int col, int n, int &rowMask, int &colMask,
                int &leftToRightDiagonalMask, int &rightToLeftDiagonalMask)
    {
        // base case
        if (row >= n)
        {
            ans.push_back(path);
            return;
        }
        else if (col >= n)
        {
            return;
        }

        // making current bitmasks
        int curRowMask, curColMask, curLeftToRightDiagonalMask,
            curRightToLeftDiagonalMask;
        makeCurMask(row, col, n, curRowMask, curColMask,
                    curLeftToRightDiagonalMask, curRightToLeftDiagonalMask);

        // describing choices

        // choice -1
        if (canPlace(curRowMask, curColMask, curLeftToRightDiagonalMask,
                     curRightToLeftDiagonalMask, rowMask, colMask,
                     leftToRightDiagonalMask,
                     rightToLeftDiagonalMask))
        { // pruning

            // making choice
            path[row][col] = 'Q';
            makeChoice(curRowMask, curColMask, curLeftToRightDiagonalMask,
                       curRightToLeftDiagonalMask, rowMask, colMask,
                       leftToRightDiagonalMask, rightToLeftDiagonalMask);

            // exploring recursions
            helper(ans, path, row + 1, 0, n, rowMask, colMask,
                   leftToRightDiagonalMask,
                   rightToLeftDiagonalMask);

            // undo choice
            path[row][col] = '.';
            undoChoice(curRowMask, curColMask, curLeftToRightDiagonalMask,
                       curRightToLeftDiagonalMask, rowMask, colMask,
                       leftToRightDiagonalMask, rightToLeftDiagonalMask);
        }

        // choice -2
        helper(ans, path, row, col + 1, n, rowMask, colMask,
               leftToRightDiagonalMask, rightToLeftDiagonalMask);
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> path(n);
        int rowMask = 0, colMask = 0, leftToRightDiagonalMask = 0,
            rightToLeftDiagonalMask = 0;
        string s = string(n, '.');
        for (int i = 0; i < n; i++)
        {
            path[i] = s;
        }
        helper(ans, path, 0, 0, n, rowMask, colMask, leftToRightDiagonalMask,
               rightToLeftDiagonalMask);
        return ans;
    }
};

int main(){
    int n;
    cout << "Enter n:";
    cin >> n;
    Solution s;
    vector<vector<string>> ans = s.solveNQueens(n);
    cout << "All the possible solutions are: " << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j]<<endl;
        }
        cout << endl<<endl;
    }
    
}