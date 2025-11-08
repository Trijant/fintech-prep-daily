#include <bits/stdc++.h>
using namespace std;

// topic: maths + array

class Solution
{
public:
    long long minOperations(vector<int> &nums1, vector<int> &nums2)
    {
        long long ans = 0;
        int minDiff = INT_MAX;
        int size = nums1.size();
        int last = nums2[size];
        for (int i = 0; i < size; i++)
        {
            ans += abs(nums1[i] - nums2[i]);
            int mn, mx;
            if (nums1[i] < nums2[i])
            {
                mn = nums1[i];
                mx = nums2[i];
            }
            else
            {
                mx = nums1[i];
                mn = nums2[i];
            }

            if (last >= mn && last <= mx)
                minDiff = 0;
            else if (last > mx)
                minDiff = min(minDiff, last - mx);
            else
                minDiff = min(minDiff, mn - last);
        }
        return ans + minDiff + 1;
    }
};

int main()
{
    int size1, size2;
    cout << "Enter size: ";
    cin >> size1;
    size2 = size1 + 1;
    vector<int> nums1(size1);
    vector<int> nums2(size2);
    cout << "Enter elements of nums1: " << endl;
    for (int i = 0; i < size1; i++)
    {
        cin >> nums1[i];
    }
    cout << "Enter elements of nums2: " << endl;
    for (int i = 0; i < size2; i++)
    {
        cin >> nums2[i];
    }
    Solution s;
    cout << "Operations: " << s.minOperations(nums1, nums2) << endl;
}