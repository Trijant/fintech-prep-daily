#ifndef ARRAYUTILS_H
#define ARRAYUTILS_H

namespace arrayutils{    
    int insert(int arr[], int &size, int element, int position,int capacity);
    int deleteAt(int arr[], int &size, int position);
    int search(int arr[], int size, int element);
    void display(int arr[], int size);
}

#endif