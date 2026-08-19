#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(x) freopen(x".inp", "r", stdin); freopen(x".out", "w", stdout);
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define fast ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);

using namespace std;

typedef long long ll;
const ll INF = 1e18;
const int MOD = 1e9 + 7;
const int N = 2e5 + 5;

int n, q, ans[200005], st[524288], in[200005];
map<int, vector<int>> pos;
set<int> val;
map<int, vector<pair<pair<int, int>, int>>> qs;

void upd(int id, int l, int r, int i, int v)
{
    if(l == r) {
        st[id] += v;
        return;
    }
    int m = (l + r) / 2;
    if(i <= m) upd(id * 2 + 1, l, m, i, v);
    else upd(id * 2 + 2, m + 1, r, i, v);
    st[id] = st[id * 2 + 1] + st[id * 2 + 2];
}

int query(int id, int l, int r, int u, int v){
    if(u > v) return 0;
    if(l == u && r == v) return st[id];
    int m = (l + r) / 2;
    if(v <= m) return query(id * 2 + 1, l, m, u, v);
    if(u > m) return query(id * 2 + 2, m + 1, r, u, v);
    return query(id * 2 + 1, l, m, u, m) + query(id * 2 + 2, m + 1, r , m + 1, v);
}

int main()
{
    fast
    file("3146");
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int h;
        cin >> h;
        pos[-h].pb(i);
        val.insert(-h);
    }
    for (int i = 1; i <= q; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        qs[-x].pb({{l, r}, i});
        val.insert(-x);
    }
    memset(in, 0, sizeof(in));
    memset(st, 0, sizeof(st));
    for (int h : val) {
        for (auto qr : qs[h]) {
            ans[qr.se] = query(0, 1, n, qr.fi.fi, qr.fi.se - 1) + in[qr.fi.fi] + in[qr.fi.se];
            ans[qr.se] /= 2;
        }
        for (int i : pos[h]) {
            in[i] = 1;
            if (in[i - 1]) upd(0, 1, n, i - 1, -1);
            else upd(0, 1, n, i - 1, 1);
            if (in[i + 1]) upd(0, 1, n, i, -1);
            else upd(0, 1, n, i, 1);
        }
    }
    for (int i = 1; i <= q; i++) cout << ans[i] << '\n';
    return 0;
}
