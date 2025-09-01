#include<iostream>
#include<vector>
using namespace std;

// TOPIC: STRING MANIPULATION
// Time-complexity: O(n*m), where n=len(arr) and m=len(shortest string)
// Space-complexity: O(1)

string longestCommonPrefix(vector<string> &strs)
{
    for (int i = 0; i < strs[0].size(); i++)
    {
        for (int j = 1; j < strs.size(); j++)
        {
            if (i >= strs[j].size() || strs[j][i] != strs[0][i])
            {
                return strs[0].substr(0, i);
            }
        }
    }
    return strs[0];
}

int main(){
    int size;
    cout << "Enter size of array: ";
    cin >> size;
    vector<string> strs(size);
    cout << "Enter strings without space: "<<endl;
    for (int i = 0; i < size; i++)
    {
        cin >> strs[i];
    }
    cout << "Longest common prefix : " << longestCommonPrefix(strs);
}