//（づ￣3￣）づ╭❤️～
// Huwng Lee _
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

const int e = 1e5 + 2;
const ll oo = 1e18;

int n, m, q, w[2 * e], p[2 * e];

int up[20][2 * e], lg, d[2 * e], tin[2 * e], timer, id[2 * e];

int mn[2 * e][20], mx[2 * e][20];

vector <int> adj[2 * e];

void lph()
{
    freopen("vertices.inp", "r", stdin);
    freopen("vertices.out", "w", stdout);
}

int find_set(int u)
{
    if(p[u] == u)
        return u;
    return p[u] = find_set(p[u]);
}

void dfs(int u, int f)
{
    tin[u] = ++ timer;
    id[timer] = u;
    d[u] = (u == f ? 0 : d[f] + 1);
    up[0][u] = f;
    for(int v: adj[u])
        if(v != f)
            dfs(v, u);
}

int lca(int u, int v)
{
    if(d[u] < d[v])
        swap(u, v);
    ftd(i, lg, 0)
        if(d[up[i][u]] >= d[v])
            u = up[i][u];
    if(u == v)
        return u;
    //cout << u << ' ' << v << '\n';
    ftd(i, lg, 0)
        if(up[i][u] != up[i][v])
        {
            u = up[i][u];
            v = up[i][v];
        }
    return up[0][u];
}

int main()
{
    lph();
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin >> n >> m >> q;
    int N = n;
    fti(i, 1, 2 * n)
        p[i] = i, w[i] = 0;
    fti(i, 1, m)
    {
        int u, v;
        cin >> u >> v;
        u = find_set(u);
        v = find_set(v);
        if(u != v)
        {
            ++ N;
            adj[N].pb(u);
            adj[N].pb(v);
            adj[u].pb(N);
            adj[v].pb(N);
            w[N] = i;
            p[u] = N;
            p[v] = N;
            p[N] = N;
        }
    }
    dfs(N, N);
    lg = log2(N);
    //cout << up[N][0];
    fti(i, 1, lg)
        fti(j, 1, N)
            up[i][j] = up[i - 1][up[i - 1][j]];
    for(int i=1; i<=lg; ++i) {
            for(int j=1; j<=N; ++j) {
                //up[j][i]=up[up[j][i-1]][i-1];
                cout << up[i][j] << ' ';
            }
            cout << '\n';
        }
//    fti(i, 1, N)
//        cerr << w[i] << " ";
    fti(i, 1, N)
        mn[i][0] = mx[i][0] = tin[i];
    fti(j, 1, lg)
        fti(i, 1, N - (1 << j) + 1)
        {
            mn[i][j] = min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
            mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
        }
    // for(int j=0; j<=lg; ++j) {
    //         for(int i=1; i<=N; ++i) {
    //             //rmqmin[i][j]=min(rmqmin[i][j-1],rmqmin[i+(1<<(j-1))][j-1]),rmqmax[i][j]=max(rmqmax[i][j-1],rmqmax[i+(1<<(j-1))][j-1]);
    //             cout << mn[i][j] << ' ';
    //         }
    //         cout << '\n';
    //     }
    for(int i=1; i<=N; ++i) cout << d[i] << ' ';
    cout << '\n';
    fti(i, 1, q)
    {
        int l, r;
        cin >> l >> r;
        int k = log2(r - l + 1);
        int u = min(mn[l][k], mn[r - (1 << k) + 1][k]);
        int v = max(mx[l][k], mx[r - (1 << k) + 1][k]);
        //cout << u << ' ' << v << '\n';
        //cout << lca(id[u],id[v]) << ' ';
        cout << lca(id[u],id[v]);
        cout << '\n';
        //cout << w[lca(id[u], id[v])] << "\n";
    }
    return 0;
}