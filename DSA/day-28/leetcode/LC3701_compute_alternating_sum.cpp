#include<iostream>
#include<vector>
using namespace std;

// topic: maths

class Solution
{
public:
    int alternatingSum(vector<int> &nums)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i & 1)
                sum -= nums[i];
            else
                sum += nums[i];
        }
        return sum;
    }
};

int main(){
    int size;
    cout << "Enter size: ";
    cin >> size;
    cout << "Enter elements:" << endl;
    vector<int> nums(size);
    for (int  i = 0; i < size; i++)
    {
        cin >> nums[i];
    }
    Solution s;
    cout << "Sum is " << s.alternatingSum(nums)<<endl;
}