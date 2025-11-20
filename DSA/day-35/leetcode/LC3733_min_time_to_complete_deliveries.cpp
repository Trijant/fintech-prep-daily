#include<bits/stdc++.h>
using namespace std;

// topic: binary search on answer + maths

class Solution {
public:
    long long minimumTime(vector<int>& d, vector<int>& r) {
        int d1=d[0],d2=d[1],r1=r[0],r2=r[1],r3=lcm(r1,r2);
        long long end=4e9,start=0;
        auto canDeliver=[&](long long t){
            long long available1=t-t/r1;
            long long available2=t-t/r2;
            long long bothBusy=t/r3;
            long long totalAvailable=t-bothBusy;
            if(d1>available1 || d2>available2) return false;
            return (d1+d2)<=totalAvailable;
        };
        while(start<end){
            long long mid=start+((end-start)>>1);
            if(canDeliver(mid)) end=mid;
            else start=mid+1;
        }
        return start;
    }
};

int main(){
    vector<int> d(2);
    vector<int> r(2);
    cout<<"Enter di: "<<endl;
    cin >> d[0] >> d[1];
    cout<<"Enter ri: "<<endl;
    cin >> r[0] >> r[1];
    Solution s;
    cout << "Min time: " << s.minimumTime(d, r) << endl;
}