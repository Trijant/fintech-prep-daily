#include<bits/stdc++.h>
using namespace std;

// topic: array + set (brute force)

class Solution
{
public:
    int longestBalanced(vector<int> &nums)
    {
        int m = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            unordered_set<int> even;
            unordered_set<int> odd;
            for (int j = i; j < nums.size(); j++)
            {
                if (nums[j] & 1)
                    odd.insert(nums[j]);
                else
                    even.insert(nums[j]);
                if (even.size() == odd.size())
                    m = max(m, j - i + 1);
            }
        }
        return m;
    }
};

int main(){
    int size;
    cout<<"Enter size: ";
    cin>>size;
    vector<int>nums(size);
    cout << "Enter nums: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> nums[i];
    }
    Solution s;
    cout << "longest balanced subarray length: " << s.longestBalanced(nums) << endl;
}