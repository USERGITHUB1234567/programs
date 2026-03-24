#include <bits/stdc++.h>
using namespace std;

struct point {
    int x, y;
};

struct vecto {
    int x, y;
};

int n, ans[101];
point a[101], b[101];

double cross_product(vecto a, vecto b) {
    return a.x * b.y - a.y * b.x;
}

int side(point A, point B, point C) {
    vecto AB = {B.x - A.x, B.y - A.y}, AC = {C.x - A.x, C.y - A.y};
    double s = cross_product(AB, AC);
    if (s > 0) return 1;   // rẽ trái - điểm C thuộc nửa mặt phẳng bên trái của đường thẳng AB
    if (s < 0) return -1;  // rẽ phải - điểm C thuộc nửa mặt phẳng bên phải của đường thẳng AB
    return 0;              // 3 điểm thẳng hàng
}

bool intersect(point A, point B, point C, point D) {
    int s1 = side(A, B, C);
    int s2 = side(A, B, D);
    int s3 = side(C, D, A);
    int s4 = side(C, D, B);
    if (s1 == 0 && s2 == 0 && s3 == 0 && s4 == 0) { // 4 điểm thẳng hàng
        if (max(A.x, B.x) < min(C.x, D.x) || max(C.x, D.x) < min(A.x, B.x) ||
            max(A.y, B.y) < min(C.y, D.y) || max(C.y, D.y) < min(A.y, B.y))
            return false;
        return true;
    }
    return (s1 * s2 <= 0 && s3 * s4 <= 0);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen("test03.in", "r", stdin);
    // freopen("", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y;
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i].x >> b[i].y;
    }
    for (int i = 1; i <= n; i++) {
        ans[i] = i;
    }

    while (true) {
        bool ok = true;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (intersect(a[i], b[ans[i]], a[j], b[ans[j]])) {
                    swap(ans[i], ans[j]);
                    ok = false;
                }
            }
        }
        if (ok) break;
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}
