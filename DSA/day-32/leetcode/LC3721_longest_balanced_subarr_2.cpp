#include<bits/stdc++.h>
using namespace std;

// topic: array + segment tree

class Solution {
    vector<int>mn,mx,dif;
    inline int mid(int s,int e){
        return s+((e-s)>>1);
    }
    void update(int l,int r,int s,int e,int v,int i){
        if(r<s||l>e) return;
        else if(l<=s && r>=e) {
            dif[i]+=v;
            mn[i]+=v;
            mx[i]+=v;
            return;
        }
        int m=mid(s,e);
        int lc=i<<1;
        int rc=lc+1;
        update(l,r,s,m,v,lc);
        update(l,r,m+1,e,v,rc);
        
        mn[i]=min(mn[lc],mn[rc])+dif[i];
        mx[i]=max(mx[lc],mx[rc])+dif[i];
    }
    int find(int l,int r,int s,int e,int v,int i){
        if(r<s || l>e || mn[i]>v ||mx[i]<v) return -1;
        else if(s==e) return s;
        else if(l<=s && r>=e) v-=dif[i];
        
        int m=mid(s,e);
        int lc=i<<1;
        int idx=find(l,r,m+1,e,v,lc+1);
        if(idx!=-1)return idx;
        return find(l,r,s,m,v,lc);
    }
public:
    int longestBalanced(vector<int>& nums) {
        int s=nums.size();
        int ts=s<<2;
        int m=0;
        mn.assign(ts,0);
        mx.assign(ts,0);
        dif.assign(ts,0);
        unordered_map<int,int>mp;
        mp.reserve(s<<1);

        for(int i=s-1;i>=0;i--){
            int r=s-1;
            if(mp.count(nums[i]))r=mp[nums[i]]-1;
            mp[nums[i]]=i;
            int v=(nums[i]&1?-1:1);
            update(i,r,0,s-1,v,1);
            int ri=find(i,s-1,0,s-1,0,1);
            if(ri!=-1) m=max(m,ri-i+1);
        }
        return m;
    }
};

int main(){
    int size;
    cout<<"Enter size: ";
    cin>>size;
    vector<int>nums(size);
    cout<<"Enter nums: "<<endl;
    for(int i=0;i<size;i++){
        cin >> nums[i];
    }
    Solution s;
    cout << "Longest balanced subarr length: " << s.longestBalanced(nums) << endl;
}