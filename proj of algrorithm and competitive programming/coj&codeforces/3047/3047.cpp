#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

long long maxx[123][123], minn[123][123];
long long v[123];
char e[123];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> e[i] >> v[i];
        e[n + i] = e[i];
        v[n + i] = v[i];
        maxx[i][1] = v[i];
        maxx[i + n][1] = v[i];
        minn[i][1] = v[i];
        minn[i + n][1] = v[i];
    }

    // Calculate maxx and minn for all possible subproblems
    for (int j = 2; j <= n; j++) {
        for (int i = 1; i <= n; i++) {
            maxx[i][j] = -1e18;
            minn[i][j] = 1e18;
            for (int k = 1; k <= j - 1; k++) {
                if (e[i + k] == 't') {
                    maxx[i][j] = max(maxx[i][j], maxx[i][k] + maxx[i + k][j - k]);
                    minn[i][j] = min(minn[i][j], minn[i][k] + minn[i + k][j - k]);
                    maxx[i + n][j] = maxx[i][j];
                    minn[i + n][j] = minn[i][j];
                } else {
                    maxx[i][j] = max({maxx[i][j],
                                      maxx[i][k] * maxx[i + k][j - k],
                                      minn[i][k] * minn[i + k][j - k],
                                      minn[i][k] * maxx[i + k][j - k],
                                      maxx[i][k] * minn[i + k][j - k]});
                    minn[i][j] = min({minn[i][j],
                                      maxx[i][k] * maxx[i + k][j - k],
                                      minn[i][k] * minn[i + k][j - k],
                                      minn[i][k] * maxx[i + k][j - k],
                                      maxx[i][k] * minn[i + k][j - k]});
                    maxx[i + n][j] = maxx[i][j];
                    minn[i + n][j] = minn[i][j];
                }
            }
        }
    }

    long long ans = -1e18;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, maxx[i][n]);
    }
    cout << ans << "\n";

    bool ok = true;
    for (int i = 1; i <= n; i++) {
        if (maxx[i][n] == ans) {
            if (ok) {
                cout << i;
                ok = false;
            } else {
                cout << " " << i;
            }
        }
    }
    return 0;
}
