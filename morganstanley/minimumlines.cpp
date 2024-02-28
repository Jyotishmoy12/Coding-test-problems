Description
Given N points in 2-dimensional space, Your task to find the count of the minimum number of lines which traverse through all these N points and which also go through a specific (x0, y0) point.

Input Format
The first line of input contains three space-separated integers N, x0 and y0.
The next N lines contain xi, yi - the coordinates of the ith point.


// if slope zero then vertical line else find the slope
#include<bits/stdc++.h>

using namespace std;

struct Point {
    int x, y;
};

int minLinesCount(int N, int x0, int y0, vector<Point>& points) {
    unordered_set<double> slopes;

    for (int i = 0; i < N; ++i) {
        int dx = points[i].x - x0;
        int dy = points[i].y - y0;

        if (dx == 0) {
            slopes.insert(INT_MAX); // Vertical line
        } else {
            double slope = static_cast<double>(dy) / dx;
            slopes.insert(slope);
        }
    }

    return slopes.size();
}

int main() {
    int N, x0, y0;
    cin >> N >> x0 >> y0;

    vector<Point> points(N);
    for (int i = 0; i < N; ++i) {
        cin >> points[i].x >> points[i].y;
    }

    int result = minLinesCount(N, x0, y0, points);
    cout << result << endl;

    return 0;
}
