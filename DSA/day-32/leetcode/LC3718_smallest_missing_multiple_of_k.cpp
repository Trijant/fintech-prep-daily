#include<bits/stdc++.h>
using namespace std;

// topic: maths + freq array

class Solution
{
public:
    int missingMultiple(vector<int> &nums, int k)
    {
        vector<bool> f(101, false);
        for (auto &n : nums)
        {
            f[n] = true;
        }
        for (int i = k;; i += k)
        {
            if (i > 100 || !f[i])
                return i;
        }
        return -1;
    }
};

int main(){
    int size,k;
    cout << "Enter size: ";
    cin >> size;
    cout << "Enter k: ";
    cin>>k;
    vector<int> nums(size);
    for (int i = 0; i < size; i++)
    {
        cin >> nums[i];
    }
    Solution s;
    cout << "Smallest missing multiple: " << s.missingMultiple(nums, k) << endl;
}