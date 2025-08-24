#include <iostream>
using namespace std;

// Time complexity = O(n)
// Space complexity = O(1)
// Works for both sorted and unsorted arrays
int removeElement(int arr[],int size,int element){
    int i = 0;
    for (int j = 0; j < size; j++)
    {
        if (arr[j]!=element)
        {
            arr[i++] = arr[j];
        }
    }
    return i;
}

int main(){
    
    int size,element;
    cout << "Enter arr size: ";
    cin >> size;
    int *arr=new int[size];
    cout << endl
         << "Enter array elements: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter target element: ";
    cin >> element;
    size = removeElement(arr, size, element);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    delete[] arr;
}