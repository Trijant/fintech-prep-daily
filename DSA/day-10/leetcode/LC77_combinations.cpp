#include<iostream>
#include<vector>
using namespace std;

class Solution
{
private:
    void helper(int n, int k, vector<vector<int>> &ans, vector<int> &path, int index)
    {
        // base case
        if (!k)
        {
            ans.push_back(path);
            return;
        }
        // describing choices
        for (int i = index; i <= n - k + 1; i++)
        {
            // making choice
            path.push_back(i);
            // exploring recursions
            helper(n, k - 1, ans, path, i + 1);
            // undo choice
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> ans;
        vector<int> path;
        path.reserve(k);
        helper(n, k, ans, path, 1);
        return ans;
    }
};

int main(){
    int n, k;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter k:";
    cin >> k;
    Solution s;
    vector<vector<int>> ans = s.combine(n, k);
    cout << "Combinations: " << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < k; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    
}