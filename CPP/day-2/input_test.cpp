#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

// command to run this file: 
// g++ .\inputfile_generator.cpp
// >> ./a
// >> g++ input_test.cpp
// >> Get-Content ./input.txt | ./a.exe

void classic_cin(int no_of_inputs){
    char c[no_of_inputs];
    for (int i = 0; i < no_of_inputs; i++)
    {
        cin >> c[i];
    }
}
void unsync_cin(int no_of_inputs){
    ios::sync_with_stdio(false);
    char c[no_of_inputs];
    for (int i = 0; i < no_of_inputs; i++)
    {
        cin >> c[i];
    }
    ios::sync_with_stdio(true);
}
void untie_cin(int no_of_inputs){
    cin.tie(nullptr);
    char c[no_of_inputs];
    for (int i = 0; i < no_of_inputs; i++)
    {
        cin >> c[i];
    }
    cin.tie(&cout);
}
void untie_with_unsync_cin(int no_of_inputs){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    char c[no_of_inputs];
    for (int i = 0; i < no_of_inputs; i++)
    {
        cin >> c[i];
    }
    cin.tie(&cout);
    ios::sync_with_stdio(true);
}
void getchar_input(int no_of_inputs){
    char c[no_of_inputs];
    for (int i = 0; i < no_of_inputs; i++)
    {
        c[i]=getchar();
    }
}
void get_input(int no_of_inputs){
    char c[no_of_inputs];
    for (int i = 0; i < no_of_inputs; i++)
    {
        c[i]=cin.get();
        cin.get();
    }
}
void scanf_input(int no_of_inputs){
    char c[no_of_inputs];
    for (int i = 0; i < no_of_inputs; i++)
    {
        scanf(" %c",&c[i]);
    }
}
void getline_input(int no_of_inputs){
    char c[no_of_inputs];
    for (int i = 0; i < no_of_inputs; i++)
    {
        cin.getline(&c[i],1,' ');
    }
}
void getchar_unlocked_input(int no_of_inputs){
    char c[no_of_inputs];
    for (int i = 0; i < no_of_inputs; i++)
    {
        ;
    }
}


int main(){
    int no_of_inputs = 100000;

    char temp;
    cin >> temp;

    auto start1 = high_resolution_clock::now();
    classic_cin(no_of_inputs);
    auto end1 = high_resolution_clock::now();

    auto start2 = high_resolution_clock::now();
    unsync_cin(no_of_inputs);
    auto end2 = high_resolution_clock::now();

    auto start3 = high_resolution_clock::now();
    untie_cin(no_of_inputs);
    auto end3 = high_resolution_clock::now();

    auto start4 = high_resolution_clock::now();
    untie_with_unsync_cin(no_of_inputs);
    auto end4 = high_resolution_clock::now();

    auto start5 = high_resolution_clock::now();
    getchar_input(no_of_inputs);
    auto end5 = high_resolution_clock::now();

    auto start6 = high_resolution_clock::now();
    get_input(no_of_inputs);
    auto end6 = high_resolution_clock::now();

    auto start7 = high_resolution_clock::now();
    scanf_input(no_of_inputs);
    auto end7 = high_resolution_clock::now();

    auto start8 = high_resolution_clock::now();
    getline_input(no_of_inputs);
    auto end8 = high_resolution_clock::now();

    auto start9 = high_resolution_clock::now();
    getchar_unlocked_input(no_of_inputs);
    auto end9 = high_resolution_clock::now();

    auto duration1 = duration_cast<microseconds>(end1 - start1);
    auto duration2 = duration_cast<microseconds>(end2 - start2);
    auto duration3 = duration_cast<microseconds>(end3 - start3);
    auto duration4 = duration_cast<microseconds>(end4 - start4);
    auto duration5 = duration_cast<microseconds>(end5 - start5);
    auto duration6 = duration_cast<microseconds>(end6 - start6);
    auto duration7 = duration_cast<microseconds>(end7 - start7);
    auto duration8 = duration_cast<microseconds>(end8 - start8);

    cout << endl;
    cout << "normal cin: " << duration1.count() << endl;
    cout << "unsync cin: " << duration2.count() << endl;
    cout << "untie cin: " << duration3.count() << endl;
    cout << "unsync + untie cin: " << duration4.count() << endl;
    cout << "getchar(): " << duration5.count() << endl;
    cout << "get(): " << duration6.count() << endl;
    cout << "scanf(): " << duration7.count() << endl;
    cout << "getline(): " << duration8.count() << endl;
}