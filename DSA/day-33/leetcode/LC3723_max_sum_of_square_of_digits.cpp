#include<bits/stdc++.h>
using namespace std;

// topic: maths + greedy

class Solution
{
public:
    string maxSumOfSquares(int num, int sum)
    {
        string ans = "";
        ans.reserve(num);
        while (num)
        {
            int take = min(9, sum);
            sum -= take;
            ans.push_back('0' + take);
            num--;
        }
        return sum ? "" : ans;
    }
};

int main(){
    int num, sum;
    cout << "Enter num: ";
    cin>>num;
    cout << "Enter sum: ";
    cin >> sum;
    Solution s;
    cout << "Max sum: " << s.maxSumOfSquares(num, sum) << endl;
}