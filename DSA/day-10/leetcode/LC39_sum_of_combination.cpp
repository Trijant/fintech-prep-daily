#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// topic: backtracking + sorting
// time-complexity: O(n^target), n=size of candidates
// space-complexity: O(target*(n^target))

class Solution
{
protected:
    void helper(vector<int> &candidates, int target, int idx, vector<vector<int>> &ans, vector<int> &path)
    {
        // base case
        if (target == 0)
        {
            ans.push_back(path);
            return;
        }

        // describing choices
        for (int i = idx; i < candidates.size(); i++)
        {
            // pruning
            if (candidates[i] > target)
            {
                break;
            }
            path.push_back(candidates[i]);                            // making choice
            helper(candidates, target - candidates[i], i, ans, path); // exploring recursions
            path.pop_back();                                          // undo choice
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        // sorting for better pruning
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> path;
        path.reserve(target);
        helper(candidates, target, 0, ans, path);
        return ans;
    }
};

int main(){
    int size, target;
    cout << "Enter size of arr:";
    cin >> size;
    vector<int> candidates(size);
    for (int i = 0; i < size; i++)
    {
        cin >> candidates[i];
    }
    cout << "Enter target: ";
    cin >> target;
    Solution s;
    vector<vector<int>> ans = s.combinationSum(candidates, target);
    cout << "Combinations: " << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
    
}