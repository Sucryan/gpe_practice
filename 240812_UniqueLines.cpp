#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;

struct Point {
    int x, y;
};

int countUniqueLines(vector<Point>& points) {
    map<pair<double, double>, int> lines;
    int n = points.size();
    // 舉例{(0, 0), (1, 1), (2, 2), (3, 3)}
    // 一開始先算 (0, 0) 和 (1, 1), (2, 2), (3, 3)
    // 再算 (1, 1) 和 (2, 2), (3, 3)
    // 再算 (2, 2) 和 (3, 3)
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int dx = points[j].x - points[i].x;
            int dy = points[j].y - points[i].y;

            if (dx == 0) {
                // 垂直線
                lines[{INFINITY, points[i].x}]++;
            } 
            else {
                double slope = (double)dy / dx;
                double intercept = points[i].y - slope * points[i].x;
                // 可以記錄這條線重複出現幾次
                lines[{slope, intercept}]++;
            }
        }
    }
    // 不過以這題來說我們只在乎有幾條不同的線
    return lines.size();
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<Point> points(n);
        for (int i = 0; i < n; i++) {
            cin >> points[i].x >> points[i].y;
        }
        cout << countUniqueLines(points) << endl;
    }

    return 0;
}