#include<bits/stdc++.h>
using namespace std;

// topic: maths

class Solution
{
public:
    long long removeZeros(long long n)
    {
        long long ans = 0;
        long long m = 1;
        while (n)
        {
            int d = n % 10;
            n /= 10;
            if (!d)
                continue;
            ans = d * m + ans;
            m *= 10;
        }
        return ans;
    }
};

int main(){
    long long n;
    cout << "Enter n: ";
    cin >> n;
    Solution s;
    cout << "Ans: " << s.removeZeros(n) << endl;
}