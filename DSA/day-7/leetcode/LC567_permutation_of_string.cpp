#include <iostream>
#include <vector>
using namespace std;

// Topic: sliding window, frequency array, anagram
// Time-complexity: O(n+m) ; where n=size of s, m=size of p
// Space-complexity: O(1)

bool checkInclusion(string s1, string s2)
{
    int s1Size = s1.size(), s2Size = s2.size();
    // if s1 is smaller no permutation possible
    if (s1Size > s2Size)
    {
        return false;
    }

    // frequency array for both strings
    int s1freq[26] = {0};
    int s2freq[26] = {0};

    // storing frequency of s1
    for (int i = 0; i < s1Size; i++)
    {
        s1freq[s1[i] - 'a']++;
    }

    // sliding window approach
    int left = 0;
    for (int right = 0; right < s2Size; right++)
    {
        // inserting from right pointer
        int idx = s2[right] - 'a';
        s2freq[idx]++;

        // shrinking with help of left pointer to match condition
        while (s2freq[idx] > s1freq[idx])
        {
            s2freq[s2[left] - 'a']--;
            left++;
        }

        // checking the valid condition
        if (right - left + 1 == s1Size)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    string s1, s2;
    cout << "Enter string s: ";
    getline(cin, s1);
    cout << "Enter string p:";
    getline(cin, s2);
    cout << "Does s2 contain permutation of s1: " <<checkInclusion(s1,s2)<< endl;
}