#include <iostream>
#include <string>
using namespace std;

// TOPIC: STRING MANIPULATION
// Time-complexity:O(n)
// Space-complexity:(1)
bool isAnagram(string s, string t)
{
    if (s.size() != t.size())
    {
        return false;
    }
    // map to store frequency of char in string
    int mp[26] = {0};
    for (int i = 0; i < s.size(); i++)
    {
        mp[s[i] - 'a']++;
    }
    for (int i = 0; i < t.size(); i++)
    {
        // checking if any character is occured morethan first string
        if (!mp[t[i] - 'a'])
        {
            return false;
        }
        mp[t[i] - 'a']--;
    }
    return true;
}

int main()
{
    string s1,s2;
    cout << "Enter string1: ";
    getline(cin, s1);
    cout << "Enter string2: ";
    getline(cin, s2);
    cout << "Is anagram?: " << isAnagram(s1,s2);
}