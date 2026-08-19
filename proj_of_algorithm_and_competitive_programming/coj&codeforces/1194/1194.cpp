#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

struct point {
    double x,y;
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    point p[n];
    double an[n];
    for (int i=0; i<n; i++) {
        cin >> p[i].x >> p[i].y;
        an[i]=atan2(p[i].y,p[i].x);
    }
    sort(an,an+n);
    double kq=an[n-1]-an[0];
    for (int i=0; i<n-1; i++) {
        double ang=2*M_PI-(an[i+1]-an[i]);
        kq=min(kq,ang);
    }
    cout << fixed << setprecision(6) << kq*(180/M_PI);
    return 0;
}
