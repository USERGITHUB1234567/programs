#include <bits/stdc++.h>
using namespace std;

int main() {
    int r, x, y, xt, yt;
    cin >> r >> x >> y >> xt >> yt;
    double d = sqrt(pow(xt - x, 2) + pow(yt - y, 2));
    int kq = ceil(d / (2 * r));
    cout << kq;
    return 0;
}
