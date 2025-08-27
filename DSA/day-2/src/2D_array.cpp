#include <iostream>
using namespace std;

// This is the best way to access 2d array in function as we accept as 1d array only and at memory level also we have just 1 contiguous memory

void display_arr(int *arr,int size1,int size2){
    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            cout << arr[i*size2+j]<<" ";
        }
        cout << endl;
    }
}
int main(){
    int arr[][2] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << arr<<endl;
    cout << arr[0]<<endl;
    cout << &arr[0][0]<<endl;
    display_arr(&arr[0][0], 5, 2); // this flatterns array
    display_arr(arr[0], 5, 2);      // this is also flatterning
    // display_arr(arr, 5, 2); this is wrong

}