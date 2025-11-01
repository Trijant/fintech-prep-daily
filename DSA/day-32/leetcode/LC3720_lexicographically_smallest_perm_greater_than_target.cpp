#include<bits/stdc++.h>
using namespace std;

// topic: backtracking + string

class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int size=s.size();
        string ans;
        ans.reserve(size);
        vector<int> f(26, 0);
        for (auto& ch : s)
            f[ch - 'a']++;
        int i=0;
        do{
            ans.push_back(target[i]);
        }while(f[target[i]-'a']-- && i++<size-1);

        while(!ans.empty()){
            char ch=ans.back();
            ans.pop_back();
            f[ch-'a']++;
            for(int i=ch-'a'+1;i<26;i++) if(f[i]){
                    ans.push_back('a'+i);
                    f[i]--;
                    for(int j=0;j<26;j++) while(f[j]--) ans.push_back('a'+j);
                    return ans;
                }
        }
        return ans;
    }
};

int main(){
    string s, t;
    cout << "Enter s: ";
    cin >> s;
    cout<<"Enter target: ";
    cin>>t;
    Solution sl;
    cout << "ans: " << sl.lexGreaterPermutation(s, t) << endl;
}