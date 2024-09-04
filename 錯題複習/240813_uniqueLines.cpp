#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

int gcd(int a, int b) {
    // 小的一定會在右邊，然後碰0才會停！
    return b == 0 ? a : gcd(b, a % b);
}

struct Point {
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
};

struct Line {
    int a, b, c; // ax + by + c = 0
    Line(const Point& p1, const Point& p2) {
        // a = dy, b = -dx, c = dx * y - dy * x
        a = p1.y - p2.y;
        b = p2.x - p1.x;
        c = p1.x * p2.y - p2.x * p1.y;
        int g = gcd(abs(a), gcd(abs(b), abs(c)));
        if (g > 0) {
            a /= g; b /= g; c /= g;
        }
        if (a < 0 || (a == 0 && b < 0)) {
            a = -a; b = -b; c = -c;
        }
    }
    // operator overloading!
    /*
        重載 < 運算符，用於比較兩條直線。
        比較順序：先比較 a，然後 b，最後 c。
        這允許將 Line 對象用在需要排序的容器中，如 set 或 map。
    */
    bool operator<(const Line& other) const {
        if (a != other.a) return a < other.a;
        if (b != other.b) return b < other.b;
        return c < other.c;
    }
};

int count_unique_lines(const vector<Point>& points) {
    set<Line> unique_lines;
    int n = points.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            Line line(points[i], points[j]);
            unique_lines.insert(line);
        }
    }

    return unique_lines.size();
}

int main() {
    int test_cases;
    cin >> test_cases;

    while (test_cases--) {
        int n;
        cin >> n;
        vector<Point> points(n);

        for (int i = 0; i < n; i++) {
            cin >> points[i].x >> points[i].y;
        }

        cout << count_unique_lines(points) << endl;
    }

    return 0;
}