#include <iostream>
#include <unordered_set>
using namespace std;

// TOPIC: SLIDING WINDOW
// Time-complexity: O(n)
// Space-complexity: O(1)

int characterReplacement(string s, int k)
{
    int mp[26] = {0};
    int left = 0, right = 0, maxLength = 0, maxFreq = 0;

    while (right < s.size())
    {
        int index = s[right] - 'A';
        mp[index]++;
        maxFreq = max(maxFreq, mp[index]); // update after insertion

        // shrink window if condition fails
        while ((right - left + 1) - maxFreq > k)
        {
            mp[s[left] - 'A']--;
            left++;
        }

        maxLength = max(maxLength, right - left + 1); // window length
        right++;
    }

    return maxLength;
}

int main()
{
    int k;
    string s;
    cout << "Enter string: ";
    cin >> s;
    cout << "Enter k: ";
    cin >> k;
    cout << "Length of max substring with same char with k replacements : " << characterReplacement(s,k);
}