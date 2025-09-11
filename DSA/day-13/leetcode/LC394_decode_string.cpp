#include<iostream>
#include<stack>
using namespace std;

// topic: stack
// time-complexity: O(n+m)
// space-complexity: O(n+m); n=input string len,m=output string len

string decodeString(const string &s)
{
    stack<int> countSt;       // stores repeat counts
    stack<string> strSt;      // stores strings before '['
    string curStr;            // current building string
    curStr.reserve(s.size()); // reserve upfront to avoid realloc
    int num = 0;

    for (char ch : s)
    {
        if (isdigit(ch))
        {
            // build number (handles multi-digit)
            num = num * 10 + (ch - '0');
        }
        else if (ch == '[')
        {
            // push current state
            countSt.push(num);
            strSt.push(curStr);
            num = 0;
            curStr.clear();
        }
        else if (ch == ']')
        {
            // pop last string and repeat
            int repeat = countSt.top();
            countSt.pop();
            string prev = strSt.top();
            strSt.pop();

            // Efficient repetition
            string expanded;
            expanded.reserve(curStr.size() * repeat);
            for (int i = 0; i < repeat; i++)
                expanded += curStr;

            curStr = prev + expanded;
        }
        else
        {
            // normal character
            curStr.push_back(ch);
        }
    }
    return curStr;
}

int main(){
    string s;
    cout << "Enter encoded string: ";
    cin >> s;
    cout << "Decoded string: " << decodeString(s);
}