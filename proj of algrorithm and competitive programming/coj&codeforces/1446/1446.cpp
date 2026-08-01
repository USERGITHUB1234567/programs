#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int d[100001];
vector<pair<int, int>> a[100001];
void dfs(int u, int p) {
    for (auto [v, w] : a[u]) {
        if (v == p) continue;
        d[v] = d[u] + w;
        dfs(v, u);
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        a[x].emplace_back(y, z);
        a[y].emplace_back(x, z);
    }

    d[1] = 0;
    dfs(1, 0);
    int u = max_element(d + 1, d + 1 + n) - d;
    fill(d, d + n + 1, 0);
    dfs(u, 0);
    int kq = *max_element(d + 1, d + 1 + n);
    cout << kq;
    return 0;
}
