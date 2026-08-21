#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int side(int a, int b, int c, int x, int y) {
    long long f = 1LL * a * x + 1LL * b * y + 1LL * c;
    if (f > 0) return 1;
    else if (f < 0) return -1;
    else return 0;
}

int main() {
    int res = 0;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (side(a, b, c, x1, y1) * side(a, b, c, x2, y2) < 0) res++;
    }
    cout << res;
    return 0;
}
