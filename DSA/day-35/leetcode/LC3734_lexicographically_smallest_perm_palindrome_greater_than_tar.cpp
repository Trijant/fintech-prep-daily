#include<bits/stdc++.h>
using namespace std;

// topic: back tracking + freq array + string

class Solution {
private:
    bool helper(vector<int>&f,string &target,int idx,int mid,string &ans,bool any){
        if(idx>=mid){
            int size=target.size();
            for(int i=mid-1;i>=0;i--)ans[size-i-1]=ans[i];
            return any || ans>target;
        }
        int i= any?0:target[idx]-'a';
        while(i<26){
            if(f[i]){
                ans[idx]='a'+i;
                f[i]--;
                if(helper(f,target,idx+1,mid,ans,any||ans[idx]>target[idx])) return true;
                f[i]++;
            }
            i++;
        }
        return false;
    }
public:
    string lexPalindromicPermutation(string s, string target) {
        int size=s.size();
        vector<int>f(26,0);
        for(auto & ch:s) f[ch-'a']++;
        bool oddAllowed=size&1;
        char md='a';
        for(int i=0;i<26;i++) {
            if(f[i] &1 && !oddAllowed) return "";
            else if(f[i] &1) md='a'+i;
            f[i]>>=1;
        }
        int mid=size>>1;
        string ans(size,'a');
        if(size&1)ans[mid]=md;

        return helper(f,target,0,mid,ans,false)?ans:"";
    }
};

int main(){
    string s, tar;
    cout << "Enter s: ";
    cin>>s;
    cout<<"Enter target: ";
    cin>>tar;
    Solution sl;
    cout << "Ans: " << sl.lexPalindromicPermutation(s, tar) << endl;
}