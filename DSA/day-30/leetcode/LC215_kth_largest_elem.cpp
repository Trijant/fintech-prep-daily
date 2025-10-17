#include<iostream>
#include<vector>
using namespace std;

// topic: heap



class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        int size = nums.size();
        int end = (size >> 1) - 1;
        auto heapify = [&](int idx)
        {
            while (idx <= end)
            {
                int leftChild = (idx << 1) + 1;
                int rightChild = leftChild + 1;
                if (rightChild < size &&
                    nums[rightChild] > nums[leftChild] &&
                    nums[rightChild] > nums[idx])
                {
                    swap(nums[rightChild], nums[idx]);
                    idx = rightChild;
                }
                else if (nums[leftChild] > nums[idx])
                {
                    swap(nums[leftChild], nums[idx]);
                    idx = leftChild;
                }
                else
                    break;
            }
        };

        for (int i = ((nums.size() >> 1) - 1); i >= 0; i--)
            heapify(i);

        auto pop = [&]()
        {
            int n = nums[0];
            size--;
            end = (size >> 1) - 1;
            nums[0] = nums[size];
            heapify(0);
            return n;
        };
        int ans;
        while (k--)
            ans = pop();
        return ans;
    }
};

// quick sort type searching (FASTEST)

class Solution2
{
private:
    int quickSortSearch(vector<int> &nums, int idx, int start, int end)
    {
        if (start >= end)
            return nums[end];
        int pivotIdx = start + rand() % (end - start + 1);
        swap(nums[pivotIdx], nums[start]);
        int left = start + 1, right = end, pivot = start;
        while (left <= right)
        {
            while (left <= end && nums[left] < nums[pivot])
                left++;
            while (right > start && nums[right] > nums[pivot])
                right--;
            if (left <= right)
                swap(nums[left++], nums[right--]);
        }
        swap(nums[pivot], nums[right]);
        if (right == idx)
            return nums[right];
        else if (right < idx)
            return quickSortSearch(nums, idx, right + 1, end);
        else
            return quickSortSearch(nums, idx, start, right - 1);
    }

public:
    int findKthLargest(vector<int> &nums, int k)
    {
        return quickSortSearch(nums, nums.size() - k, 0, nums.size() - 1);
    }
};

int main(){
    int size, k;
    cout << "Enter size: ";
    cin >> size;
    cout << "Enter k: ";
    cin >> k;
    cout<<"Enter elements: "<<endl;
    vector<int> nums(size);
    for (int i = 0; i < size; i++)
    {
        cin >> nums[i];
    }
    Solution s;
    cout << "Kth largest element: " << s.findKthLargest(nums, k);
    Solution2 s2;
    cout << "Kth largest element: " << s2.findKthLargest(nums, k);
    
}