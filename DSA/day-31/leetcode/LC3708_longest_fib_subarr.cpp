#include<bits/stdc++.h>
using namespace std;

// topic: dp + fibonacci
class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int c = 2;
        int m = 0;
        for (int i = 2; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1] + nums[i - 2])
            {
                c++;
            }
            else
            {
                m = max(m, c);
                c = 2;
            }
        }
        m = max(m, c);
        return m;
    }
};

int main(){
    int size;
    cout << "Enter size: ";
    cin>>size;
    vector<int> nums(size);
    cout << "Enter nums: "<<endl;
    for (int i = 0; i < size; i++)
    {
        cin >> nums[i];
    }
    Solution s;
    cout << "ans: " << s.longestSubarray(nums) << endl;
}