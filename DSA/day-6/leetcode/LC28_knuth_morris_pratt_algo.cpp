#include<iostream>
#include<vector>
using namespace std; 

// TOPIC: String Matching (Knuth-Morris-Pratt Algorithm)
// Time Complexity: O(m + n), where m = length of text, n = length of pattern
// Space Complexity: O(n) for LPS array; O(m + n) if storing all occurrences

int strStr(string haystack, string needle)
{
    int haystackSize = haystack.size(), needleSize = needle.size();
    int lps[needleSize];
    int i = 1, len = 0;
    lps[0] = 0;                     //lps= Longest Prefix Suffix
    while (i < needleSize)
    {
        if (needle[i] == needle[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else if (len == 0)
        {
            lps[i] = 0;
            i++;
        }
        else
        {
            len = lps[len - 1]; // fall back
        }
    }

    i = 0;
    int j = 0;
    while (i < haystackSize)
    {
        if (haystack[i] == needle[j])
        {
            i++;
            j++;
        }
        else if (j == 0)
        {
            i++;
        }
        else
        {
            j = lps[j - 1];
        }
        if (j == needleSize)
        {
            return i - j;
        }
    }
    return -1;
}

int main(){
    string str, pattern;
    cout << "Enter string: ";
    getline(cin, str);
    cout << "Enter pattern: ";
    getline(cin,pattern);
    cout << "Pattern matched at index: " << strStr(str, pattern);
}