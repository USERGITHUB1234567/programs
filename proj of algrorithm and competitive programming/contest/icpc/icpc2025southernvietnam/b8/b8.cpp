#include <bits/stdc++.h>
using namespace std;
int main() {
    int q;
    if (!(cin >> q)) return 0;
    while (q--) {
        long long l, r;
        cin >> l >> r;
        long long cnt = r/3 - (l-1)/3;
        if (l <= 3 && 3 <= r) cnt--;
        if (l <= 9 && 9 <= r) cnt--;
        cout << cnt << '\n';
    }
    return 0;
}
