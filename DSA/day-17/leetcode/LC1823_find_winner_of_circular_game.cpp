#include<iostream>
using namespace std;

// topic: josephus formula + recursion
// time-complexity: O(n)
// space-complexity:O(n)

int findTheWinner(int n, int k)
{
    if (n == 1){                           // base case
        return 1;
    }
    return (findTheWinner(n - 1, k) + k - 1) % n + 1; // josephus formula
}

int main(){
    int n, k;
    cout << "Enter N: ";
    cin >> n;
    cout << "Enter K:";
    cin >> k;
    cout << "The winner is " << findTheWinner(n, k);
}