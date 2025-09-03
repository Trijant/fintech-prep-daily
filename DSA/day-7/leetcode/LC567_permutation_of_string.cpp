#include <iostream>
#include <vector>
using namespace std;

// Topic: sliding window, frequency array, anagram
// Time-complexity: O(n+m) ; where n=size of s, m=size of p
// Space-complexity: O(1)

vector<int> findAnagrams(string s, string p)
{
    if (s.size() < p.size())
    {
        return {};
    }
    int pfreq[26] = {0};
    int sfreq[26] = {0};

    int sSize = s.size(), pSize = p.size(), left = 0;

    // vector to store all the anagram starting index
    vector<int> anagrams;
    anagrams.reserve(sSize);

    // making record of all the frequencies in p
    for (int i = 0; i < pSize; i++)
    {
        pfreq[p[i] - 'a']++;
    }

    for (int right = 0; right < sSize; right++)
    {
        int curCharIndex = s[right] - 'a';
        sfreq[curCharIndex]++;

        // edjusting window to match freq
        while (sfreq[curCharIndex] > pfreq[curCharIndex])
        {
            sfreq[s[left] - 'a']--;
            left++;
        }
        // we already checked freq so just need to check window size if match it's anagram
        if (right - left + 1 == pSize)
        {
            anagrams.push_back(left);
        }
    }
    return anagrams;
}

int main()
{
    string s1, s2;
    cout << "Enter string s: ";
    getline(cin, s1);
    cout << "Enter string p:";
    getline(cin, s2);
    vector<int> anagrams = findAnagrams(s1, s2);
    cout << "Starting index of anagrams: " << endl;
    for (int i = 0; i < anagrams.size(); i++)
    {
        cout << anagrams[i] << " ";
    }
}