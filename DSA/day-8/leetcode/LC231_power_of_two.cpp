#include<iostream>
using namespace std;

// TOPIC: recursion + bit manipulation
// Time-complexity: O(n)
// Space-complexity: O(log n)

bool isPowerOfTwo(int n)
{
    // after shifting if number is 1 it means there was just 1 bit "1" which means power of 2.
    if (n == 1)
    {
        return true;
    }
    // if number is not 1 and it has bit "1" at right most place that means it has more than 1 bits "1" which is not power of 2 or if number is lessthan or equal to 0 it's not power of 2.
    else if (n & 1 || n <= 0)
    {
        return false;
    }

    // shifting 1 bit right side which is similar to divide by 2 but much more efficient and fast.
    return isPowerOfTwo(n >> 1);
}

int main(){
    int n;
    cout << "Enter number: ";
    cin >> n;
    cout << isPowerOfTwo(n);
}