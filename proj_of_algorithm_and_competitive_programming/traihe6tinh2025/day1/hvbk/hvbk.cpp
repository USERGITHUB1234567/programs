#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

const int maxn = (1 << 15) + 1;
int n, k;
long long f[maxn][17];

long long solve(int n, int k) {
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i <= n; i++) {
            f[mask][i] = 0;
        }
    }
    f[0][0] = 1;
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int q = 1; q <= n; q++) {
            if ((mask >> (q - 1)) & 1) continue;
            int nm = mask | (1 << (q - 1));
            for (int p = 0; p <= n; p++) {
                if (p != 0 && abs(q - p) > k) continue;
                f[nm][q] += f[mask][p];
            }
        }
    }
    long long res = 0;
    int fm = (1 << n) - 1;
    for (int i = 1; i <= n; i++) {
        res += f[fm][i];
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> k;
    cout << solve(n, k);
    return 0;
}
