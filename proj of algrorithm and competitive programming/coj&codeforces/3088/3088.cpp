#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#define int long long
using namespace std;

const int maxn = 200005, mod1 = 1000000003, mod2 = 1000000007;
int d[2][maxn], c[2][2][maxn], n, m;
vector<pair<int, int>> a[2][maxn];

void dijkstra(int t, int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 1; i <= n; i++) {
        d[t][i] = 4e18;
        c[t][0][i] = c[t][1][i] = 0;
    }
    d[t][s] = 0;
    c[t][0][s] = c[t][1][s] = 1;
    pq.push({0, s});
    while (!pq.empty()) {
        auto [cd, u] = pq.top();
        pq.pop();
        if (cd != d[t][u])
            continue;
        for (auto [v, w] : a[t][u]) {
            if (d[t][u] + w < d[t][v]) {
                d[t][v] = d[t][u] + w;
                c[t][0][v] = c[t][0][u];
                c[t][1][v] = c[t][1][u];
                pq.push({d[t][v], v});
            } else if (d[t][u] + w == d[t][v]) {
                c[t][0][v] = (c[t][0][v] + c[t][0][u]) % mod1;
                c[t][1][v] = (c[t][1][v] + c[t][1][u]) % mod2;
            }
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        a[0][u].push_back({v, w});
        a[1][v].push_back({u, w});
    }
    dijkstra(0, 1);
    dijkstra(1, n);
    vector<int> re;
    for (int i = 1; i <= n; i++) {
        if (d[0][i] + d[1][i] == d[0][n]) {
            if ((c[0][0][i] * c[1][0][i]) % mod1 == c[0][0][n] &&
                (c[0][1][i] * c[1][1][i]) % mod2 == c[0][1][n]) {
                re.push_back(i);
            }
        }
    }

    sort(re.begin(), re.end());
    cout << re.size() << "\n";
    for (int i = 0; i < (int)re.size(); i++){
        cout << re[i] << (i + 1 < re.size() ? " " : "");
    }
    return 0;
}
