#include<iostream>
#include<vector>
using namespace std;

// topic: backtracking + bit mask
// time-complexity: O(n*n!)
// space-complexity: O(n*n!)

class Solution
{
private:
    void helper(vector<int> &nums, int idx, vector<vector<int>> &ans)
    {
        // base case
        if (idx == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        // describe choices
        int choosen = 0;
        for (int i = idx; i < nums.size(); i++)
        {
            if (choosen & (1 << (nums[i] + 10)))
            { // pruning
                continue;
            }
            swap(nums[idx], nums[i]);   // make a choice
            helper(nums, idx + 1, ans); // explore recursions
            swap(nums[idx], nums[i]);   // undo choice
            choosen |= 1 << (nums[i] + 10);
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> ans;

        helper(nums, 0, ans);
        return ans;
    }
};

int main(){
    int size;
    cout << "Enter size of array: ";
    cin >> size;
    cout << "Enter elements of array: " << endl;
    vector<int> nums(size);
    for (int i = 0; i < size; i++)
    {
        cin >> nums[i];
    }
    Solution s;
    vector<vector<int>> permutations = s.permuteUnique(nums);
    cout << "All unique permutations: " << endl;
    for (int i = 0; i < permutations.size(); i++)
    {
        for (int j = 0; j < permutations[i].size(); j++)
        {
            cout << permutations[i][j]<<" ";
        }
        cout << endl;
    }
    
}