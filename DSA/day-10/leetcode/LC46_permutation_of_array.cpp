#include<iostream>
#include<vector>
using namespace std;

// Topic: backtracking + recursion
// Time-complexity: O(n&n!)
// Space-complexity: O(n&n!)

class Solution
{
protected:
    void helper(vector<int> &nums, vector<vector<int>> &ans, int index = 0)
    {
        // Goal
        if (index == nums.size())
        {
            ans.push_back(nums);
            return;
        }

        // descibing choices
        for (int i = index; i < nums.size(); i++)
        {
            swap(nums[i], nums[index]);   // make choice
            helper(nums, ans, index + 1); // explore
            swap(nums[i], nums[index]);   // undo choice
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        helper(nums, ans);
        return ans;
    }
};

int main(){
    int size;
    cout << "Enter size of array:";
    cin >> size;
    cout << "Enter elements of array: " << endl;
    vector<int> nums(size);
    for (int i = 0; i < size; i++)
    {
        cin >> nums[i];
    }
    Solution s;
    vector<vector<int>> permutations = s.permute(nums);
    cout << "All permutations are: " << endl;
    for (int i = 0; i < permutations.size(); i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << permutations[i][j] << " ";
        }
        cout << endl;
    }
    
}