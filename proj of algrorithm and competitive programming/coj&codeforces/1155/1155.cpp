#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int n, x[14], a[14], b[27], c[26], cnt = 0;

void dfs(int i) {
    if (i > n) {
        cnt++;
        if (cnt <= 3) {
            for (int j = 1; j <= n - 1; j++) {
                cout << x[j] << " ";
            }
            cout << x[n] << "\n";
        }
        return;
    }
    for (int j = 1; j <= n; j++) {
        if (a[j] && b[i + j] && c[i - j + n]) {
            x[i] = j;
            a[j] = false;
            b[i + j] = false;
            c[i - j + n] = false;
            dfs(i + 1);
            a[j] = true;
            b[i + j] = true;
            c[i - j + n] = true;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    memset(a, true, sizeof(a));
    memset(b, true, sizeof(b));
    memset(c, true, sizeof(c));
    dfs(1);
    cout << cnt;
    return 0;
}
