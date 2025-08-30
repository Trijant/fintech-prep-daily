#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// TOPIC: Frequency array
// Time-complexity: O(n)
// Space-complexity: O(1)

int firstUniqChar(string s)
{
    int freqArr[26] = {0};
    int firstIndex[26];
    fill(firstIndex, firstIndex + 26, -1);
    int size = s.size();
    int ans = INT_MAX;
    for (int i = 0; i < size; i++)
    {
        int curr_index = s[i] - 'a';
        freqArr[curr_index]++;
        if (firstIndex[curr_index] == -1)
        {
            firstIndex[curr_index] = i;
        }
    }
    for (int i = 0; i < 26; i++)
    {
        if (freqArr[i] == 1 && firstIndex[i] < ans)
        {
            ans = firstIndex[i];
        }
    }
    if (ans == INT_MAX)
    {
        return -1;
    }
    return ans;
}

int main(){
    string s;
    cout << "Enter string containg char from 'a' to 'z':" << endl;
    cin >> s;
    cout << "First unique char is at index: " << firstUniqChar(s);
}