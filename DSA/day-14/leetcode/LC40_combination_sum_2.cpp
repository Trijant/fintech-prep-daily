#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// topic: backtracking
// time-complexity: O(n*2^n)
// space-complexity: O(n*2^n)

class Solution
{
private:
    void helper(vector<int> &candidates, int target, int idx, vector<int> &path, vector<vector<int>> &ans)
    {
        // base case
        if (target == 0)
        {
            ans.push_back(path);
            return;
        }

        // describe choices
        for (int i = idx; i < candidates.size(); i++)
        {
            // pruning
            if (candidates[i] > target)
            {
                break;
            }
            else if (i > idx && candidates[i] == candidates[i - 1])
            {
                continue;
            }

            // make a choice
            path.push_back(candidates[i]);

            // explore recursions
            helper(candidates, target - candidates[i], i + 1, path, ans);

            // undo choice
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> path;
        path.reserve(candidates.size());
        helper(candidates, target, 0, path, ans);
        return ans;
    }
};

int main(){
    int size,target;
    cout << "Enter size of array: ";
    cin >> size;
    cout << "Enter elements of array:" << endl;
    vector<int> candidates(size);
    for (int i = 0; i < size; i++)
    {
        cin >> candidates[i];
    }
    cout << "Enter target: ";
    cin >> target;
    Solution s;
    vector<vector<int>> ans = s.combinationSum2(candidates, target);
    cout << "All possible combinations: " << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    
}