#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

struct point {
    long long x, y;
};

bool inside(point m, vector<point>& a) {
    a.push_back(a[0]);
    for (int i = 0; i < a.size(); i++) {
        a[i].x -= m.x;
        a[i].y -= m.y;
    }
    double w = 0;
    for (int i = 0; i < a.size() - 1; i++) {
        if ((a[i].y * a[i + 1].y) < 0) {
            double r = a[i].x + a[i].y * (a[i + 1].x - a[i].x) / (a[i].y - a[i + 1].y);
            if (r > 0) {
                if (a[i].y < 0) w++;
                else w--;
            }
            continue;
        }
        if (a[i].y == 0 && a[i].x > 0 && a[i + 1].y > 0 || a[i + 1].y == 0 && a[i + 1].x > 0 && a[i].y < 0) {
            w += 0.5;
            continue;
        }
        if (a[i].y == 0 && a[i].x > 0 && a[i + 1].y < 0 || a[i + 1].y == 0 && a[i + 1].x > 0 && a[i].y > 0) w -= 0.5;
    }
    for (int i = 0; i < a.size(); i++) {
        a[i].x += m.x;
        a[i].y += m.y;
    }
    return w != 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    long long x, y;
    cin >> n >> x >> y;
    point m = {x, y};
    vector<point> polygon(n);
    for (int i = 0; i < n; ++i) {
        cin >> polygon[i].x >> polygon[i].y;
    }

    if (inside(m, polygon)) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}
/*alternative code
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

struct Point {
    long long x, y;
};

bool isPointInPolygon(const vector<Point>& polygon, const Point& point) {
    int n = polygon.size();
    bool inside = false;

    for (int i = 0, j = n - 1; i < n; j = i++) {
        if (((polygon[i].y > point.y) != (polygon[j].y > point.y)) &&
            (point.x < (polygon[j].x - polygon[i].x) * (point.y - polygon[i].y) / (polygon[j].y - polygon[i].y) + polygon[i].x)) {
            inside = !inside;
        }
    }

    return inside;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    long long x, y;
    cin >> n >> x >> y;
    Point M = {x, y};

    vector<Point> polygon(n);
    for (int i = 0; i < n; ++i) {
        cin >> polygon[i].x >> polygon[i].y;
    }

    if (isPointInPolygon(polygon, M)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
*/
