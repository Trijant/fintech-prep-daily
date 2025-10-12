#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// topic: kadane's algo

class Solution
{
public:
    int maximumEnergy(vector<int> &energy, int k)
    {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int size = energy.size();

        for (int i = k; i < size; i++)
            energy[i] += max(energy[i - k], 0);

        int maxEnergy = INT_MIN;
        for (int i = size - k; i < size; i++)
            maxEnergy = max(maxEnergy, energy[i]);
        return maxEnergy;
    }
};

int main(){
    int n, k;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter k: ";
    cin >> k;
    vector<int> energy(n);
    cout << "Enter elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> energy[i];
    }
    Solution s;
    cout << "Max energy: " << s.maximumEnergy(energy, k);
}