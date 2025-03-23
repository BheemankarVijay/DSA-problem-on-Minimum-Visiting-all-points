#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int toTime(vector<int>& from, vector<int>& to) {
        int xDiff = abs(from[0] - to[0]);
        int yDiff = abs(from[1] - to[1]);
        
        return max(xDiff, yDiff);
    }

    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int time = 0;

        for (int i = 1; i < points.size(); i++) {
            time += toTime(points[i - 1], points[i]);
        }

        return time;
    }
};

int main() {
    int n; // Number of points
    cout << "Enter the number of points: ";
    cin >> n;

    vector<vector<int>> points(n, vector<int>(2)); // Initialize a 2D vector to store points

    cout << "Enter the coordinates of the points (x y):" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> points[i][0] >> points[i][1]; // Take user input for each point
    }

    // Create an object of the Solution class
    Solution solution;
    
    // Calculate the minimum time to visit all points
    int result = solution.minTimeToVisitAllPoints(points);

    cout << "Minimum Time to Visit All Points: " << result << endl;

    return 0;
}