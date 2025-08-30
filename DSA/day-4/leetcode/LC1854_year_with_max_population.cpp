#include<iostream>
#include<vector>
using namespace std;

// TOPIC: DIFFERENCE ARRAY
// Time-complexity: O(n)
// Space-complexity: O(1)

int maximumPopulation(vector<vector<int>> &logs)
{
    int diff[101] = {0};
    for (int i = 0; i < logs.size(); i++)
    {
        diff[logs[i][0] - 1950]++;
        diff[logs[i][1] - 1950]--;
    }
    int maxPopulation = diff[0], maxPopulationYear = 1950;
    for (int i = 1; i < 101; i++)
    {
        diff[i] += diff[i - 1];
        if (diff[i] > maxPopulation)
        {
            maxPopulation = diff[i];
            maxPopulationYear = 1950 + i;
        }
    }
    return maxPopulationYear;
}

int main(){
    int totalPersons;
    cout << "Enter total no. of persons: ";
    cin >> totalPersons;
    vector<vector<int>> logs(totalPersons, vector<int>(2));
    cout << "Enter logs (birth death:space seperated and year between:1950-2050):" << endl;
    for (int i = 0; i < totalPersons; i++)
    {
        cin >> logs[i][0] >> logs[i][1];
    }
    cout << "Year with max population: " << maximumPopulation(logs);
}