#include<bits/stdc++.h>
using namespace std;

// topic: string + math

class Solution
{
public:
    bool scoreBalance(string s)
    {
        int totalSum = 0;
        for (auto &ch : s)
            totalSum += (ch - 'a' + 1);
        int curSum = 0;
        for (auto &ch : s)
        {
            curSum += (ch - 'a' + 1);
            if (curSum << 1 == totalSum)
                return true;
        }
        return false;
    }
};

int main(){
    string s;
    cout << "Enter s: ";
    cin>>s;
    Solution sl;
    cout << "isPossible: " << (sl.scoreBalance(s) ? "yes" : "no") << endl;
}