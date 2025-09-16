#include<iostream>
#include<stack>
#include<vector>
using namespace std;

// topic: stack + postfix equation
// time-complexity: O(n)
// space-complexity: O(n)

class Solution
{
private:
    stack<int> operands;
    int evaluate(char op)
    {
        int operand2 = operands.top();
        operands.pop();
        int operand1 = operands.top();
        operands.pop();
        switch (op)
        {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            return operand1 / operand2;
        }
        return -1;
    }

public:
    int evalRPN(vector<string> &tokens)
    {
        for (string s : tokens)
        {
            if (s.size() > 1 || (s[0] >= '0' && s[0] <= '9'))
            {
                operands.push(stoi(s));
            }
            else
            {
                char op = s[0];
                operands.push(evaluate(op));
            }
        }
        return operands.top();
    }
};

int main(){
    int size;
    cout << "Enter size: ";
    cin >> size;
    cout << "Enter array elements:" << endl;
    vector<string> tokens(size);
    for (int i = 0; i < size; i++)
    {
        cin >> tokens[i];
    }
    Solution s;
    cout << "Ans: " << s.evalRPN(tokens) << endl;
}