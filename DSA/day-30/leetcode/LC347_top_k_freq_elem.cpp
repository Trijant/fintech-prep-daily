#include<iostream>
#include<vector>
using namespace std;

// topic: min heap

class Solution
{
private:
    vector<int> freq;
    int base = 10000;
    vector<int> minHeap;
    int size;
    int end;
    void heapify(int idx)
    {
        while (idx <= end)
        {
            int leftChild = (idx << 1) + 1;
            int rightChild = leftChild + 1;
            int minChild;
            if (rightChild < size && freq[minHeap[rightChild]] < freq[minHeap[leftChild]])
                minChild = rightChild;
            else
                minChild = leftChild;
            if (freq[minHeap[minChild]] >= freq[minHeap[idx]])
                return;
            swap(minHeap[minChild], minHeap[idx]);
            idx = minChild;
        }
    }

public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        freq.assign(20001, 0);
        size = k;
        end = (k >> 1) - 1;
        minHeap.reserve(size);
        vector<int> uniqueNums;
        uniqueNums.reserve(nums.size());
        for (auto &n : nums)
        {
            n += base;
            if (!freq[n])
                uniqueNums.push_back(n);
            freq[n]++;
        }
        for (int i = 0; i < k; i++)
            minHeap.push_back(uniqueNums[i]);

        for (int i = end; i >= 0; i--)
            heapify(i);
        for (int i = k; i < uniqueNums.size(); i++)
        {
            if (freq[uniqueNums[i]] > freq[minHeap[0]])
            {
                minHeap[0] = uniqueNums[i];
                heapify(0);
            }
        }
        for (auto &m : minHeap)
            m -= base;
        return minHeap;
    }
};

int main(){

    int size, k;
    cout << "Enter size: ";
    cin >> size;
    cout << "Enter k: ";
    cin >> k;
    cout << "Enter elements: " << endl;
    vector<int> nums(size);
    for (int i = 0; i < size; i++)
    {
        cin >> nums[i];
    }
    Solution s;
    vector<int> ans = s.topKFrequent(nums, k);
    cout << "Top k frequent elements: ";
    for(auto & n:ans)
        cout << n << " ";
    cout << endl;
}