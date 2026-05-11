#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 400005;
const int LOGMAX = 20; // đủ cho n <= 4e5

int n;
vector<int> adj[MAXN];
int up[LOGMAX][MAXN];
int depthArr[MAXN];
ll cnt[MAXN];

// dfs để thiết lập up[0][u] và depth
void dfs_init(int u, int p) {
    up[0][u] = p;
    for (int v : adj[u]) if (v != p) {
        depthArr[v] = depthArr[u] + 1;
        dfs_init(v, u);
    }
}

// LCA với binary lifting
int lca(int a, int b, int LOG) {
    if (depthArr[a] < depthArr[b]) swap(a, b);
    int diff = depthArr[a] - depthArr[b];
    for (int k = 0; k <= LOG; ++k) if (diff & (1 << k)) a = up[k][a];
    if (a == b) return a;
    for (int k = LOG; k >= 0; --k) {
        if (up[k][a] != up[k][b]) {
            a = up[k][a];
            b = up[k][b];
        }
    }
    return up[0][a];
}

// tích lũy kết quả từ con lên cha
void dfs_accumulate(int u, int p) {
    for (int v : adj[u]) if (v != p) {
        dfs_accumulate(v, u);
        cnt[u] += cnt[v];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> n)) return 0;

    for (int i = 1; i <= n; ++i) {
        adj[i].clear();
        cnt[i] = 0;
        depthArr[i] = 0;
        for (int k = 0; k < LOGMAX; ++k) up[k][i] = 0;
    }

    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // root cây tại 1
    depthArr[1] = 0;
    dfs_init(1, 0);

    // tính log thực tế
    int LOG = 0;
    while ((1 << (LOG + 1)) <= n) ++LOG;

    // build bảng up
    for (int k = 1; k <= LOG; ++k) {
        for (int i = 1; i <= n; ++i) {
            int mid = up[k-1][i];
            up[k][i] = mid ? up[k-1][mid] : 0;
        }
    }

    // áp dụng difference cho từng cặp (i, i+1)
    for (int i = 1; i < n; ++i) {
        int a = i, b = i + 1;
        int L = lca(a, b, LOG);
        cnt[a] += 1;
        cnt[b] += 1;
        cnt[L] -= 1;
        if (up[0][L]) cnt[ up[0][L] ] -= 1;
    }

    // tích lũy từ con lên cha
    dfs_accumulate(1, 0);

    // in kết quả (số đường đi đi qua node i)
    for (int i = 1; i <= n; ++i) {
        cout << cnt[i] << '\n';
    }
    return 0;
}
