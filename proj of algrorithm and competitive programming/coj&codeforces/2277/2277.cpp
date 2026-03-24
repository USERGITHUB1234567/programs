#include <bits/stdc++.h>
using namespace std;
struct Point {
    long long x, y;
};
double c(vector<Point> p) {
    int n = p.size();
    long long area = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        area += p[i].x * p[j].y;
        area -= p[j].x * p[i].y;
    }
    return abs(area) / 2.0;
}
int main() {
    int n;
    cin >> n;
    double kq = 0;
    for (int i = 0; i < n; i++) {
        int P;
        cin >> P;
        vector<Point> p(P);
        for (int j = 0; j < P; j++) {
            cin >> p[j].x >> p[j].y;
        }
        kq += c(p);
    }
    cout << (long long)kq;
    return 0;
}
