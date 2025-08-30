#include <iostream>
#include <vector>
using namespace std;

// Time-complexity: O(n+m)
// Space-complexity: O(n)

vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    int freqArr[1001]{0};
    vector<int> ans;
    for (int i = 0; i < nums1.size(); i++)
    {
        freqArr[nums1[i]]++;
    }
    for (int i = 0; i < nums2.size(); i++)
    {
        if (freqArr[nums2[i]])
        {
            ans.push_back(nums2[i]);
            freqArr[nums2[i]]--;
        }
    }
    return ans;
}

int main()
{
    int size1, size2;
    cout << "Enter size of first array: ";
    cin >> size1;
    vector<int> arr1(size1);
    cout << "Enter elements of first array: " << endl;
    for (int i = 0; i < size1; i++)
    {
        cin >> arr1[i];
    }
    cout << "Enter size of second array: ";
    cin >> size2;
    vector<int> arr2(size2);
    cout << "Enter elements of second array: " << endl;
    for (int i = 0; i < size2; i++)
    {
        cin >> arr2[i];
    }
    vector<int> ans = intersection(arr1, arr2);
    cout << "Intersection with unique elements is: " << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}