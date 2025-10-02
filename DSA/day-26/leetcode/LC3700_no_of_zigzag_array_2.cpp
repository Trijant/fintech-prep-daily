#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// topic: matrix + prefix sum

class Matrix
{
private:
public:
    int rowSize;
    int colSize;
    vector<vector<int>> mat;
    Matrix(int row, int col, int val = 0)
    {
        mat.assign(row, vector<int>(col, val));
        rowSize = row;
        colSize = col;
    }
    Matrix operator*(const Matrix &m2) const
    {
        Matrix ans(rowSize, m2.colSize);
        for (int i = 0; i < ans.rowSize; i++)
        {
            for (int j = 0; j < ans.colSize; j++)
            {
                int sum = 0;
                for (int k = 0; k < colSize; k++)
                {
                    sum = (sum + 1LL * mat[i][k] * m2.mat[k][j]) % 1000000007;
                }
                ans.mat[i][j] = sum;
            }
        }
        return move(ans);
    }
    Matrix operator^(int num) const
    {
        Matrix ans(rowSize, colSize);
        for (int i = 0; i < min(rowSize, colSize); i++)
            ans.mat[i][i] = 1;
        Matrix base = *this;
        while (num)
        {
            if (num & 1)
                ans = ans * base;
            base = base * base;
            num >>= 1;
        }
        return move(ans);
    }
    int sum()
    {
        int ans = 0;
        for (int i = 0; i < rowSize; i++)
        {
            for (int j = 0; j < colSize; j++)
            {
                ans = (ans + mat[i][j]) % 1000000007;
            }
        }
        return ans;
    }
};

class Solution
{
public:
    int zigZagArrays(int n, int l, int r)
    {
        r = r - l + 1;
        Matrix base(r, 1, 1); // base matrix

        // transition matrix
        Matrix mul(r, r);
        for (int i = 1; i < r; i++)
        {
            for (int j = r - i; j < r; j++)
            {
                mul.mat[i][j] = 1;
            }
        }

        base = ((mul ^ (n - 1)) * base);
        return (base.sum() << 1) % 1000000007;
    }
};

int main()
{
    int n, l, r;
    cout << "Enter n:";
    cin >> n;
    cout << "Enter l:";
    cin >> l;
    cout << "Enter r:";
    cin >> r;
    Solution s;
    cout << "Total zigzag arrays:" << s.zigZagArrays(n, l, r);
}