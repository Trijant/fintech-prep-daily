#include<iostream>
#include<vector>
using namespace std;

// topic: number theory

class Solution
{
public:
    vector<int> decimalRepresentation(int n)
    {
        vector<int> ans;
        long divisor = 10;
        while (n)
        {
            int cur = n % divisor;
            if (cur)
                ans.insert(ans.begin(), cur);
            n -= cur;
            divisor *= 10;
        }
        return ans;
    }
};

int main(){
    int n;
    cout << "Enter number: ";
    cin >> n;
    Solution s;
    vector<int> ans = s.decimalRepresentation(n);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}