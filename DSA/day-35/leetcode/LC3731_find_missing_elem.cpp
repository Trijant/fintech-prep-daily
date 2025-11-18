#include<bits/stdc++.h>
using namespace std;

// topic: freq array

class Solution
{
public:
    vector<int> findMissingElements(vector<int> &nums)
    {
        vector<bool> freq(101, false);
        int mn = INT_MAX, mx = INT_MIN;
        for (auto &n : nums)
        {
            mn = min(mn, n);
            mx = max(mx, n);
            freq[n] = true;
        }
        vector<int> ans;
        ans.reserve(100);
        for (int i = mn; i < mx; i++)
            if (!freq[i])
                ans.push_back(i);
        return ans;
    }
};

int main(){
    int size;
    cout << "Enter size: ";
    cin>>size;
    vector<int>nums(size);
    cout<<"Enter elements: "<<endl;
    for (int i = 0; i < size; i++)
    {
        cin >> nums[i];
    }
    Solution s;
    vector<int> ans = s.findMissingElements(nums);
    cout<<"Missing elem: ";
    for (auto &n:ans)
        cout << n << " ";
    cout << endl;
}