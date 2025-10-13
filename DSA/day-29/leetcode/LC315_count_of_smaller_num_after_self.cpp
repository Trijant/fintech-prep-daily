#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// topic: fenweek tree

class Solution
{
private:
    vector<int> tree;
    int size;
    void insert(int idx)
    {
        while (idx < size)
        {
            tree[idx]++;
            idx += (idx & -idx);
        }
    }
    int query(int idx)
    {
        int count = 0;
        while (idx > 0)
        {
            count += tree[idx];
            idx -= (idx & -idx);
        }
        return count;
    }

public:
    vector<int> countSmaller(vector<int> &nums)
    {
        vector<int> compressedNums = nums;
        sort(compressedNums.begin(), compressedNums.end());
        compressedNums.erase(unique(compressedNums.begin(), compressedNums.end()), compressedNums.end());
        auto rankOf = [&](int num)
        {
            return lower_bound(compressedNums.begin(), compressedNums.end(), num) - compressedNums.begin();
        };

        size = compressedNums.size();
        tree.assign(size, 0);
        vector<int> ans(nums.size());
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            int idx = rankOf(nums[i]);
            ans[i] = query(idx);
            insert(idx + 1);
        }
        return ans;
    }
};

int main(){
    int size;
    cout << "Enter size: ";
    cin >> size;
    vector<int> nums(size);
    cout << "Enter elements: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> nums[i];
    }
    Solution s;
    vector<int> ans = s.countSmaller(nums);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}