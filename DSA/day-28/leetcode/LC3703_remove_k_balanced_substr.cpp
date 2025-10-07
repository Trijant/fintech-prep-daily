#include<iostream>
using namespace std;

// topic: string + stack

class Solution
{
public:
    string removeSubstring(string s, int k)
    {
        int size = s.size();
        string ans(size, ' ');
        int ansSize = 0;
        int matchSize = k << 1;
        string match(matchSize, ')');
        for (int i = 0; i < k; i++)
            match[i] = '(';
        for (int i = 0; i < size; i++)
        {
            ans[ansSize++] = s[i];
            if (ansSize >= matchSize)
            {
                int j = 1;
                for (; j <= matchSize; j++)
                {
                    if (ans[ansSize - j] != match[matchSize - j])
                    {
                        break;
                    }
                }
                if (j > matchSize)
                    ansSize -= matchSize;
            }
        }
        return ans.substr(0, ansSize);
    }
};

int main(){
    string s;
    int k;
    cout << "Enter string : ";
    cin >> s;
    cout << "Enter k: ";
    cin >> k;
    Solution sl;
    cout << "ans: " << sl.removeSubstring(s, k);
}