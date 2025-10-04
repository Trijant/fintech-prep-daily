#include<iostream>
#include<unordered_set>
using namespace std;

// topic: bit operation + set

class Solution
{
private:
    void movePoint(int &x, int &y, char ch, int sign = 1)
    {
        if (ch == 'U')
            x += sign;
        else if (ch == 'D')
            x -= sign;
        else if (ch == 'L')
            y -= sign;
        else
            y += sign;
    }
    long long getKey(int &x, int &y) const
    {
        return ((long long)(unsigned)x << 32) | (unsigned)y;
    }

public:
    int distinctPoints(string s, int k)
    {
        unordered_set<long long> endPoints;
        endPoints.reserve(s.size());
        int x = 0, y = 0;
        for (int i = 0; i < k; i++)
        {
            movePoint(x, y, s[i]);
        }
        endPoints.insert(getKey(x, y));
        int left = 0;
        for (int i = k; i < s.size(); i++)
        {
            movePoint(x, y, s[i]);
            movePoint(x, y, s[left], -1);
            endPoints.insert(getKey(x, y));
            left++;
        }
        return endPoints.size();
    }
};

int main(){
    string str;
    int k;
    cout << "Enter Str containing U D L R: ";
    cin >> str;
    cout<<"Enter k: ";
    cin >> k;
    Solution s;
    cout << "Total distinct endpoints: " << s.distinctPoints(str, k);
}