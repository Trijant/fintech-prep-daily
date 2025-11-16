#include<bits/stdc++.h>
using namespace std;

// topic: min heap + graph + greedy

class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<vector<pair<int, int>>> graph(n + 1, vector<pair<int, int>>(0));
        for (auto &t : times)
            graph[t[0]].push_back({t[1], t[2]});

        vector<int> dist(n + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, k});
        while (!q.empty())
        {
            auto [w, v] = q.top();
            q.pop();
            if (dist[v] == INT_MAX)
            {
                for (auto &[t, d] : graph[v])
                    if (dist[t] == INT_MAX)
                        q.push({d + w, t});
                dist[v] = w;
            }
        }

        int mx = *max_element(dist.begin() + 1, dist.end());
        return mx == INT_MAX ? -1 : mx;
    }
};

int main(){
    int size,n,k;
    cout << "Enter size: ";
    cin>>size;
    cout << "Enter n: ";
    cin>>n;
    cout << "Enter k: ";
    cin>>k;
    vector<vector<int>> times(size, vector<int>(3));
    cout<<"Enter from to time:"<<endl;
    for (int i = 0; i < size; i++)
    {
        cin >> times[i][0] >> times[i][1] >> times[i][2];
    }
    Solution s;
    cout << "Max delay time: " << s.networkDelayTime(times, n, k) << endl;
}