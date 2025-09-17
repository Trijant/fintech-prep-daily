#include<iostream>
#include<stack>
#include<vector>
using namespace std;

// topic: stack
// time-complexity: O(1):amortized /O(n):worst
// space-complexity: O(n)

class StockSpanner
{
private:
    stack<int> prevHigh;
    vector<int> prices;

public:
    StockSpanner()
    {
    }

    int next(int price)
    {
        while (!prevHigh.empty() && prices[prevHigh.top()] <= price)
        {
            prevHigh.pop();
        }
        int curDay = prices.size();
        int span = curDay - (prevHigh.empty() ? -1 : prevHigh.top());
        prevHigh.push(curDay);
        prices.push_back(price);
        return span;
    }
};

int main(){
    cout << "Instructions:" << endl;
    cout << "price val:for storing price and getting span" << endl;
    cout << "exit: for exit code" << endl;
    StockSpanner *s = new StockSpanner();
    while (true)
    {
        string i;
        cin >> i;
        if (i=="exit")
        {
            break;
        }
        else if (i=="price")
        {
            int val;
            cin >> val;
            cout << "span: " << s->next(val)<<endl;
        }
        else{
            cout << "Invalid instruction!" << endl;
        }
    }
    
}