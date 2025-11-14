#include<bits/stdc++.h>
using namespace std;

// topic: array + prefix sum + map

class Solution
{
public:
    long long countStableSubarrays(vector<int> &capacity)
    {
        unordered_map<long long, unordered_map<int, long long>> mp;
        mp.reserve(200000);
        long long prefsum = 0;
        long long count = 0;
        for (int i = 0; i < capacity.size(); i++)
        {
            long long t = prefsum - capacity[i];
            if (mp.count(t))
            {
                count += mp[t][capacity[i]];
                if (capacity[i - 1] == 0 && capacity[i] == 0)
                    count--;
            }
            prefsum += capacity[i];
            mp[prefsum][capacity[i]]++;
        }
        return count;
    }
};

int main(){
    int size;
    cout << "Enter size: ";
    cin >> size;
    vector<int> c(size);
    cout << "Enter elements: "<<endl;
    for (int i = 0; i < size; i++)
    {
        cin >> c[i];
    }
    Solution s;
    cout << "Count : " << s.countStableSubarrays(c) << endl;
}