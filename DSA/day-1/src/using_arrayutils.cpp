#include <iostream>
#include "../include/Arrayutils.h"
using namespace std;

int main(){
    int capacity = 100;
    int arr[capacity];
    int size = 0;
    arrayutils::insert(arr, size, 5, 0,capacity);
    arrayutils::insert(arr, size, 15, 1,capacity);
    arrayutils::insert(arr, size, 20, 1,capacity);
    arrayutils::insert(arr, size, 25, 1,capacity);
    arrayutils::display(arr, size);
    arrayutils::deleteAt(arr, size, 0);
    arrayutils::display(arr, size);
    cout<<arrayutils::search(arr, size, 20)<<endl;
    cout << arrayutils::search(arr, size, 5) << endl;
}