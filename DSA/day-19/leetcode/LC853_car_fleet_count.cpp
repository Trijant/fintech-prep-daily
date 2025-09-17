#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// topic : next max
// time-complexity: O(n)
// space-complexity: O(n)

    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {
        int n = position.size();
        vector<pair<int, double>> cars; // {position, time}
        cars.reserve(n);

        for (int i = 0; i < n; i++)
        {
            double t = static_cast<double>(target - position[i]) / speed[i];
            cars.push_back({position[i], t});
        }

        // Sort by position ASC so we can process from rightmost (closest to target)
        sort(cars.begin(), cars.end());

        int fleets = 0;
        double maxTime = 0;

        // Traverse from closest to target → farthest
        for (int i = n - 1; i >= 0; i--)
        {
            double curTime = cars[i].second;
            if (curTime > maxTime)
            {
                fleets++;
                maxTime = curTime;
            }
        }

        return fleets;
    }



int main(){
    int target, size;
    cout << "Enter total no. of cars:";
    cin >> size;
    vector<int> pos(size);
    vector<int> speed(size);
    cout << "Enter positions:" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> pos[i];
    }
    cout << "Enter speeds: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> speed[i];
    }
    cout<<"Enter target destination: ";
    cin >> target;
    cout << "Total fleets: " << carFleet(target, pos, speed) << endl;
}