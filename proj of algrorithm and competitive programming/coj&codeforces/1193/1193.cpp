/*#include <bits/stdc++.h>
using namespace std;

struct point {
    double x, y;
};

struct vect {
    double x, y;
};

double tvh(vect a, vect b) {
    return a.x * b.x + a.y * b.y;
}

double tc(vect a, vect b) {
    return a.x * b.y - a.y * b.x;
}

int side(point a, point b, point c) {
    vect ab = {b.x - a.x, b.y - a.y};
    vect ac = {c.x - a.x, c.y - a.y};
    double s = tc(ab, ac);
    if (s > 0) return 1;
    if (s < 0) return -1;
    return 0;
}

int main() {
    point a, b, c;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
    if (side(a, b, c) == -1) cout << "RIGHT";
    else if (side(a, b, c) == 1) cout << "LEFT";
    else cout << "TOWARD";
    return 0;
}*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    long long cross_product = (xb - xa) * (yc - yb) - (yb - ya) * (xc - xb);

    if (cross_product > 0) {
        cout << "LEFT" ;
    } else if (cross_product < 0) {
        cout << "RIGHT";
    } else {
        cout << "TOWARDS";
    }

    return 0;
}

