#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// TOPIC: SLIDING WINDOW
// Time-complexity: O(n)
// Space-complexity: O(1)

int minSubArrayLen(int target, vector<int> &nums)
{
    int left = 0, currentSum = 0, minLength = INT_MAX;
    for (int right = 0; right < nums.size(); right++)
    {
        currentSum += nums[right];
        while (currentSum >= target)
        {
            minLength = min(minLength, right - left + 1);
            currentSum -= nums[left];
            left++;
        }
    }
    if (minLength == INT_MAX)
    {
        return 0;
    }
    return minLength;
}

int main(){
    int size, target;
    cout << "Enter size of array: ";
    cin >> size;
    cout << "Enter arr elements: " << endl;
    vector<int> arr(size);
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter target: ";
    cin >> target;
    cout << "Min length of subarr with sum >= target: " << minSubArrayLen(target, arr);
}