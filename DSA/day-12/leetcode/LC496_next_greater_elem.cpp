#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// topic: stack + map
// time-complexity: O(n)
// space-complexity: O(n)

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    unordered_map<int, int> mp;
    int size = nums2.size();
    vector<int> nextGreater(size, -1);
    mp[nums2.back()] = -1;
    for (int i = size - 2; i >= 0; i--)
    {
        int j = i + 1;
        while (j != -1 && j < size && nums2[j] < nums2[i])
        {
            j = nextGreater[j];
        }
        nextGreater[i] = j;
        mp[nums2[i]] = (j == -1) ? -1 : nums2[j];
    }

    vector<int> ans;
    ans.reserve(nums1.size());
    for (int num : nums1)
    {
        ans.push_back(mp[num]);
    }
    return ans;
}

int main(){
    int size1, size2;
    cout << "Enter size of nums1:";
    cin >> size1;
    vector<int> nums1(size1);
    cout << "Enter elements of nums1:"<<endl;
    for (int i = 0; i < size1; i++)
    {
        cin >> nums1[i];
    }
    
    cout << "Enter size of nums2:";
    cin >> size2;
    vector<int> nums2(size2);
    cout << "Enter elements of nums1:"<<endl;
    for (int i = 0; i < size2; i++)
    {
        cin >> nums2[i];
    }
    vector<int> ans = nextGreaterElement(nums1, nums2);
    cout << "Next greater element:" << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    
}