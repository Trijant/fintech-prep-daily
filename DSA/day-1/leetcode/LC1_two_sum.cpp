#include <iostream>
using namespace std;

//Time complexity= O(n^2)
//Space complexity= O(1)
int *twosum(int arr[],int size,int target)
{
    int *ans=new int[2]{-1,-1};
    for (int i = 0; i < size - 1;i++){
        for (int j = i+1; j < size; j++)
        {
            if (arr[i]+arr[j]==target)
            {
                ans[0] = i;
                ans[1] = j;
                break;
            }
            
        }
    }
    return ans;
}

int main(){
    int size,target;
    cout << "Enter arr size: ";
    cin >> size;
    int *arr=new int[size];
    cout << endl
         << "Enter array elements: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << endl
         << "Enter target:";
    cin >> target;
    cout << "Ans: ";
    int *ans=twosum(arr, size, target);
    cout << ans[0] << ", " << ans[1];
    delete[] ans;
    delete[] arr;
}