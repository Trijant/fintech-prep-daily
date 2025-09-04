#include<iostream>
#include<vector>
using namespace std;

// TOPIC: recursion + DP
// Time-complexity: O(n)
// Space-complexity:O(n)

class Solution
{
private:
    vector<int> dp;
    int rob_helper(vector<int> &nums, int idx = 0)
    {
        // base case
        if (idx >= nums.size())
        {
            return 0;
        }
        // recalling from dp(dynamic programming)
        else if (dp[idx] != -1)
        {
            return dp[idx];
        }
        // getting current max_amount
        int max_amount = max(rob_helper(nums, idx + 2) + nums[idx], rob_helper(nums, idx + 1));
        // remembering calculated data
        dp[idx] = max_amount;
        return max_amount;
    }

public:
    int rob(vector<int> &nums)
    {
        // creating dp array with default value -1
        dp.resize(nums.size(), -1);
        return rob_helper(nums);
    }
};

int main(){
    int size;
    cout << "Enter size of array: ";
    cin >> size;
    cout << "Enter elements of array:" << endl;
    vector<int> nums(size);
    for (int i = 0; i < size; i++)
    {
        cin >> nums[i];
    }
    Solution s;
    cout<< "Maximum amount can be robbed: " <<s.rob(nums);
}