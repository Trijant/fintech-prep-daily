#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// TOPIC: KMP(knuth morris pratt algo) & string matching
// Time-complexity: O(n)
// Space-complexity: O(n)

vector<int> getlps(string s){
    vector<int> lps(s.size());
    lps[0] = 0;
    int i = 1, len = 0,size=s.size();
    while (i<size)
    {
        if (s[i]==s[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else if(len==0){
            lps[i] = 0;
            i++;
        }
        else{
            len = lps[len - 1];     //fall back
        }
    }
    return lps;
}

string shortestPalindrome(string s){
    if(s.size()==0){
        return "";
    }
    string rev = s;
    reverse(rev.begin(), rev.end());
    string newStr = s + "#" + rev;
    int lenOfValidPalindrome = getlps(newStr).back();
    newStr = s.substr(lenOfValidPalindrome);
    reverse(newStr.begin(), newStr.end());
    return newStr+s;
}

int main()
{
    string s;
    cout << "Enter string: ";
    getline(cin, s);
    cout << "Shortest valid palindrome: "<<shortestPalindrome(s);
}