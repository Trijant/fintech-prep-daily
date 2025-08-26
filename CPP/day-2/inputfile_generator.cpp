#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main(){

    int no_of_input=100000, test_count=8;
    ostringstream oss;
    for (int i = 0; i < test_count; i++)
    {
        for (int j = 0; j < no_of_input; j++)
        {
            oss << "a ";
        }        
    }
    oss << "a ";
    ofstream fout("input.txt");
    fout << oss.str();
    fout.close();
}