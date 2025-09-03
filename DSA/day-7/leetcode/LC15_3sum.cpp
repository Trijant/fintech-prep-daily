#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> triplet;
    triplet.reserve(3000); // approximate upper bound
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<int> temp(3); // reusable vector

    for (int i = 0; i < n - 2; i++)
    {
        // skipping repeated number
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        int val1 = nums[i];
        // for value greater than 0 there is no triplet possible because of sorted array
        if (val1 > 0)
            break;

        int left = i + 1, right = n - 1;
        int target = -val1;

        while (left < right)
        {
            int current_sum = nums[left] + nums[right];
            if (current_sum == target)
            {
                temp[0] = val1;
                temp[1] = nums[left];
                temp[2] = nums[right];
                triplet.emplace_back(temp);

                int lval = nums[left], rval = nums[right];
                // updating pointers until we get new number
                do
                {
                    left++;
                } while (left < right && nums[left] == lval);
                do
                {
                    right--;
                } while (left < right && nums[right] == rval);
            }
            else if (current_sum < target)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }
    return triplet;
}

int main(){
    int size;
    cout << "Enter size of arr: ";
    cin >> size;
    cout << "Enter elements of arr: "<<endl;
    vector<int> nums(size);
    for (int i = 0; i < size; i++)
    {
        cin >> nums[i];
    }
    vector<vector<int>> triplets = threeSum(nums);
    cout << "Triplets with sum 0:" << endl;
    for (int i = 0; i < triplets.size(); i++)
    {
        cout << triplets[i][0] << " " << triplets[i][1] << " " << triplets[i][2] << endl;
    }
    
}