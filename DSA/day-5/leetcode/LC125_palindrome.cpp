#include<iostream>
#include<string>
using namespace std;

// TOPIC: STRING MANIPULATION
// Time-complexity:O(n)
// Space-complexity:(1)

bool isPalindrome(string s)
{
    int left = 0, right = s.size() - 1;
    while (left < right)
    {
        // converting uppercase char into lowercase
        if (s[left] >= 'A' && s[left] <= 'Z')
        {
            s[left] = s[left] + 32;
        }
        // checking for not alphanumeric number
        else if ((s[left] < '0' || s[left] > '9') && (s[left] < 'a' || s[left] > 'z'))
        {
            left++;
            continue;
        }
        // converting uppercase char into lowercase
        if (s[right] >= 'A' && s[right] <= 'Z')
        {
            s[right] = s[right] + 32;
        }
        // checking for not alphanumeric number
        else if ((s[right] < '0' || s[right] > '9') && (s[right] < 'a' || s[right] > 'z'))
        {
            right--;
            continue;
        }
        // checking for palindrom
        if (s[left] != s[right])
        {
            return false;
        }
        right--;
        left++;
    }
    return true;
}

int main(){
    string s;
    cout << "Enter string: ";
    getline(cin,s);
    cout << "Is palindrome?: " << isPalindrome(s);
}