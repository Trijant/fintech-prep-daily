#include<bits/stdc++.h>
using namespace std;

// topic: string 

class Solution {
public:
    string lexSmallest(string s) {
        int size=s.size();
        string ans=s;
        char smallest=*min_element(s.begin(),s.end());
        bool isReversed=false;
        for(int i=0;i<size;i++){
            if(s[i]==smallest){
                string c=s;
                reverse(c.begin(),c.begin()+i+1);
                if(ans>c){
                    if(s[0] !=smallest) isReversed=true;
                    ans=c;
                }
            }
        }
        if(isReversed) return ans;
        char last=s[size-1];
        for(int i=1;i<size;i++){
            if(s[i]>=last){
                string c=s;
                reverse(c.begin()+i,c.end());
                if(ans>c){
                    ans=c;
                    if(s[i]>last) return ans;
                }
            }
        }
        return ans;
    }
};

int main(){
    string str;
    cout << "Enter str: ";
    cin >> str;
    Solution s;
    cout << "Smallest str after reverse: " << s.lexSmallest(str) << endl;
}