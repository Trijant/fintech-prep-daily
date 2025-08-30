#include <iostream>
#include<vector>
using namespace std;

// TOPIC: DIFFERENCE ARRAY
// Time-complexity: O(n+q)
// Space-complexity:O(n)

vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n)
{
    // updating flights in difference array.
    vector<int> diff(n, 0);
    for (int i = 0; i < bookings.size(); i++)
    {
        diff[bookings[i][0] - 1] += bookings[i][2];
        if (bookings[i][1] != n)
        {
            diff[bookings[i][1]] -= bookings[i][2];
        }
    }
    // constructing ans array from difference array.
    for (int i = 1; i < n; i++)
    {
        diff[i] += diff[i - 1];
    }
    return diff;
}

int main(){
    int total_orders,total_flights;
    cout << "Enter total no. of flights: ";
    cin >> total_flights;
    cout << "Enter total no. of orders: ";
    cin >> total_orders;
    vector<vector<int>> bookings(total_orders, vector<int>(3));
    for (int i = 0; i < total_orders; i++)
    {
        cout << "Enter order " << i << " left right seats: ";
        cin >> bookings[i][0] >> bookings[i][1] >> bookings[i][2];
    }
    vector<int> totalSeatsReserved = corpFlightBookings(bookings, total_flights);
    cout << "No. of seats booked: " << endl;
    for (int i = 0; i < total_flights; i++)
    {
        cout << totalSeatsReserved[i]<<" ";
    }
    
}