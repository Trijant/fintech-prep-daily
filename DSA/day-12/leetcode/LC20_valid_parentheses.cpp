#include<iostream>
#include<stack>
using namespace std;

// topic: stack
// time-complexity: O(n)
// space-complexity: O(n)

bool isValid(string s)
{
    // check size of s is even or odd
    if (s.size() & 1)
    {
        return false;
    }
    stack<char> st;
    for (char ch : s)
    {
        // pushing open brackets in stack
        if (ch == '(' || ch == '{' || ch == '[')
        {
            st.push(ch);
        }
        else
        {
            // if it's not opening bracket then stack should not be empty
            if (st.empty())
            {
                return false;
            }
            // getting top charector of stack
            char topCh = st.top();
            // checking if top char match with corresponding closing bracket
            if ((topCh == '(' && ch != ')') || (topCh == '{' && ch != '}') || (topCh == '[' && ch != ']'))
            {
                return false;
            }
            // remove top char
            st.pop();
        }
    }

    if (st.empty())
    {
        return true;
    }
    return false;
}

int main(){
    string s;
    cout << "Enter string: ";
    cin >> s;
    if (isValid(s))
    {
        cout << "valid parentheses!" << endl;
    }
    else
    {
        cout << "Not valid parentheses!" << endl;
    }    
}