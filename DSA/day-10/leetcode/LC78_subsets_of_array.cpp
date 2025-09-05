#include<iostream>
#include<vector>
using namespace std;

// Topic: backtracking + recursion
// Time-complexity: O(2^n)
// Space-complexity: O(n*2^n)

class Solution
{
private:
    void helper(vector<int> &nums, int idx, vector<int> &path, vector<vector<int>> &ans)
    {
        // base case;
        if (idx >= nums.size())
        {
            ans.push_back(path);
            return;
        }
        // 2 choices
        path.push_back(nums[idx]);        // making 1st choice
        helper(nums, idx + 1, path, ans); // exploring
        path.pop_back();                  // undo choice
        helper(nums, idx + 1, path, ans); // choice 2
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> path = {};
        helper(nums, 0, path, ans);
        return ans;
    }
};

int main(){
    int size;
    cout << "Enter size: ";
    cin >> size;
    cout << "Enter elements: " << endl;
    vector<int> nums(size);
    for (int i = 0; i < size; i++)
    {
        cin >> nums[i];
    }
    Solution s;
    vector<vector<int>> ans = s.subsets(nums);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    
}