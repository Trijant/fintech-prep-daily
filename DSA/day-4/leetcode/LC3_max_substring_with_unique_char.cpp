#include<iostream>
#include<unordered_set>
using namespace std;

// TOPIC: SLIDING WINDOW
// Time-complexity: O(n)
// Space-complexity: O(n)

int lengthOfLongestSubstring(string s)
{
    unordered_set<char> mp;
    int left = 0, right = 0, maxLength = 0;
    while (right < s.size())
    {
        while (mp.count(s[right]))
        {
            mp.erase(s[left++]);
        }
        mp.insert(s[right++]);
        if (right - left > maxLength)
        {
            maxLength = right - left;
        }
    }
    return maxLength;
}
int main(){
    string s;
    cout << "Enter string: ";
    cin >> s;
    cout << "Length of max substring with unique char : " << lengthOfLongestSubstring(s);
}