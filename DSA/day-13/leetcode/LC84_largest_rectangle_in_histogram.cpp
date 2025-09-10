#include<iostream>
#include<vector>
using namespace std;

// topic:stack
// time-complexity:O(n)
// space-complexity:O(n)

int largestRectangleArea(const vector<int> &heights)
{
    int n = heights.size();
    int st[100001];
    int top = -1, maxArea = 0;

    for (int i = 0; i <= n; i++)
    {
        int h = (i == n ? 0 : heights[i]);
        while (top >= 0 && heights[st[top]] > h)
        {
            int height = heights[st[top--]];
            int width = i - (top >= 0 ? st[top] : -1) - 1;
            int area = height * width;
            if (area > maxArea)
                maxArea = area;
        }
        st[++top] = i;
    }
    return maxArea;
}

int main(){
    int size;
    cout << "Enter size of array: ";
    cin >> size;
    cout << "Enter element of array: " << endl;
    vector<int> heights(size);
    for (int i = 0; i < size; i++)
    {
        cin >> heights[i];
    }
    cout << "Largest rectangle area: " << largestRectangleArea(heights);
}