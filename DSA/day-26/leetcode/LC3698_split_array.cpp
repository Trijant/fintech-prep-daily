#include<iostream>
#include<vector>
using namespace std;

// topic: array

class Solution
{
public:
    long long splitArray(vector<int> &nums)
    {
        int size = nums.size();
        long long diff = nums[0];
        int i = 1;
        for (; i < size && nums[i] > nums[i - 1]; i++)
        {
            diff += nums[i];
        }
        int check = i - 1;
        if (i < size)
            diff -= nums[i++];
        for (; i < size && nums[i] < nums[i - 1]; i++)
        {
            diff -= nums[i];
        }
        if (i != size)
            return -1;
        if (check < size - 1 && nums[check] <= nums[check + 1])
            return abs(diff);
        long long newDiff = diff - (nums[check] << 1);
        return min(abs(diff), abs(newDiff));
    }
};

int main(){
    int size;
    cout << "Enter size :";
    cin>>size;
    cout << "Enter elements: ";
    vector<int> nums(size);
    for (int  i = 0; i < size; i++)
    {
        cin >> nums[i];
    }
    Solution s;
    cout << "Min diff after split: " << s.splitArray(nums);
}