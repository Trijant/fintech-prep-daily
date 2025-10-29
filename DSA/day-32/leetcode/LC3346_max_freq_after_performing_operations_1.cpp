#include<bits/stdc++.h>
using namespace std;

// topic: sweep line + overlaping intervals

class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k, int numOperations)
    {
        int maxVal = *max_element(nums.begin(), nums.end()) + 1;
        vector<int> freq(maxVal + 1, 0), sweep(maxVal + 1, 0);

        for (auto &n : nums)
        {
            freq[n]++;
            sweep[max(n - k, 0)] += 1;
            sweep[min(n + k + 1, maxVal)] -= 1;
        }
        int count = 0, maxFreq = 0;
        for (int i = 0; i <= maxVal; i++)
        {
            count += sweep[i];
            maxFreq = max(maxFreq, min(count, freq[i] + numOperations));
        }
        return maxFreq;
    }
};

int main(){
    int size, k, n;
    cout << "Enter size: ";
    cin >> size;
    cout << "Enter k: ";
    cin >> k;
    cout << "Enter n: ";
    cin >> n;
    vector<int> nums(size);
    cout << "Enter nums: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> nums[i];
    }
    Solution s;
    cout << "Enter max freq: " << s.maxFrequency(nums, k, n) << endl;
}