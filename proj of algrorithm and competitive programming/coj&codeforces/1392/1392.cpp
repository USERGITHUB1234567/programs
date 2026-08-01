#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    long long res = 0;
    for (int a = 1; a <= n; ++a) {
        vector<int> f(n + 1, 0);
        for (int b : g[a]) {
            for (int c : g[b]) {
                if (c != a) {
                    f[c]++;
                }
            }
        }
        for (int c = 1; c <= n; ++c) {
            if (f[c] > 1) {
                res += (f[c] * (f[c] - 1)) / 2;
            }
        }
    }

    cout << res << endl;
    return 0;
}
