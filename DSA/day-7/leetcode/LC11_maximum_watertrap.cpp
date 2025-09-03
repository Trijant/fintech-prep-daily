#include<iostream>
#include<vector>
using namespace std;

// TOPIC: two pointer
// Time-complexity: O(n)
// Space-complexity:O(1)

int maxArea(vector<int> &height)
{
    int maxWater = 0, left = 0, right = height.size() - 1;
    while (left < right)
    {
        // possible water trap between 2 pointers is width*min_height
        int currentWater = (right - left) * min(height[left], height[right]);

        // updating maxWater trapped
        maxWater = max(maxWater, currentWater);

        // updating pointer of min_height pointer in hope of getting bigger height(greedy approach)
        if (height[left] < height[right])
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return maxWater;
}

int main(){
    int size;
    cout << "Enter size of array: ";
    cin >> size;
    cout << "Enter array elements: "<<endl;
    vector<int> height(size);
    for (int i = 0; i < size; i++)
    {
        cin >> height[i];
    }
    cout << "Max water trapped : " << maxArea(height);
}