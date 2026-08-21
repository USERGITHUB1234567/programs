/*#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n;
struct point
{
    double x,y,g,d;
};
bool cmp(point a, point b)
{
    return (a.g<b.g) or ((a.g==b.g) and (a.d<b.d));
}
double dis(point a, point b)
{
    double t1=abs(a.x-b.x),t2=abs(a.y-b.y);
    return sqrt(t1*t1+t2*t2);
}
int main()
{
    cin >> n;
    point a[10001];
    for(int i=1; i<=n; i++) cin >> a[i].x >> a[i].y;
    for(int i=2; i<=n; i++) {
        if((a[i].y<a[1].y) or (a[i].y==a[1].y and a[i].x>a[1].x)) swap(a[1],a[i]);
    }
    for(int i=2; i<=n; i++) {
        a[i].g=atan2(a[i].y-a[1].y,a[i].x-a[1].x);
        a[i].d=dis(a[i],a[1]);
    }
    sort(a+2,a+1+n,cmp);
    for(int i=n; i>=2; i--) {
        if(a[i].g!=a[i-1].g) {
            for(int j=i; j<=(n+i)/2; j++) swap(a[j],a[n+i-j]);
            break;
        }
    }
    double kq=1e9;
    for(int i=1; i<=n; i++) {
        int j=i+1;
        if(j>n) j=1;
        kq=min(kq,dis(a[i],a[j]));
    }
    cout << fixed << setprecision(2) << kq;
    return 0;
}
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

struct Point {
    double x, y;
};

// Hàm tính khoảng cách giữa 2 điểm
double distance(const Point& p1, const Point& p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

// Hàm tính diện tích tam giác xác định bởi 3 điểm (cho biết điểm có tạo thành bao lồi hay không)
double ccw(const Point& p1, const Point& p2, const Point& p3) {
    return (p2.y - p1.y) * (p3.x - p1.x) - (p2.x - p1.x) * (p3.y - p1.y);
}

// So sánh hai điểm để sắp xếp
bool compare(const Point& p1, const Point& p2) {
    return (p1.x < p2.x) || (p1.x == p2.x && p1.y < p2.y);
}

// Thuật toán Graham scan để tìm bao lồi
vector<Point> convex_hull(vector<Point>& points) {
    sort(points.begin(), points.end(), compare);
    vector<Point> lower, upper;

    for (const auto& p : points) {
        while (lower.size() >= 2 && ccw(lower[lower.size() - 2], lower.back(), p) <= 0) {
            lower.pop_back();
        }
        lower.push_back(p);
    }

    for (int i = points.size() - 1; i >= 0; i--) {
        while (upper.size() >= 2 && ccw(upper[upper.size() - 2], upper.back(), points[i]) <= 0) {
            upper.pop_back();
        }
        upper.push_back(points[i]);
    }

    lower.pop_back();
    upper.pop_back();
    lower.insert(lower.end(), upper.begin(), upper.end());

    return lower;
}

int main() {
    int N;
    cin >> N;
    vector<Point> points(N);

    for (int i = 0; i < N; ++i) {
        cin >> points[i].x >> points[i].y;
    }

    if (N == 0) {
        cout << "0.00" << endl;
        return 0;
    }

    auto hull = convex_hull(points);
    double perimeter = 0.0;

    for (size_t i = 0; i < hull.size(); ++i) {
        perimeter += distance(hull[i], hull[(i + 1) % hull.size()]);
    }

    cout << fixed << setprecision(2) << perimeter << endl;
    return 0;
}
