#include<bits/stdc++.h>
using namespace std;

// topic: prim's algo + graph

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int size = points.size();
        vector<bool> relaxed(size, false);
        vector<int> minDist(size, INT_MAX);
        minDist[0] = 0;
        int ans = 0;

        for (int i = 0; i < size; i++) {
            int mn = 0;
            int mnVal = INT_MAX;
            for (int j = 0; j < size; j++)
                if (!relaxed[j] && minDist[j] < mnVal) {
                    mn = j;
                    mnVal = minDist[j];
                }
            relaxed[mn] = true;
            ans += mnVal;
            for (int j = 0; j < size; j++) {
                if (!relaxed[j]) {
                    int newDist = abs(points[j][0] - points[mn][0]) +
                                  abs(points[j][1] - points[mn][1]);
                    if (newDist < minDist[j])
                        minDist[j] = newDist;
                }
            }
        }

        return ans;
    }
};

int main(){
    int size;
    cout<<"Enter size: ";
    cin>>size;
    cout<<"Enter points: "<<endl;
    vector<vector<int>>points(size,vector<int>(2));
    for (int i = 0; i < size; i++)
    {
        cin >> points[i][0] >> points[i][1];
    }
    Solution s;
    cout << "Min cost: " << s.minCostConnectPoints(points) << endl;
    
}