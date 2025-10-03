#include<iostream>
#include<unordered_map>
using namespace std;

// topic: freq array + map

class Solution
{
public:
    string majorityFrequencyGroup(string s)
    {
        int freq[26] = {0};
        for (auto ch : s)
        {
            freq[ch - 'a']++;
        }
        unordered_map<int, string> mp;
        string majorityFreqGroup = "";
        int majorityFreq = 0;
        for (int i = 0; i < 26; i++)
        {
            int curFreq = freq[i];
            if (!curFreq)
                continue;
            string ch(1, 'a' + i);
            if (mp.count(curFreq))
            {
                mp[curFreq] += ch;
            }
            else
            {
                mp[curFreq] = ch;
            }
            if (majorityFreqGroup.size() < mp[curFreq].size() ||
                (majorityFreqGroup.size() == mp[curFreq].size() &&
                 curFreq > majorityFreq))
            {
                majorityFreqGroup = mp[curFreq];
                majorityFreq = curFreq;
            }
        }
        return majorityFreqGroup;
    }
};

int main(){
    string str;
    cout << "Enter string: ";
    cin >> str;
    Solution s;
    cout << "Majority freq group: " << s.majorityFrequencyGroup(str);
}