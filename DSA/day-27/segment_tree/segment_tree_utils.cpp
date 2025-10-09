#include <iostream>
#include <vector>
using namespace std;

// topic : segment tree

class SegmentTree
{
private:
    vector<int> tree;
    int size;

    // get mid val of range
    int getMid(int &start, int &end)
    {
        return (start + ((end - start) >> 1));
    }

    // build segment tree from raw array
    void build(vector<int> &arr, int start, int end, int idx)
    {
        if (start == end)
            tree[idx] = arr[start];
        else
        {
            int mid = getMid(start, end);
            int leftChild = idx << 1;
            int rightChild = leftChild + 1;
            build(arr, start, mid, leftChild);
            build(arr, mid + 1, end, rightChild);
            tree[idx] = tree[leftChild] + tree[rightChild];
        }
    }

    // get sum of range left-right
    int rangeQueryHelper(int left, int right, int start, int end, int idx)
    {
        if (left > end || right < start)
            return 0;
        if (left <= start && right >= end)
            return tree[idx];
        int mid = getMid(start, end);
        int leftChild = idx << 1;
        return rangeQueryHelper(left, right, start, mid, leftChild) + rangeQueryHelper(left, right, mid + 1, end, leftChild + 1);
    }

    // update val at specific pos
    void updateHelper(int pos, int start, int end, int val, int idx)
    {
        if (start == end)
            tree[idx] = val;
        else
        {
            int mid = getMid(start, end);
            int leftChild = idx << 1;
            int rightChild = leftChild + 1;
            if (pos <= mid)
                updateHelper(pos, start, mid, val, leftChild);
            else
                updateHelper(pos, mid + 1, end, val, rightChild);
            tree[idx] = tree[leftChild] + tree[rightChild];
        }
    }
    void displayHelper(int start, int end, int idx)
    {
        if (start == end)
            cout << tree[idx]<<" ";
        else
        {
            int mid = getMid(start, end);
            int leftChild = idx << 1;
            displayHelper(start, mid, leftChild);
            displayHelper(mid + 1, end, leftChild + 1);
        }
    }

public:
    SegmentTree(vector<int> &arr)
    {
        size = arr.size();
        tree.resize((size << 1));
        build(arr, 0, size - 1, 1);
    }
    int rangeQuery(int left, int right)
    {
        return rangeQueryHelper(left, right, 0, size - 1, 1);
    }
    void update(int pos, int val)
    {
        updateHelper(pos, 0, size - 1, val, 1);
    }
    void display()
    {
        cout << endl;
        displayHelper(0,size-1,1);
        cout << endl;
    }
};

int main(){
    int size;
    cout << "Enter size: ";
    cin >> size;
    cout << "Enter elements: " << endl;
    vector<int> arr(size);
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    SegmentTree st(arr);
    cout << "Instructions: " << endl;
    cout << "query <left> <right>: for range query" << endl;
    cout << "display" << endl;
    cout << "update <idx> <val>" << endl;
    cout << "exit" << endl;
    while (true)
    {
        string s;
        cin >> s;
        if(s=="exit")
            break;
        else if(s=="update"){
            int idx, val;
            cin >> idx >> val;
            st.update(idx, val);
        }
        else if(s=="display"){
            st.display();
        }
        else if(s=="query"){
            int left, right;
            cin >> left >> right;
            cout << "Sum: " << st.rangeQuery(left, right) << endl;
        }
        else
            cout << "Invalid instruction!" << endl;
    }
    
}