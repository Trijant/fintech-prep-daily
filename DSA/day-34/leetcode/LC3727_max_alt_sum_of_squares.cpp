#include<bits/stdc++.h>
using namespace std;

// topic: array + maths

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int size=nums.size();
        for(int i=0;i<size;i++)if(nums[i]<0)nums[i]=-nums[i];
        sort(nums.begin(),nums.end());
        long long ans=0;
        int half=size>>1;
        for(int i=half;i<size;i++) ans+=(nums[i]*nums[i]);
        for(int i=0;i<half;i++)ans-=(nums[i]*nums[i]);
        return ans;
    }
};

int main(){
    int size;
    cout << "Enter size: ";
    cin >> size;
    cout<<"Enter elements : "<<endl;
    vector<int>nums(size);
    for (int i = 0; i < size; i++)
    {
        cin >> nums[i];
    }
    Solution s;
    cout << "Max sum: " << s.maxAlternatingSum(nums) << endl;
}