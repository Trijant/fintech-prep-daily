#include<bits/stdc++.h>
using namespace std;

// topic: maths + array

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans=0;
        for(auto &n:nums) ans+=(n%3?1:0);
        return ans;
    }
};

int main(){
    int size;
    cout<<"Enter size: ";
    cin>>size;
    vector<int>nums(size);
    cout << "Enter elems: " << endl;
    for(int i=0;i<size;i++){
        cin >> nums[i];
    }
    Solution s;
    cout << "Ans: " << s.minimumOperations(nums) << endl;
}