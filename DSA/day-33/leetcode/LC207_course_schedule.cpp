#include<bits/stdc++.h>
using namespace std;

// topic: graph + dfs

class Solution
{
private:
    bool detectCycle(vector<int> prerequisites[], vector<bool> &visited, vector<bool> &isCompleted, int idx)
    {
        if (visited[idx])
            return true;
        visited[idx] = true;
        for (auto &i : prerequisites[idx])
            if (!isCompleted[i] && detectCycle(prerequisites, visited, isCompleted, i))
                return true;

        visited[idx] = false;
        isCompleted[idx] = true;
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> p[numCourses];
        vector<bool> visited(numCourses, false);
        vector<bool> isCompleted(numCourses, false);

        for (auto &v : prerequisites)
            p[v[0]].push_back(v[1]);
        for (int i = 0; i < numCourses; i++)
            if (!isCompleted[i] && detectCycle(p, visited, isCompleted, i))
                return false;
        return true;
    }
};

int main(){
    int size,n;
    cout<<"Enter course count: ";
    cin >> n;
    cout<<"Enter size: ";
    cin>>size;
    vector<vector<int>> p(size, vector<int>(2));
    cout << "Enter prerequisites: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> p[i][0] >> p[i][1];
    }
    Solution s;
    if(s.canFinish(n,p))
        cout << "It's possible to complete courses." << endl;
    else
        cout << "It's not possible to complete courses." << endl;
}