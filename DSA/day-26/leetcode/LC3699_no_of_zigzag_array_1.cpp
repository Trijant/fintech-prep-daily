#include <iostream>
#include <vector>
using namespace std;

// topic: prefix sum + dp

class Solution
{
public:
    int zigZagArrays(int n, int l, int r)
    {
        r = r - l + 1;
        int m = 1e9 + 7;
        vector<long long> dp(r + 1, 1);
        for (int i = 1; i < n; i++)
        {
            dp[0] = 0;
            for (int j = 1; j < r; j++)
                dp[j] = (dp[j] + dp[j - 1]) % m;
            i++;
            if (i < n)
            {
                dp[r] = 0;
                for (int j = r - 1; j > 0; j--)
                    dp[j] = (dp[j] + dp[j + 1]) % m;
            }
        }
        long long ans = 0;
        for (int i = 1; i <= r; i++)
            ans += dp[i];
        return (ans << 1) % m;
    }
};

int main(){
    int n, l, r;
    cout << "Enter n:";
    cin >> n;
    cout << "Enter l:";
    cin >> l;
    cout << "Enter r:";
    cin >> r;
    Solution s;
    cout << "Total zigzag arrays:" << s.zigZagArrays(n,l,r);
}