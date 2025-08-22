#include <iostream>
#include "../include/Mathutils.h"
using namespace std;

int main(){
    int num1 = 5, num2 = 6;
    cout <<"addition of "<<num1<<" and "<<num2<<" is "<< mathutils::add(num1,num2)<<endl;
    cout <<"multiplication of "<<num1<<" and "<<num2<<" is "<< mathutils::multiply(num1,num2)<<endl;
}