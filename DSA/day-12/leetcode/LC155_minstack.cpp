#include<iostream>
#include<stack>
#include<climits>
using namespace std;

// Topic: stack + min stack

class MinStack
{
    stack<int> st;
    stack<int> minStack;

public:
    MinStack()
    {
        minStack.push(INT_MAX);
    }

    void push(int val)
    {
        // another way to do with single stack: 
        // keep currentMin single variable
        // if val<currentMin push(2*val-currentMin)     => for pop if top()<currentMin then original stack value=currentMin and oldMin=2*currentMin-top()
        
        minStack.push(min(val, minStack.top()));
        st.push(val);
    }

    void pop()
    {
        st.pop();
        minStack.pop();
    }

    int top()
    {
        return st.top();
        return 0;
    }

    int getMin()
    {
        return minStack.top();
        return 0;
    }
};


int main(){
    MinStack *ms = new MinStack();
    ms->push(2);
    cout << ms->top();
    ms->push(3);
    cout <<"min: "<< ms->getMin();
}