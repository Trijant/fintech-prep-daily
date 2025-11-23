#include<bits/stdc++.h>
using namespace std;

// topic: maths

class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum=0,mul=1;
        int x=0;
        while(n){
            int d=n%10;
            n/=10;
            if(d){
                x+=d*mul;
                mul*=10;
                sum+=d;
            }
        }
        return sum*x;
    }
};

int main(){
    int n;
    cout<<"Enter n:";
    cin>>n;
    Solution s;
    cout << "Ans: " << s.sumAndMultiply(n) << endl;
}