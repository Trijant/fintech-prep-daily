#include<iostream>
using namespace std;

// TOPIC: fibonaci series
// Time-complexity: O(n)
// Space-complexity: O(1)

int fib(int n)
{
    if (n == 0)
        return 0;
    int second_last = 0, last = 1;
    for (int i = 2; i <= n; i++)
    {
        int current = second_last + last;
        second_last = last;
        last = current;
    }
    return last;
}

int main(){
    int n;
    cout << "Enter number: ";
    cin >> n;
    cout << "Fibonaci number: " << fib(n);
}