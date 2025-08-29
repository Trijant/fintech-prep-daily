#include<iostream>
#include<vector>
#include<map>
using namespace std;

// Time-complexity: O(nlog(n))
// Space-complexity: O(n)

int subArrSum(vector<int> arr,int k){
    map<int, int> mp;
    mp[0] = 1;
    int prefix_sum = 0,count=0;
    for (int i = 0; i < arr.size(); i++){
        prefix_sum += arr[i];
        if(mp.count(prefix_sum-k)){
            count += mp[prefix_sum - k];
        }
        mp[prefix_sum]++;
    }
    return count;
}

int main()
{
    int size,target;
    cout << "Enter size of array: ";
    cin >> size;
    vector<int> arr(size);
    cout << "Enter elements of array: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter target: ";
    cin >> target;
    cout << "Count of subarray whose sum is "<<target<<" are: " << subArrSum(arr,target);
}