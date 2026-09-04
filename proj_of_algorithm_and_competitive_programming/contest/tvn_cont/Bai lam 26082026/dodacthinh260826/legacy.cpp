#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fti(i, x, y) for (int i = x; i <= y; ++i)
#define ftd(i, x, y) for (int i = x; i >= y; --i)
#define pi pair <ll, int>

const int MA = 1e5 + 5;

int n, q, s;
ll d[MA * 5];
vector <pair <int, ll>> con[MA * 5];

void build(int p, int nd = 1, int l = 1, int r = n)
{
//    cerr << l << ' ' << r << " - " << (l == r ? l : n + nd) << '\n';
    if (l == r)
    {
        con[l].push_back({n + p, 0}); return;
    }
    con[n + nd].push_back({n + p, 0});
    int c = (l + r) >> 1, p1 = nd << 1, p2 = p1 | 1;
    build(nd, p1, l, c); build(nd, p2, c + 1, r);
}

void connect(int p, int L, int R, ll w, bool rev, int nd = 1, int l = 1, int r = n)
{
    if (r < L || R < l) return;
    if (L <= l && r <= R)
    {
        if (l == r)
        {
            if (l != p)
                if (rev)
                    con[l].push_back({p, w});
                else
                    con[p].push_back({l, w});
        }
        else
        {
            if (rev)
                con[n + nd].push_back({p, w});
            else
                con[p].push_back({n + nd, w});
        }
        return;
    }
    int c = (l + r) >> 1, p1 = nd << 1, p2 = p1 | 1;
    connect(p, L, R, w, rev, p1, l, c);
    connect(p, L, R, w, rev, p2, c + 1, r);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("legacy.inp", "r", stdin);
    freopen("legacy.out", "w", stdout);
    cin >> n >> q >> s; build(n * 4 + 1);
    fti(i, 1, q)
    {
        int t, l, r, u, v; ll w;
        cin >> t;
        if (t == 1)
        {
            cin >> u >> v >> w;
            if (u != v)
                con[u].push_back({v, w});
        }
        else
        {
            cin >> u >> l >> r >> w;
            if (t == 2)
            {
                if (l == r)
                    con[u].push_back({l, w});
                else
                    connect(u, l, r, w, 0);
            }
            else
            {
                if (l == r)
                    con[l].push_back({u, w});
                else
                    connect(u, l, r, w, 1);
            }
        }
    }
    fti(i, 1, n * 5) d[i] = 1e18;
    d[s] = 0;
    priority_queue <pi, vector <pi>, greater <pi>> pq;
    pq.push({0, s});
    while (!pq.empty())
    {
        auto [cur, u] = pq.top(); pq.pop();
        if (d[u] != cur) continue;
        for (auto [v, w] : con[u])
            if (d[v] > d[u] + w)
                d[v] = d[u] + w, pq.push({d[v], v});
    }
    fti(i, 1, n) cout << (d[i] == 1e18 ? -1 : d[i]) << ' ';
    return 0;
}
