#include<iostream>
using namespace std;

// TOPIC: tribonacci+ memoization
// Time-complexity: O(n)
// Space-complexity: O(1)

int tribonacci(int n)
{
    if (n <= 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    int prev3 = 0, prev2 = 1, prev1 = 1;
    for (int i = 3; i <= n; i++)
    {
        int cur = prev1 + prev2 + prev3;
        prev3 = prev2;
        prev2 = prev1;
        prev1 = cur;
    }
    return prev1;
}

int main(){
    int n;
    cout << "Enter number: ";
    cin >> n;
    cout << "Tribonacci term : " << tribonacci(n);
}