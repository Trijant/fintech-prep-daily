#include<bits/stdc++.h>
using namespace std;

// topic: pref sum + pattern find

class Solution
{
public:
    int maxBalancedSubarray(vector<int> &nums)
    {
        int size = nums.size();
        unordered_map<long long, int> mp;
        mp.reserve((size + 1) << 1);
        mp[0] = -1;
        int prefxor = 0, ans = 0, diff = 0;
        for (int i = 0; i < size; i++)
        {
            if (nums[i] & 1)
                diff++;
            else
                diff--;
            prefxor ^= nums[i];
            long long code = ((unsigned long long)diff << 32) | prefxor;
            if (mp.count(code))
            {
                ans = max(ans, i - mp[code]);
            }
            else
                mp[code] = i;
        }
        return ans;
    }
};

int main(){
    int size;
    cout<<"Enter size: ";
    cin>>size;
    vector<int>nums(size);
    cout<<"Enter elements: "<<endl;
    for(int i=0;i<size;i++){
        cin >> nums[i];
    }
    Solution s;
    cout << "Ans: " << s.maxBalancedSubarray(nums) << endl;
}