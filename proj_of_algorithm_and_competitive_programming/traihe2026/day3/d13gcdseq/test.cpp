/**/ 
#pragma GCC optimize("O3","Ofast","unroll-loops") 
#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll; 
const int maxn = 200005;

namespace utilities { 
    // Standard Euclidean GCD
    ll gcd(ll a, ll b) {
        while (b) { a %= b; swap(a, b); }
        return a;
    }
    
    // Safer LCM
    ll get_lcm(ll a, ll b) {
        if (a == 0 || b == 0) return 0;
        return (a / gcd(a, b)) * b;
    }
}
using namespace utilities;

int n, m, a[maxn];
int dif[maxn][21], cur[21], mk[maxn][21];
struct condition { int l, r, c; } con[maxn];

class segment_tree {
    int st[maxn << 2];
public:
    void build(int id, int l, int r) {
        if (l == r) { st[id] = a[l]; return; }
        int mid = (l + r) >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
        st[id] = gcd(st[id << 1], st[id << 1 | 1]);
    }
    int query(int id, int l, int r, int i, int j) {
        if (l > j || r < i) return 0;
        if (l >= i && r <= j) return st[id];
        int mid = (l + r) >> 1;
        int q1 = query(id << 1, l, mid, i, j);
        int q2 = query(id << 1 | 1, mid + 1, r, i, j);
        if (q1 == 0) return q2;
        if (q2 == 0) return q1;
        return gcd(q1, q2);
    }
} seg;

int main() { 
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> con[i].l >> con[i].r >> con[i].c;
        dif[con[i].l][con[i].c]++;
        dif[con[i].r + 1][con[i].c]--;
    }

    for (int i = 1; i <= n; ++i) {
        ll l = 1;
        for (int j = 1; j <= 20; ++j) {
            cur[j] += dif[i][j];
            if (cur[j] > 0) l = get_lcm(l, j);
        }
        if (l > 1e9) l = 1e9; 
        a[i] = (int)l;
    }
    seg.build(1, 1, n);
    for (int i = 1; i <= m; ++i) {
        if (seg.query(1, 1, n, con[i].l, con[i].r) != con[i].c) {
            cout << -1;
            return 0;
        }
    }
    for (int i = 1; i <= n; ++i) cout << a[i] << (i == n ? "" : " ");
    return 0; 
}