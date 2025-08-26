#include <iostream>
#include <chrono>
#include <cstdio>
using namespace std;
using namespace std::chrono;

void print_with_simple_cout(int n){
    for (int i = 0; i < n; i++)
    {
        cout << "hi" << endl;
    }
}
void print_with_simple_cout_without_endl(int n){
    for (int i = 0; i < n; i++)
    {
        cout << "hi\n";
    }
}
void print_with_unsync_cout(int n){
    ios::sync_with_stdio(false);
    for (int i = 0; i < n; i++)
    {
        cout << "hi\n";
    }
    ios::sync_with_stdio(true);
}
void print_with_printf(int n){
    for (int i = 0; i < n; i++)
    {
        printf("hi\n");
    }
}
void print_with_write(int n){
    for (int i = 0; i < n; i++)
    {
        cout.write("hi\n",3);
    }
}
void print_with_fwrite(int n){
    string s;
    s.reserve(n * 3);
    for (int i = 0; i < n; i++)
    {
        s += "hi\n";
    }
    fwrite(s.c_str(),1,s.size(),stdout);
}
void print_with_put(int n){
    for (int i = 0; i < n; i++)
    {
        cout.put('h');
        cout.put('i');
        cout.put('\n');
    }
}

int main(){
    int output_size = 1000;
    auto start1 = high_resolution_clock::now();
    print_with_simple_cout(output_size);
    auto end1 = high_resolution_clock::now();

    auto start2 = high_resolution_clock::now();
    print_with_simple_cout_without_endl(output_size);
    auto end2 = high_resolution_clock::now();

    auto start3 = high_resolution_clock::now();
    print_with_printf(output_size);
    auto end3 = high_resolution_clock::now();

    auto start4 = high_resolution_clock::now();
    print_with_unsync_cout(output_size);
    auto end4 = high_resolution_clock::now();

    auto start5 = high_resolution_clock::now();
    print_with_write(output_size);
    auto end5 = high_resolution_clock::now();

    auto start6 = high_resolution_clock::now();
    print_with_put(output_size);
    auto end6 = high_resolution_clock::now();

    auto start7 = high_resolution_clock::now();
    print_with_fwrite(output_size);
    auto end7 = high_resolution_clock::now();

    auto duration1 = duration_cast<microseconds>(end1 - start1);
    auto duration2 = duration_cast<microseconds>(end2 - start2);
    auto duration3 = duration_cast<microseconds>(end3 - start3);
    auto duration4 = duration_cast<microseconds>(end4 - start4);
    auto duration5 = duration_cast<microseconds>(end5 - start5);
    auto duration6 = duration_cast<microseconds>(end6 - start6);
    auto duration7 = duration_cast<microseconds>(end7 - start7);

    cout << endl;
    cout << "normal cout with endl: " << duration1.count() << endl;
    cout << "normal cout with \\n: " << duration2.count() << endl;
    cout << "printf: " << duration3.count() << endl;
    cout << "unsync cout with \\n: " << duration4.count() << endl;
    cout << "write(): " << duration5.count() << endl;
    cout << "put(): " << duration6.count() << endl;
    cout << "fwrite(): " << duration7.count() << endl;
}