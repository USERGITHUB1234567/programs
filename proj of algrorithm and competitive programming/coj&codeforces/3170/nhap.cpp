//（づ￣3￣）づ╭❤️️～
// Huwng Lee ~_~
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

#define pl pair <ll, ll>
#define pll pair <pl, ll>
#define pi pair <int, int>
#define pb push_back
#define fi first
#define se second
#define ld long double
#define fti(i, x, y) for(int i = (x), _y = (y); i <= _y; ++ i)
#define ftd(i, x, y) for(int i = (x), _y = (y); i >= _y; -- i)

using namespace std;

typedef long long ll;

const ll N = 1e5 + 2, oo = 1e18;

int n, s, q, e, w[N];
ll d[N];
struct node
{
    int v, w, id;
};
vector <pi> a[N];
bool store[N], visit[N];
pi edge[N];

void lph()
{
    freopen("3170.inp", "r", stdin);
    freopen("3170.out", "w", stdout);
}

namespace sub1
{
    void dfs(int u, int p)
    {
        for(auto [v, w]: a[u])
        {
            if(v == p) continue;
            d[v] = d[u] + w;
            dfs(v, u);
        }
    }

    void solve()
    {
        while(q --)
        {
            int i, r;
            cin >> i >> r;
            fti(j, 1, n)
                a[j].clear();
            fti(j, 1, n - 1)
            {
                if(i != j)
                {
                    int u = edge[j].fi, v = edge[j].se;
                    a[u].pb({v, w[j]});
                    a[v].pb({u, w[j]});
                }
            }
            int u = min(edge[i].fi, edge[i].se);
            if((r <= u && e <= u) || (r > u && e > u))
                cout << "escaped\n";
            else
            {
                fti(j, 1, n)
                    d[j] = oo;
                d[r] = 0;
                dfs(r, 0);
                ll ans = oo;
                fti(j, 1, n)
                    if(store[j])
                        ans = min(ans, d[j]);
                if(ans == oo)
                    cout << "oo\n";
                else
                    cout << ans << "\n";
            }
        }
    }
}

namespace sub2
{
    void dfs(int u, int p)
    {
        for(auto [v, w]: a[u])
        {
            if(v == p) continue;
            d[v] = d[u] + w;
            dfs(v, u);
        }
    }

    void solve()
    {
        while(q --)
        {
            int i, r;
            cin >> i >> r;
            fti(j, 1, n)
                a[j].clear();
            fti(j, 1, n - 1)
            {
                if(i != j)
                {
                    int u = edge[j].fi, v = edge[j].se;
                    a[u].pb({v, w[j]});
                    a[v].pb({u, w[j]});
                }
            }

            fti(j, 1, n)
                d[j] = oo;
            d[r] = 0;
            dfs(r, 0);
            if(d[e] != oo) cout << "escaped\n";
            else
            {
                ll ans = oo;
                fti(j, 1, n)
                    if(store[j])
                        ans = min(ans, d[j]);
                if(ans == oo)
                    cout << "oo\n";
                else
                    cout << ans << "\n";
            }
        }
    }
}

namespace sub3
{
    int tin[N], tout[N], timer = 0;
    void dfs(int u, int p)
    {
        tin[u] = ++ timer;
        for(auto [v, w]: a[u])
        {
            if(v == p) continue;
            d[v] = d[u] + w;
            dfs(v, u);
        }
        tout[u] = timer;
    }

    void solve()
    {
        fti(j, 1, n - 1)
        {
            int u = edge[j].fi, v = edge[j].se;
            a[u].pb({v, w[j]});
            a[v].pb({u, w[j]});
        }
        d[e] = 0;
        dfs(e, 0);
        while(q --)
        {
            int i, r;
            cin >> i >> r;

            int u = edge[i].fi, v = edge[i].se;
            if(tin[u] > tin[v])
                swap(u, v);
            if(tin[r] < tin[v] || tout[r] > tout[v]) cout << "escaped\n";
            else
                cout << "0\n";
        }
    }
}

namespace sub4
{
    // min_dist[u] là kcach từ gốc e tới cửa hàng gần nhất trong cây con của u;
    // up[u][j] là nút từ u đi lên 2^j nút (kể cả nút u), up[u][0] = u;
    ll min_dist[N], magic[N][20];
    int tin[N], tout[N], timer = 0, up[N][20], h[N], lg;

    void dfs(int u, int p)
    {
        up[u][0] = p;
        tin[u] = ++ timer;
        min_dist[u] = (store[u] ? d[u] : oo);
        for(auto [v, w]: a[u])
        {
            if(v == p) continue;
            d[v] = d[u] + w;
            h[v] = h[u] + 1;
            dfs(v, u);
            min_dist[u] = min(min_dist[u], min_dist[v]);
        }
        tout[u] = timer;
    }

    ll best_magic(int r, int v)
    {
        // tìm magic tốt nhất của 1 nút trên đường đi từ r về v;
        int dist = h[r] - h[v] + 1; // số nút trên đường đi;
        ll ans = oo;
        for(int j = lg; j >= 0; -- j)
        {
            if(((dist >> j) & 1) == 1)
            {
                ans = min(ans, magic[r][j]);
                r = up[r][j];
            }
        }
        return ans;
    }

    void solve()
    {
        fti(j, 1, n - 1)
        {
            int u = edge[j].fi, v = edge[j].se;
            a[u].pb({v, w[j]});
            a[v].pb({u, w[j]});
        }
        d[e] = 0;
        h[e] = 0;
        dfs(e, 0);
        lg = log2(n);

        fti(i, 1, n)
            magic[i][0] = (min_dist[i] == oo ? oo : min_dist[i] - 2 * d[i]);
        fti(j, 1, lg)
            fti(i, 1, n)
            {
                up[i][j] = up[up[i][j - 1]][j - 1];
                magic[i][j] = min(magic[i][j - 1], magic[up[i][j - 1]][j - 1]);
            }

        while(q --)
        {
            int i, r;
            cin >> i >> r;

            int v = edge[i].fi;
            if(tin[edge[i].fi] < tin[edge[i].se])
                v = edge[i].se;
            if(tin[r] < tin[v] || tout[r] > tout[v]) cout << "escaped\n";
            else
            {
                ll res = best_magic(r, v);
                if(res == oo)
                    cout << "oo\n";
                else
                    cout << d[r] + res << "\n";
            }
        }
    }
}

int main()
{
    //lph();
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin >> n >> s >> q >> e;
    fti(i, 1, n - 1)
    {
        int u, v;
        cin >> u >> v >> w[i];
//        a[u].pb({v, w});
//        a[v].pb({u, w});
        edge[i] = {u, v};
    }
    memset(store, 0, sizeof(store));
    fti(i, 1, s)
    {
        int c;
        cin >> c;
        store[c] = 1;
    }

//    if(s == n) sub3::solve();
//    else
//        if(n <= 1000 && q <= 1000) sub2::solve();
//        else sub4::solve();
    sub4::solve();
    return 0;
}
