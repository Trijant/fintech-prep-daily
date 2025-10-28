#include<bits/stdc++.h>
using namespace std;

// topic: minHeap

using ll=long long;
class Solution {
private:
    ll cordExt=0xFFFFFFFF;
    ll encode(int val,int i,int j){
        return ((ll)val<<32) | ((ll)i<<10)|j;
    }
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<ll,vector<ll>,greater<ll>>pq;
        int curMax=INT_MIN;
        for(int i=0;i<nums.size();i++){
            pq.push(encode(nums[i][0],i,0));
            curMax=max(curMax,nums[i][0]);
        }
        int rangeStart=INT_MIN;
        int rangeEnd=INT_MAX;
        while(true){
            ll code=pq.top();
            pq.pop();
            int curMin=code>>32;
            code&=cordExt;
            int i=code>>10;
            int j=code&1023;
            if(((ll)curMax-curMin)<((ll)rangeEnd-rangeStart)){
                rangeEnd=curMax;
                rangeStart=curMin;
            }
            j++;
            if(j<nums[i].size()){
                pq.push(encode(nums[i][j],i,j));
                curMax=max(curMax,nums[i][j]);
            }
            else{
                break;
            }
        }
        return {rangeStart,rangeEnd};
    }
};

int main(){
    int osize;
    cout<<"Enter osize: ";
    cin>>osize;
    vector<vector<int>> nums;
    for (int i = 0; i < osize; i++)
    {
        int curSize;
        cout<<"Enter cur size: ";
        cin>>curSize;
        vector<int> cur(curSize);
        cout << "Enter elements: " << endl;
        for (int j = 0; j < curSize; j++)
        {
            cin >> cur[j];
        }
        sort(cur.begin(), cur.end());
        nums.push_back(cur);
    }
    Solution s;
    vector<int> ans = s.smallestRange(nums);
    cout << "Range: " << ans[0] << " " << ans[1] << endl;
}