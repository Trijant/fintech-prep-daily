#include<iostream>
#include<vector>
using namespace std;

// topic : freq arr

class Solution
{
public:
    int sumDivisibleByK(vector<int> &nums, int k)
    {
        vector<int> freq(101, 0);
        int ts = 0;
        for (auto &n : nums)
            freq[n]++;
        for (int i = 0; i < 101; i++)
        {
            if (freq[i] && freq[i] % k == 0)
            {
                ts += (i * freq[i]);
            }
        }
        return ts;
    }
};
int main(){
    int size, k;
    cout << "Enter size: ";
    cin >> size;
    cout << "Enter k: ";
    cin >> k;
    vector<int> nums(size);
    cout << "Enter nums: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> nums[i];
    }
    Solution s;
    cout << "Sum: " << s.sumDivisibleByK(nums, k);
}