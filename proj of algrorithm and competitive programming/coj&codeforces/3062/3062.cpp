#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long ll;
const ll INF = 1e15;
int n, m, q;
ll di[501][501];
void floydwarshall() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (di[i][k] != INF && di[k][j] != INF && di[i][k] + di[k][j] < di[i][j]) {
                    di[i][j] = di[i][k] + di[k][j];
                }
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            di[i][j] = (i == j ? 0 : INF);
        }
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        di[u][v] = min(di[u][v], w);
        di[v][u] = min(di[v][u], w);
    }
    floydwarshall();
    while (q--) {
        int x, y;
        cin >> x >> y;
        cout << (di[x][y] == INF ? -1 : di[x][y]) << "\n";
    }
    return 0;
}
