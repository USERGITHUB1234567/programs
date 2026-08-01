#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#define int long long
using namespace std;

const int maxn = 200005;
const int INF = 4000000000000000000LL;
int n, m, q;
int a[45000], b[45000], c[45000];
int t_arr[maxn], x_arr[maxn], y_arr[maxn];
int d[302][302], ans[maxn];
bool bl[45000];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(bl, false, sizeof(bl));
    cin >> n >> m >> q;
    for (int i = 1; i <= m; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    for (int i = 1; i <= q; i++) {
        cin >> t_arr[i];
        if (t_arr[i] == 1) {
            cin >> x_arr[i];
            bl[x_arr[i]] = true;
        }
        else {
            cin >> x_arr[i] >> y_arr[i];
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            d[i][j] = (i == j ? 0 : INF);
        }
    }
    for (int i = 1; i <= m; i++){
        if (!bl[i]) {
            d[a[i]][b[i]] = min(d[a[i]][b[i]], c[i]);
            d[b[i]][a[i]] = min(d[b[i]][a[i]], c[i]);
        }
    }
    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    for (int i = q; i >= 1; i--){
        if (t_arr[i] == 1) {
            int road = x_arr[i];
            int u = a[road], v = b[road], w = c[road];
            d[u][v] = min(d[u][v], w);
            d[v][u] = min(d[v][u], w);
            for (int i1 = 1; i1 <= n; i1++){
                for (int j1 = 1; j1 <= n; j1++){
                    d[i1][j1] = min(d[i1][j1], d[i1][u] + w + d[v][j1]);
                    d[i1][j1] = min(d[i1][j1], d[i1][v] + w + d[u][j1]);
                }
            }
        }
        else {
            ans[i] = d[x_arr[i]][y_arr[i]];
            if (ans[i] == INF) ans[i] = -1;
        }
    }
    for (int i = 1; i <= q; i++){
        if (t_arr[i] == 2)
            cout << ans[i] << "\n";
    }
    return 0;
}
