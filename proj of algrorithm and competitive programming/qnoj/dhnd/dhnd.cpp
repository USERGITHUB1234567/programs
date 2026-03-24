#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

const int MAXN = 300005;
bool ar[MAXN];
long long a[MAXN], t[MAXN], ai[MAXN];
int n, k;

int main() {
    fill(ai, ai + MAXN, 1e18);
    cin >> n >> k;

    for (int i = 1; i <= k; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= k; i++) {
        cin >> t[i];
        ai[a[i]] = t[i];
    }
    for (int i = 1; i <= n; i++) {
        if (i > 1) {
            ai[i] = min(ai[i], ai[i - 1] + 1);
        }
    }
    for (int i = n; i >= 1; i--) {
        if (i < n) {
            ai[i] = min(ai[i], ai[i + 1] + 1);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ai[i] << " ";
    }
    return 0;
}
