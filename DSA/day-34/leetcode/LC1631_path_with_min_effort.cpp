#include<bits/stdc++.h>
using namespace std;

// topic: dijkstra's algo + graph + min heap + set

class Solution
{
private:
    inline long long encode(int i, int j, int d)
    {
        return ((long long)d << 32) | i << 16 | j;
    }

public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int size = heights.size();
        int rowSize = heights[0].size();

        vector<vector<bool>> relaxed(size, vector<bool>(rowSize, false));

        priority_queue<long long, vector<long long>, greater<long long>> pq;
        pq.push(encode(0, 0, 0));

        while (!pq.empty())
        {
            long long code = pq.top();
            pq.pop();
            int dist = code >> 32;
            int cord = code;
            int i = cord >> 16;
            int j = cord & 0x0000ffff;
            if (!relaxed[i][j])
            {
                relaxed[i][j] = true;
                if (j > 0 && !relaxed[i][j - 1])
                    pq.push(encode(
                        i, j - 1,
                        max(dist, abs(heights[i][j] - heights[i][j - 1]))));
                if (i > 0 && !relaxed[i - 1][j])
                    pq.push(encode(
                        i - 1, j,
                        max(dist, abs(heights[i][j] - heights[i - 1][j]))));
                if (i < size - 1 && !relaxed[i + 1][j])
                    pq.push(encode(
                        i + 1, j,
                        max(dist, abs(heights[i][j] - heights[i + 1][j]))));
                if (j < rowSize - 1 && !relaxed[i][j + 1])
                    pq.push(encode(
                        i, j + 1,
                        max(dist, abs(heights[i][j] - heights[i][j + 1]))));
                if (i == size - 1 && j == rowSize - 1)
                    return dist;
            }
        }
        return -1;
    }
};

int main(){
    int size, rowSize;
    cout<<"Enter size: ";
    cin>>size;
    cout << "Enter row size: ";
    cin >> rowSize;
    vector<vector<int>> heights(size, vector<int>(rowSize));
    cout << "Enter heights: " << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < rowSize; j++)
        {
            cin >> heights[i][j];
        }
    }
    Solution s;
    cout << "Effort: " << s.minimumEffortPath(heights) << endl;
}