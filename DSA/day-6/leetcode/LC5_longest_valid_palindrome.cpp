#include <iostream>
#include<vector>
using namespace std;

//TOPIC: MANACHER'S ALGORITHM
//Time-complexity: O(n)
//Space-complexity: O(n)

string longestPalindrome(string s)
{
    vector<char> tstr(s.size() * 2 + 3);
    int tsize = tstr.size();
    vector<int> radius(tsize, 0);
    tstr[0] = '^';
    tstr[tsize - 1] = '&';
    int i = 1, j = 0;
    while (i < tsize - 2)
    {
        tstr[i++] = '#';
        tstr[i++] = s[j++];
    }
    tstr[i] = '#';
    radius[0] = 0;
    int c = 0, r = 0;
    for (int i = 1; i < tsize - 1; i++)
    {
        // check for mirror , if exist then both will have same palindrome radius till r:right; It reduces centre expansion 
        int mirr = 2 * c - i;
        if (i < r)
        {
            radius[i] = min(radius[mirr], r - i);
        }

        // expand arround centre
        while (tstr[i + 1 + radius[i]] == tstr[i - 1 - radius[i]])
        {
            radius[i]++;
        }

        // updating right most palindrome center
        if (i + radius[i] > r)
        {
            r = i + radius[i];
            c = i;
        }
    }
    //finding max radius centre(longest palindrome centre)
    int maxlen = 0, index = 0;
    for (int i = 0; i < tsize; i++)
    {
        if (radius[i] > maxlen)
        {
            maxlen = radius[i];
            index = i;
        }
    }
    // start index of original s;
    int start = (index - maxlen) / 2;
    return s.substr(start, maxlen);
}

int main(){
    string s;
    cout << "Enter string: ";
    getline(cin,s);
    cout << "Longest valid palindrome substring: " << longestPalindrome(s);
}