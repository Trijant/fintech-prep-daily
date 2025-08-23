#include "../include/Arrayutils.h"
#include <iostream>

namespace arrayutils{
    int insert(int arr[],int &size, int element, int position, int capacity=100){
        if (size>=capacity)
        {
            return -2;
        }
        else if (position<0 || position > size)
        {
            return -1;
        }
        
        int i = size;
        for (; i > position; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[i] = element;
        ++size;
        return 0;
    }
    int deleteAt(int arr[],int &size, int position){
        if (position<0 || position >= size)
        {
            return -1;
        }
        
        for (int i=position; i < size-1; i++)
        {
            arr[i] = arr[i + 1];
        }
        --size;
        return 0;
    }
    int search(int arr[],int size,int element){
        for (int i = 0; i < size; i++)
        {
            if (arr[i]==element)
            {
                return i;
            }
            
        }
        return -1;
    }
    void display(int arr[], int size){
        for (int i = 0; i < size; i++)
        {
            std::cout << arr[i] << "  ";
        }
        std::cout << std::endl;
    }
}