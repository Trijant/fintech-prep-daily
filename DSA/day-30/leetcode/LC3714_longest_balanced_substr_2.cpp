#include <bits/stdc++.h>
using namespace std;

// topic: freq arr + sliding window

class Solution
{
public:
    int longestBalanced(string s)
    {
        int n = s.size();
        int pa = 0, pb = 0, pc = 0;
        long long base = 50000; // to avoid negative numbers
        auto encode = [&](int n1, int n2)
        {
            return ((n1 + base) << 32) | (n2 + base);
        };
        unordered_map<long long, int> dict3, dict_ab, dict_ac, dict_bc;
        long long key = encode(0, 0);
        dict3[key] = dict_ab[key] = dict_ac[key] = dict_bc[key] = 0;
        int ans = 0;
        char run_char = '\0';
        int run_len = 0;
        for (int i = 1; i <= n; i++)
        {
            char ch = s[i - 1];
            if (ch == 'a')
                pa++;
            else if (ch == 'b')
                pb++;
            else
                pc++;

            // all three characters
            long long key3 = ((long long)(pa - pb + base) << 32) | (pa - pc + base);
            if (dict3.count(key3))
                ans = max(ans, i - dict3[key3]);
            else
                dict3[key3] = i;

            // a and b only
            long long key_ab = ((long long)(pa - pb + base) << 32) | pc + base;
            if (dict_ab.count(key_ab))
                ans = max(ans, i - dict_ab[key_ab]);
            else
                dict_ab[key_ab] = i;

            // a and c only
            long long key_ac = ((long long)(pa - pc + base) << 32) | pb + base;
            if (dict_ac.count(key_ac))
                ans = max(ans, i - dict_ac[key_ac]);
            else
                dict_ac[key_ac] = i;

            // b and c only
            long long key_bc = encode(pb - pc, pa);
            if (dict_bc.count(key_bc))
                ans = max(ans, i - dict_bc[key_bc]);
            else
                dict_bc[key_bc] = i;

            // single character run
            if (ch == run_char)
                run_len++;
            else
            {
                run_char = ch;
                run_len = 1;
            }
            ans = max(ans, run_len);
        }

        return ans;
    }
};

int main()
{
    string s;
    cout << "Enter s: ";
    cin >> s;
    Solution sl;
    cout << "Ans: " << sl.longestBalanced(s);
}