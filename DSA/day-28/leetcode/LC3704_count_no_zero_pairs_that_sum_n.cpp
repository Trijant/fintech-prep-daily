#include<iostream>
#include<vector>
using namespace std;

// topic: dp + maths

class Solution
{
private:
    int countDigits(long long n)
    {
        int count = 0;
        while (n)
        {
            count++;
            n /= 10;
        }
        return count;
    }

public:
    long long countNoZeroPairs(long long n)
    {
        int digits = countDigits(n);
        vector<vector<long long>> dp(digits + 1, vector<long long>(2));
        dp[0][0] = 1;
        dp[0][1] = 0;
        long long ans = 0;
        long long carryInZeroDigit = 0;
        long long withoutCarryInZeroDigit = 0;
        for (int pos = 1; pos <= digits; pos++)
        {
            int digit = n % 10;
            n /= 10;
            long long prevPairsWithCarry = dp[pos - 1][1];
            long long prevPairsWithoutCarry = dp[pos - 1][0];
            if (pos > 1)
            {
                if (digit)
                {
                    withoutCarryInZeroDigit += (prevPairsWithoutCarry << 1);
                }
                else
                {
                    withoutCarryInZeroDigit = 0;
                }
                if (digit == 0)
                {
                    carryInZeroDigit += (prevPairsWithCarry << 1);
                }
                else if (digit > 1)
                {
                    withoutCarryInZeroDigit += (prevPairsWithCarry << 1);
                    withoutCarryInZeroDigit += carryInZeroDigit;
                    carryInZeroDigit = 0;
                }
                else if (!n)
                {
                    carryInZeroDigit += prevPairsWithCarry;
                }
                else
                {
                    carryInZeroDigit = 0;
                }
            }

            long long pairsWithCarry = 0;
            long long pairsWithoutCarry = 0;
            for (int i = 1; i <= 9; i++)
            {
                int j = i > digit ? (digit + 10) - i : digit - i;
                if (!j)
                    continue;
                if (i + j > 9)
                    pairsWithCarry += prevPairsWithoutCarry;
                else
                    pairsWithoutCarry += prevPairsWithoutCarry;
            }

            digit -= 1;
            for (int i = 1; i <= 9; i++)
            {
                int j = i > digit ? (digit + 10) - i : digit - i;
                if (!j)
                    continue;
                if (i + j >= 9)
                    pairsWithCarry += prevPairsWithCarry;
                else
                    pairsWithoutCarry += prevPairsWithCarry;
            }
            dp[pos][0] = pairsWithoutCarry;
            dp[pos][1] = pairsWithCarry;
        }
        ans += carryInZeroDigit + withoutCarryInZeroDigit;
        ans += dp.back()[0];
        return ans;
    }
};

int main(){
    int n;
    cout << "Enter n: ";
    cin >> n;
    Solution s;
    cout << "No zero pairs count: " << s.countNoZeroPairs(n);
}