#include<iostream>
using namespace std;

// TOPIC: fibonaci series
// Time-complexity: O(n)
// Space-complexity: O(1)

int climbStairs(int n)
{
    int prev2 = 0, prev1 = 1;
    if (n <= 0)
    {
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        int cur = prev2 + prev1;
        prev2 = prev1;
        prev1 = cur;
    }
    return prev1;
}

int main(){
    int n;
    cout << "Enter number: ";
    cin >> n;
    cout << "Total number of ways to climb stairs: " << climbStairs(n);
}