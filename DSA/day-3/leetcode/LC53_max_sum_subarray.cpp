#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(vector<int> &nums)
{
    if(nums.size()==0){
        return 0;
    }
    int curr_sum = nums[0];
    int max_sum = curr_sum;
    for (int i = 1; i < nums.size(); i++)
    {
        if (curr_sum <= 0)
        {
            curr_sum = nums[i];
        }
        else
        {
            curr_sum += nums[i];
        }
        if (curr_sum > max_sum)
        {
            max_sum = curr_sum;
        }
    }
    return max_sum;
}

int main(){
    int size;
    cout << "Enter size of array: ";
    cin >> size;
    vector<int> arr(size);
    cout << "Enter elements of array: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << "Max sum of subarray is: " << maxSubArray(arr);
}