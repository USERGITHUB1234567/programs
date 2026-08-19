#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    cout.setf(std::ios::fixed); cout << setprecision(6);

    while (T--) {
        double xa, ya, xb, yb, xc, yc, xd, yd;
        cin >> xa >> ya >> xb >> yb >> xc >> yc >> xd >> yd;

        // u = A - C
        double ux = xa - xc;
        double uy = ya - yc;
        // v = (B - A) - (D - C) = (B - A) - (D - C)
        double vx = (xb - xa) - (xd - xc);
        double vy = (yb - ya) - (yd - yc);

        double vv = vx*vx + vy*vy; // v·v
        double uv = ux*vx + uy*vy; // u·v

        double t;
        if (vv == 0.0) {
            // same velocity vector, distance is constant
            t = 0.0;
        } else {
            t = - uv / vv;
            if (t < 0.0) t = 0.0;
            else if (t > 1.0) t = 1.0;
        }

        double dx = ux + vx * t;
        double dy = uy + vy * t;
        double dist = sqrt(dx*dx + dy*dy);
        cout << dist << '\n';
    }
    return 0;
}
