#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// topic: dp(memoization)

class Solution
{
public:
    long long maximumTotalDamage(vector<int> &power)
    {
        sort(power.begin(), power.end());
        int size = power.size();
        long long prevSum1 = 0, prevSum2 = 0, prevSum3 = 0;
        int prevNum1 = 0, prevNum2 = -1, prevNum3 = -2;
        for (int i = 0; i < size;)
        {
            int p = power[i];
            long long curSum = power[i];
            int target = p - 3;
            long long prevSum = 0;
            if (prevNum1 <= target)
                prevSum = prevSum1;
            else if (prevNum2 <= target)
                prevSum = prevSum2;
            else
                prevSum = prevSum3;
            prevNum3 = prevNum2;
            prevNum2 = prevNum1;
            prevNum1 = p;
            prevSum3 = prevSum2;
            prevSum2 = prevSum1;

            while (++i < size && power[i] == p)
                curSum += p;
            prevSum1 = max(prevSum1, prevSum + curSum);
        }
        return prevSum1;
    }
};

int main(){
    int size;
    cout << "Enter size: ";
    cin >> size;
    vector<int> power(size);
    cout << "Enter powers: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> power[i];
    }
    Solution s;
    cout << "Total damage: " << s.maximumTotalDamage(power) << endl;
}