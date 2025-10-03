#include<iostream>
#include<vector>
using namespace std;

// topic: sliding window / dp

class Solution
{
public:
    int climbStairs(int n, vector<int> &costs)
    {
        vector<int> dp(n, 0);
        int prev1 = 0, prev2 = 0, prev3 = 0;
        for (int i = 0; i < n; i++)
        {
            int cur = min(prev1 + 1, min(prev2 + 4, prev3 + 9));
            cur += costs[i];
            prev3 = prev2;
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }
};

int main(){
    int n;
    cout << "Enter n: ";
    cin>>n;
    vector<int> costs(n);
    cout << "Enter costs: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> costs[i];
    }
    Solution s;
    cout << "Total min cost: " << s.climbStairs(n, costs);
}