#include<iostream>
#include<vector>
using namespace std;

// TOPIC: STRING MANIPULATION
// time-complexity: O(n)
// space-complexity: O(1)

void reverseString(vector<char> &s)
{
    int left = 0, right = s.size() - 1;
    while (left < right)
    {
        // swapping left and right char
        char temp = s[left];
        s[left++] = s[right];
        s[right--] = temp;
    }
}

int main(){
    vector<char> str;
    cout << "Enter string: ";
    char ch=getchar();
    while (ch!='\n'&&ch!=EOF)
    {
        str.push_back(ch);
        ch = getchar();
    }
    reverseString(str);
    for (int i = 0; i < str.size(); i++)
    {
        cout << str[i];
    }
    
}