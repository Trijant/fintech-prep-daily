#include<iostream>
#include<vector>
using namespace std;

// topic: stack
// time-complexity: O(n)
// space-complexity: O(n)

vector<int> dailyTemperatures(vector<int> &temperatures)
{
    int size = temperatures.size();
    vector<int> st;
    st.reserve(size);
    vector<int> ans(size, 0);
    for (int i = size - 1; i >= 0; i--)
    {
        int currentTemp = temperatures[i];
        while ((!st.empty()) && temperatures[st.back()] <= currentTemp)
        {
            st.pop_back();
        }
        if (!st.empty())
        {
            ans[i] = st.back() - i;
        }
        st.push_back(i);
    }
    return ans;
}

int main(){
    int size;
    cout << "Enter size: ";
    cin >> size;
    cout << "Enter temperatures: "<<endl;
    vector<int> temperatures(size);
    for (int i = 0; i < size; i++)
    {
        cin >> temperatures[i];
    }
    cout << "No. of days to wait for next warmer day" << endl;
    vector<int> ans = dailyTemperatures(temperatures);
    for (int i = 0; i < size; i++)
    {
        cout << ans[i] << " ";
    }
    
}