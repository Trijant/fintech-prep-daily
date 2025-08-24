#include <iostream>
using namespace std;

// Timecomplexity= O(n)
// Spacecomplexity= O(1)
// This only works for sorted array only!
void removeDuplicateElements(int arr[], int &size){
    int i = 1;
    for (int j = 1; j < size; j++)
    {
        if (arr[j]!=arr[j-1])
        {
            arr[i++] = arr[j];
        }
    }
    size = i;
}

int main(){
    
    int size;
    cout << "Enter arr size: ";
    cin >> size;
    int *arr=new int[size];
    cout << endl
         << "Enter array elements: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    removeDuplicateElements(arr, size);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    delete[] arr;
}