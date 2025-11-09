#include<bits/stdc++.h>
using namespace std;

// topic: dp + maths

class Solution
{
public:
    int countCoprime(vector<vector<int>> &mat)
    {
        const int MOD = 1e9 + 7;
        vector<long long> prev(151, 0), curr(151, 0);

        // initialize for first row
        for (int x : mat[0])
            prev[x]++;

        // iterate through each next row
        for (int i = 1; i < mat.size(); ++i)
        {
            fill(curr.begin(), curr.end(), 0);
            for (int n : mat[i])
            {
                for (int g = 1; g <= 150; ++g)
                {
                    if (prev[g] == 0)
                        continue;
                    int newG = std::gcd(g, n);
                    curr[newG] = (curr[newG] + prev[g]) % MOD;
                }
            }
            swap(prev, curr);
        }

        return (int)prev[1]; // count of ways where gcd = 1
    }
};

int main(){
    int n, m;
    cout << "Enter m: ";
    cin>>m;
    cout << "Enter n: ";
    cin >> n;
    vector<vector<int>> mat(m, vector<int>(n));
    cout << "Enter elements: " << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }
    Solution s;
    cout << "Total ways: " << s.countCoprime(mat) << endl;
}