#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int n, m, q;
int b[300001], g[300001], c[300001], x, y, t;
vector<int> a[300001];

int mx(int x, int y) {
    return (x > y) ? x : y;
}

int f(int x) {
    if (b[x] == x)
        return x;
    return b[x] = f(b[x]);
}

void dfs(int k) {
    b[k] = x;
    for (int i = 0; i < (int)a[k].size(); i++) {
        int v = a[k][i];
        if (!b[v]) {
            dfs(v);
            g[x] = mx(g[x], c[k] + c[v] + 1);
            c[k] = mx(c[k], c[v] + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> q;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) {
        if (!b[i]) {
            x = i;
            dfs(i);
        }
    }
    while (q--) {
        cin >> t >> x;
        if (t == 1) {
            cout << g[f(x)] << '\n';
        } else {
            cin >> y;
            x = f(x);
            y = f(y);
            if (x != y) {
                b[y] = x;
                g[x] = mx(mx(g[x], g[y]), (g[x] + 1) / 2 + (g[y] + 1) / 2 + 1);
            }
        }
    }
    return 0;
}
