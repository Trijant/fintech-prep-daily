#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Time-complexity: O(n)
// Space-complexity: O(1)

int maximumSum(vector<int> &arr)
{
    int n = arr.size();
    int noDelete = arr[0];
    int oneDelete = 0;
    int ans = arr[0];
    for (int i = 1; i < n; i++)
    {
        oneDelete = max(noDelete, oneDelete + arr[i]);
        noDelete = max(arr[i], noDelete + arr[i]);
        ans = max(ans, max(noDelete, oneDelete));
    }
    return ans;
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
    cout << "Max sum of subarray is: " << maximumSum(arr);
}