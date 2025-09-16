#include<iostream>
#include<queue>
using namespace std;

// topic: queue
// time-complexity: O(1)
// space-complexity: O(n)

class RecentCounter
{
private:
    queue<int> pingsQueue;

public:
    RecentCounter()
    {
    }

    int ping(int t)
    {
        pingsQueue.push(t);
        int start = t - 3000;
        while (!pingsQueue.empty() && pingsQueue.front() < start)
        {
            pingsQueue.pop();
        }
        return pingsQueue.size();
    }
};

int main(){
    cout << "Instructions:" << endl;
    cout << "ping seconds: for pinging" << endl;
    cout << "exit: for exit code" << endl;
    RecentCounter *rc = new RecentCounter();
    while (true)
    {
        string i;
        cin >> i;
        if (i=="exit")
        {
            break;
        }
        else if (i=="ping")
        {
            int t;
            cin >> t;
            cout << "Count: " << rc->ping(t)<<endl;
        }
        else{
            cout << "Invalid instruction!" << endl;
        }
    }    
}