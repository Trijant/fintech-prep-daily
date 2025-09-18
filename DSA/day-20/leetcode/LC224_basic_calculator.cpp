#include<iostream>
#include<stack>
using namespace std;

// topic: stack
// time-complexity: O(n)
// space-complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

    int calculate(string s)
    {
        long result = 0;
        int sign = 1;
        stack<long> results;
        stack<int> signs;
        int n = s.size();

        for (int i = 0; i < n; i++)
        {
            char c = s[i];

            if (isdigit(c))
            {
                long num = 0;
                while (i < n && isdigit(s[i]))
                {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                i--; // adjust for extra increment
                result += sign * num;
            }
            else if (c == '+')
            {
                sign = 1;
            }
            else if (c == '-')
            {
                sign = -1;
            }
            else if (c == '(')
            {
                results.push(result);
                signs.push(sign);
                result = 0;
                sign = 1;
            }
            else if (c == ')')
            {
                result = results.top() + signs.top() * result;
                results.pop();
                signs.pop();
            }
        }

        return (int)result;
    }


int main(){
    string s;
    cout<<"Enter equation: ";
    cin>>s;
    cout << "Ans: " << calculate(s) << endl;
}