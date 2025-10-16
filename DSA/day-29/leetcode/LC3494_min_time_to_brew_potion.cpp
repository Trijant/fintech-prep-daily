#include<iostream>
#include<vector>
using namespace std;

// topic: prefix sum

class Solution
{
public:
    long long minTime(vector<int> &skill, vector<int> &mana)
    {
        int n = skill.size();
        int m = mana.size();
        vector<long long> sPrefix(n + 1, 0);

        for (int i = 1; i <= n; i++)
            sPrefix[i] = sPrefix[i - 1] + skill[i - 1];

        long long timeSum = 0;
        for (int j = 1; j < m; j++)
        {
            long long maxTime = 0;
            for (int i = 0; i < n; i++)
            {
                long long timeDiff = sPrefix[i + 1] * mana[j - 1] - sPrefix[i] * mana[j];
                maxTime = max(maxTime, timeDiff);
            }
            timeSum += maxTime;
        }
        return timeSum + sPrefix[n] * mana[m - 1];
    }
};

int main(){
    int n, m;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter m: ";
    cin >> m;
    vector<int> skill(n);
    vector<int> mana(m);
    cout << "Enter skill: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> skill[i];
    }
    cout << "Enter mana: " << endl;
    for (int i = 0; i < m; i++)
    {
        cin >> mana[i];
    }
    Solution s;
    cout << "End time: " << s.minTime(skill, mana);
}