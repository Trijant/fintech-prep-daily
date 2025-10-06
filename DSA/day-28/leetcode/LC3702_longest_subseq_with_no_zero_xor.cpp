#include<iostream>
#include<vector>
using namespace std;

// topic: xor

class Solution
{
public:
    int longestSubsequence(vector<int> &nums)
    {
        int x = 0;
        bool isNonZero = false;
        for (auto &num : nums)
        {
            x ^= num;
            isNonZero |= num;
        }
        if (!isNonZero)
            return 0;
        return (x ? nums.size() : nums.size() - 1);
    }
};

int main(){
    int size;
    cout << "Enter size: ";
    cin >> size;
    vector<int> nums(size);
    cout << "Enter elements:" << endl;
    for (int i = 0; i < size;i++){
        cin >> nums[i];
    }
    Solution s;
    cout << "Length: " << s.longestSubsequence(nums);
}