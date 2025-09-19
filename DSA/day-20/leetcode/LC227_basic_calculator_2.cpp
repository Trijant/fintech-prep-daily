#include<iostream>
using namespace std;

// topic: stack
// time-complexity: O(n)
// space-complexity: O(1)

int calculate(string s)
{
    int result = 0;
    int lastNumber = 0; // used for * and /
    int num = 0;
    char operation = '+';

    for (int i = 0; i < s.size(); ++i)
    {
        char ch = s[i];

        if (isdigit(ch))
        {
            num = num * 10 + (ch - '0');
        }

        if ((!isdigit(ch) && ch != ' ') || i == s.size() - 1)
        {
            if (operation == '+')
            {
                result += lastNumber;
                lastNumber = num;
            }
            else if (operation == '-')
            {
                result += lastNumber;
                lastNumber = -num;
            }
            else if (operation == '*')
            {
                lastNumber = lastNumber * num;
            }
            else if (operation == '/')
            {
                lastNumber = lastNumber / num;
            }

            operation = ch;
            num = 0;
        }
    }
    result += lastNumber;
    return result;
}

int main(){
    string s;
    cout << "Enter equation: ";
    cin >> s;
    cout << "Ans: " << calculate(s);
}