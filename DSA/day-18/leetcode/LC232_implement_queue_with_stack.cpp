#include<iostream>
#include<stack>
using namespace std;

// topic: stack + queue
// time-complexity: O(1)
// space-complexity: O(n)

class MyQueue
{
private:
    stack<int> pushBuffer;
    stack<int> popBuffer;

public:
    MyQueue()
    {
    }
    void fillPopBuffer()
    {
        while (!pushBuffer.empty())
        {
            int val = pushBuffer.top();
            pushBuffer.pop();
            popBuffer.push(val);
        }
    }

    void push(int x)
    {
        pushBuffer.push(x);
    }

    int pop()
    {
        if (empty())
        {
            return -1;
        }
        if (popBuffer.empty())
        {
            fillPopBuffer();
        }
        int ans = popBuffer.top();
        popBuffer.pop();
        return ans;
    }

    int peek()
    {
        if (empty())
        {
            return -1;
        }
        if (popBuffer.empty())
        {
            fillPopBuffer();
        }
        return popBuffer.top();
    }

    bool empty()
    {
        return pushBuffer.empty() && popBuffer.empty();
    }
};

int main(){
    cout << "Instructions:" << endl;
    cout << "push val: for pushing value in queue" << endl;
    cout << "pop: for poping value from queue" << endl;
    cout << "peek: get value without removing" << endl;
    cout << "isempty: to check if queue is empty" << endl;
    cout << "exit: to stop code" << endl;
    MyQueue *q = new MyQueue();
    while (true)
    {
        string i;
        cin >> i;
        if (i=="exit")
        {
            break;
        }
        else if (i=="push")
        {
            int val;
            cin >> val;
            q->push(val);
        }
        else if (i=="pop")
        {
            cout << "val: " << q->pop()<<endl;
        }
        else if (i=="peek")
        {
            cout << "val: " << q->peek()<<endl;
        }
        else if(i=="isempty"){
            cout << (q->empty() ? "true" : "false") << endl;
        }
        else{
            cout << "Invalid instruction." << endl;
        }
        
    }
    
}