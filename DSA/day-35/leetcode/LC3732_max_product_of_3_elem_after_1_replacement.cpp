#include<bits/stdc++.h>
using namespace std;

// topic: min Heap + maths

class Solution
{
public:
    long long maxProduct(vector<int> &nums)
    {
        long long mul = 1e5;
        long long mx = 0;
        long long secondMx = 0;
        for (auto &n : nums)
        {
            if (abs(n) > mx)
            {
                secondMx = mx;
                mx = abs(n);
            }
            else if (abs(n) > secondMx)
            {
                secondMx = abs(n);
            }
        }
        return mx * mul * secondMx;
    }
};

int main(){
    int size;
    cout<<"Enter size: ";
    cin>>size;
    cout<<"Enter elements: "<<endl;
    vector<int>nums(size);
    for (int i = 0; i < size; i++)
    {
        cin >> nums[i];
    }
    Solution s;
    cout << "Max product: " << s.maxProduct(nums) << endl;
}