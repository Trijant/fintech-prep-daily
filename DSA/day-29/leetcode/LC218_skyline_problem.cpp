#include<iostream>
#include<vector>
#include<cstdint>
#include<algorithm>
using namespace std;

// topic: bit packing + unique elem + sorting + mapping + interval + range updates + bit manipulation

class Solution
{
private:
    uint64_t encode(uint64_t height, uint64_t x, uint64_t event)
    {

        x <<= 32;
        event <<= 31;
        if (!event)
            height ^= 0x7FFFFFFF;
        return x | event | height;
    }

public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
    {
        size_t size = buildings.size();
        vector<int> heights;
        heights.reserve(size + 1);
        heights.push_back(0);
        for (auto &building : buildings)
        {
            heights.push_back(building[2]);
        }
        sort(heights.begin(), heights.end());
        heights.erase(unique(heights.begin(), heights.end()), heights.end());
        auto rankOf = [&](int height)
        {
            return lower_bound(heights.begin(), heights.end(), height) - heights.begin();
        };
        vector<uint64_t> points;
        points.reserve(size << 1);
        for (auto &building : buildings)
        {
            int heightRank = rankOf(building[2]);
            points.push_back(encode(heightRank, building[0], 0));
            points.push_back(encode(heightRank, building[1], 1ULL));
        }
        sort(points.begin(), points.end());
        vector<int> freq(heights.size(), 0);
        uint32_t maxHeight = 0;
        vector<vector<int>> ans;
        ans.reserve(size << 1);
        for (auto &p : points)
        {
            uint32_t curHeight = p;
            uint32_t code = p & 0x80000000;
            if (!code)
                curHeight ^= 0x7FFFFFFF;
            curHeight &= 0x7FFFFFFF;
            uint64_t x = p >> 32;
            if (!code)
            {
                freq[curHeight]++;
                if (curHeight > maxHeight)
                {
                    maxHeight = curHeight;
                    ans.push_back({(int)x, heights[curHeight]});
                }
            }
            else
            {
                freq[curHeight]--;
                if (!freq[maxHeight])
                {
                    while (maxHeight && !freq[maxHeight])
                        maxHeight--;
                    ans.push_back({(int)x, heights[maxHeight]});
                }
            }
        }
        return ans;
    }
};

int main(){
    int n;
    cout << "Enter n: ";
    cin >> n;
    vector<vector<int>> buildings;
    buildings.reserve(n);
    cout << "Enter buildings <left right height>: " << endl;
    for (int i = 0; i < n; i++)
    {
        int left, right, height;
        cin >> left >> right >> height;
        buildings.push_back({left, right, height});
    }
    Solution s;
    vector<vector<int>> skyline = s.getSkyline(buildings);

    cout << "skyline: [";
    for (auto & p: skyline)
    {
        cout <<"["<< p[0] << "," << p[1] <<"]"<<",";
    }
    cout << "]"<<endl;
    
}