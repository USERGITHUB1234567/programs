#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#define int long long
using namespace std;

int n, a[100005];
int k1, k2, k3, m = 1e9;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    k2 = max_element(a, a + n) - a;
    k1 = (k2 - 1 + n) % n;
    k3 = (k2 + 1) % n;
    cout << k1 + 1 << " " << k2 + 1 << " " << k3 + 1;
}
