#include<iostream>
#include<vector>
using namespace std;

// TOPIC: backtracking + bitmask
// Time-complexity: O(n*2^n)
// Space-complexity: O(n*2^n)

class Solution
{
private:
    bool isPalindrome(vector<int> &palindromeDP, int start, int end)
    {
        return palindromeDP[start] & (1 << end);
    }
    vector<string> makePartitions(vector<int> &partitionLen, string &s)
    {

        vector<string> partition(partitionLen.size());
        int idx = 0;
        for (int i = 0; i < partitionLen.size(); i++)
        {
            partition[i] = s.substr(idx, partitionLen[i]);
            idx += partitionLen[i];
        }
        return partition;
    }
    void helper(string &s, int start, vector<vector<string>> &ans, vector<int> &partitionLen, vector<int> &palindromeDP)
    {
        // base case
        if (start >= s.size())
        {
            ans.push_back(makePartitions(partitionLen, s));
            return;
        }

        // describing choices
        for (int i = start; i < s.size(); i++)
        {
            if (isPalindrome(palindromeDP, start, i))
            {                                                      // pruning
                partitionLen.push_back(i - start + 1);             // making choice
                helper(s, i + 1, ans, partitionLen, palindromeDP); // exploring recursion
                partitionLen.pop_back();                           // undo choice
            }
        }
    }
    void setPalindrome(string &s, vector<int> &palindromeDP)
    {
        vector<char> newStr(s.size() * 2 + 3);
        newStr[0] = '$';
        newStr[1] = '#';
        int idx = 2;
        for (int i = 0; i < s.size(); i++)
        {
            newStr[idx++] = s[i];
            newStr[idx++] = '#';
        }
        newStr[idx] = '^';
        for (int i = 0; i < newStr.size() - 2; i++)
        {
            // expanding centre
            int start = i, end = i;
            while (start >= 0 && end < newStr.size())
            {
                if (newStr[start] != newStr[end])
                {
                    break;
                }
                else if (newStr[start] != '#')
                {
                    palindromeDP[(start - 1) / 2] |= 1 << ((end - 1) / 2);
                }
                start--;
                end++;
            }
        }
    }

public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans; // vector to store ans
        ans.reserve(1 << s.size());

        vector<int> partitionLen; // vector to store partition lengths
        partitionLen.reserve(s.size());

        vector<int> palindromeDP(s.size(), 0); // DP to keep track of all the valid palindromes
        setPalindrome(s, palindromeDP);

        helper(s, 0, ans, partitionLen, palindromeDP);
        return ans;
    }
};

int main(){
    string s;
    cout << "Enter string: ";
    cin >> s;
    Solution sl;
    vector<vector<string>> partitions = sl.partition(s);
    cout << "Partitions: " << endl;
    for (int i = 0; i < partitions.size(); i++)
    {
        for (int j = 0; j < partitions[i].size(); j++)
        {
            cout << partitions[i][j] << " ";
        }
        cout << endl;
    }
    
}
