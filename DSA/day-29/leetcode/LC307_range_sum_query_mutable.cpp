#include<iostream>
#include<vector>
using namespace std;

// topic: segment tree

class NumArray
{
private:
    vector<int> tree;
    int size;
    int getMid(int start, int end) { return start + ((end - start) >> 1); }
    void build(vector<int> &nums, int start, int end, int idx)
    {
        if (start == end)
        {
            tree[idx] = nums[start];
            return;
        }
        int mid = getMid(start, end);
        int leftChild = idx << 1;
        int rightChild = leftChild + 1;
        build(nums, start, mid, leftChild);
        build(nums, mid + 1, end, rightChild);
        tree[idx] = tree[leftChild] + tree[rightChild];
    }
    void updateHelper(int pos, int start, int end, int val, int idx)
    {
        if (start == end)
        {
            tree[idx] = val;
            return;
        }
        int mid = getMid(start, end);
        int leftChild = idx << 1;
        int rightChild = leftChild + 1;
        if (pos > mid)
            updateHelper(pos, mid + 1, end, val, rightChild);
        else
            updateHelper(pos, start, mid, val, leftChild);
        tree[idx] = tree[leftChild] + tree[rightChild];
    }
    int sumRangeHelper(int left, int right, int start, int end, int idx)
    {
        if (right < start || left > end)
            return 0;
        if (left <= start && right >= end)
            return tree[idx];
        int mid = getMid(start, end);
        int leftChild = idx << 1;
        return sumRangeHelper(left, right, start, mid, leftChild) +
               sumRangeHelper(left, right, mid + 1, end, leftChild + 1);
    }

public:
    NumArray(vector<int> &nums)
    {
        size = nums.size();
        tree.resize(size << 2);
        build(nums, 0, size - 1, 1);
    }

    void update(int index, int val)
    {
        updateHelper(index, 0, size - 1, val, 1);
    }

    int sumRange(int left, int right)
    {
        return sumRangeHelper(left, right, 0, size - 1, 1);
    }
};

int main()
{
    int size;
    cout << "Enter size: ";
    cin >> size;
    cout << "Enter elements: " << endl;
    vector<int> arr(size);
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    NumArray st(arr);
    cout << "Instructions: " << endl;
    cout << "query <left> <right>: for range query" << endl;
    cout << "update <idx> <val>" << endl;
    cout << "exit" << endl;
    while (true)
    {
        string s;
        cin >> s;
        if (s == "exit")
            break;
        else if (s == "update")
        {
            int idx, val;
            cin >> idx >> val;
            st.update(idx, val);
        }
        else if (s == "query")
        {
            int left, right;
            cin >> left >> right;
            cout << "Sum: " << st.sumRange(left, right) << endl;
        }
        else
            cout << "Invalid instruction!" << endl;
    }
}