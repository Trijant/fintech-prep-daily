#include<bits/stdc++.h>
using namespace std;

// topic: prefsum + array + map

class Solution
{
public:
    long long numGoodSubarrays(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        mp.reserve(200000);
        unordered_map<int, int> mp2;
        mp2.reserve(200000);
        int mod = nums[0] % k;
        mp[mod]++;
        mp2[mod]++;

        long long count = 0;
        mp[0]++;
        if (mod == 0)
            count++;
        long long prefsum = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            prefsum += nums[i];
            int curmod = prefsum % k;
            if (nums[i] == nums[i - 1])
            {
                count += mp[curmod] - mp2[curmod];
            }
            else
            {
                count += mp[curmod];
                mp2 = unordered_map<int, int>();
            }
            mp2[curmod]++;
            mp[curmod]++;
        }
        return count;
    }
};

int main(){
    int size, k;
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
    cout << "Count: " << s.numGoodSubarrays(nums, k) << endl;
}