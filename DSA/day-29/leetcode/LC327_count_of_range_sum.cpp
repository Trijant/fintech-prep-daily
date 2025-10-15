#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// topic: fenweek tree

class Solution
{
private:
    vector<int> tree;
    int size;

    void insert(int idx)
    {
        while (idx < size)
        {
            tree[idx]++;
            idx += (idx & -idx);
        }
    }
    int query(int idx)
    {
        int count = 0;
        while (idx > 0)
        {
            count += tree[idx];
            idx -= (idx & -idx);
        }
        return count;
    }

public:
    int countRangeSum(vector<int> &nums, int lower, int upper)
    {
        vector<long long> prefSums;
        prefSums.reserve(nums.size() + 1);
        prefSums.push_back(0);

        long long prefSum = 0;
        for (auto &n : nums)
        {
            prefSum += n;
            prefSums.push_back(prefSum);
        }

        vector<long long> compressedPrefSum = prefSums;
        sort(compressedPrefSum.begin(), compressedPrefSum.end());
        compressedPrefSum.erase(unique(compressedPrefSum.begin(), compressedPrefSum.end()), compressedPrefSum.end());
        auto rankOf = [&](long long p)
        {
            return lower_bound(compressedPrefSum.begin(), compressedPrefSum.end(), p) - compressedPrefSum.begin();
        };

        size = compressedPrefSum.size() + 1;
        tree.assign(size, 0);

        int ans = 0;
        for (auto &p : prefSums)
        {
            int idx = rankOf(p);
            int end = upper_bound(compressedPrefSum.begin(), compressedPrefSum.end(), p - lower) - compressedPrefSum.begin();
            int start = rankOf(p - upper);
            ans += (query(end) - query(start));
            insert(idx + 1);
        }

        return ans;
    }
};

int main(){
    int size, lower, upper;
    cout << "Enter size lower upper: ";
    cin >> size >> lower >> upper;
    cout << "Enter elements: " << endl;

    vector<int> nums(size);
    for (int i = 0; i < size; i++)
    {
        cin >> nums[i];
    }
    Solution s;
    cout << "Count: " << s.countRangeSum(nums, lower, upper) << endl;
}