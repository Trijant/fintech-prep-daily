#include<iostream>
#include<vector>
using namespace std;

// topic: deque + sliding window
// time-complexity: O(n)
// space-complexity: O(n)

    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int size = nums.size();
        vector<int> maxQueue(size);
        vector<int> ans(size - k + 1);
        int left = 0, front = 0, rear = -1;
        for (int i = 0; i < k; i++)
        {
            int cur = nums[i];
            while (front <= rear && cur > nums[maxQueue[rear]])
            {
                rear--;
            }
            maxQueue[++rear] = i;
        }
        ans[0] = nums[maxQueue[front]];
        for (int right = k; right < size; right++)
        {
            if (maxQueue[front] == left)
            {
                front++;
            }
            left++;
            int cur = nums[right];
            while (rear >= front && cur > nums[maxQueue[rear]])
            {
                rear--;
            }
            maxQueue[++rear] = right;
            ans[left] = nums[maxQueue[front]];
        }
        return ans;
    }


    int main(){
        int size, k;
        cout << "Enter size of array: ";
        cin >> size;
        vector<int> nums(size);
        cout << "Enter array elements:" << endl;
        for (int i = 0; i < size; i++)
        {
            cin >> nums[i];
        }
        cout << "Enter window size: ";
        cin >> k;
        vector<int> ans = maxSlidingWindow(nums, k);
        cout << "Ans: " << endl;
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
    }