#include <bits/stdc++.h>
using namespace std;

int n, m, logn, p[100001][17], d[100001];

// Hàm tính độ sâu của một nút
int depth(int i) {
    if (p[i][0] == i) return d[i] = 1;
    if (d[i] == 0) d[i] = depth(p[i][0]) + 1;
    return d[i];
}

// Hàm tìm tổ tiên chung gần nhất của hai nút u và v
int lca(int u, int v) {
    if (d[u] < d[v]) swap(u, v);
    for (int j = logn; j >= 0; j--)
        if (d[p[u][j]] >= d[v]) u = p[u][j];
    if (u == v) return u;
    for (int j = logn; j >= 0; j--)
        if (p[u][j] != p[v][j]) {
            u = p[u][j];
            v = p[v][j];
        }
    return p[u][0];
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &p[i][0]);
    for (logn = 1; (1 << logn) <= n; logn++);
    logn--;
    for (int j = 1; j <= logn; j++)
        for (int i = 1; i <= n; i++)
            p[i][j] = p[p[i][j - 1]][j - 1];
    memset(d, 0, sizeof(d));
    for (int i = 1; i <= n; i++) depth(i);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        printf("%d\n", lca(u, v));
    }
}
