#include<iostream>
#include<vector>
using namespace std;

// topic: min heap

class KthLargest
{
private:
    vector<int> minHeap;
    int size;
    int end;
    inline void heapify(int idx)
    {
        while (idx <= end)
        {
            int leftChild = idx << 1;
            int rightChild = leftChild + 1;
            int minChild;

            if (rightChild < size &&
                minHeap[rightChild] < minHeap[leftChild])
                minChild = rightChild;
            else
                minChild = leftChild;

            if (minHeap[minChild] >= minHeap[idx])
                return;
            swap(minHeap[idx], minHeap[minChild]);
            idx = minChild;
        }
    }
    inline void insert(int num)
    {
        if (num > minHeap[1])
        {
            minHeap[1] = num;
            heapify(1);
        }
    }

public:
    KthLargest(int k, vector<int> &nums)
    {
        size = k + 1;
        end = k >> 1;
        minHeap.reserve(size);
        minHeap.push_back(0);
        for (int i = 0; i < k - 1; i++)
            minHeap.push_back(nums[i]);
        minHeap.push_back((k <= nums.size() ? nums[k - 1] : INT_MIN));
        for (int i = end; i > 0; i--)
            heapify(i);
        for (int i = k; i < nums.size(); i++)
            insert(nums[i]);
    }

    int add(int val)
    {
        insert(val);
        return minHeap[1];
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
    KthLargest kth(k,nums);
    cout << "Instructions: " << endl;
    cout << "add <val>" << endl;
    cout << "exit" << endl;
    while (true)
    {
        string i;
        cin >> i;
        if(i=="exit"){
            break;
        }
        else if(i == "add"){
            int val;
            cin >> val;
            cout << k << "th largest score: " << kth.add(val) << endl;
        }
        else{
            cout << "Invalid instruction! " << endl;
        }
    }
    
}