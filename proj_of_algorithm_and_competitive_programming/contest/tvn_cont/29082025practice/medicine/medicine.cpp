#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define file(name) freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout);
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define int long long
using namespace std;
typedef long long ll;
const int maxn=200005;
const ll mod=1000000007;
ll m,n,num[maxn],low[maxn],comp[maxn],ncomp=0,in[maxn],sz[maxn],timer=0;
pair<ll,ll>med[maxn];
bool inst[maxn];
stack<int>st;
vector<int>adj[maxn];
vector<pair<int,int>>edge;
ll modexp(ll a, ll b)
{
    ll s=1;
    while(b>0) {
        if(b&1) s=(s*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return s;
}

void dfs(int u)
{
    low[u] = num[u] = ++timer;
    st.push(u);
    inst[u] = true;
    for (auto v : adj[u]) {
        if (!num[v]) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else if (inst[v])
            low[u] = min(low[u], num[v]);
    }
    if (low[u] == num[u]) {
        ncomp++;
        while (true) {
            int v = st.top();
            st.pop();
            comp[v] = ncomp;
            inst[v] = false;
            sz[ncomp]++;
            if (v == u) break;
        }
    }
}

signed main()
{
    //fast
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    file("medicine");
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        edge.pb({x, y});
    }
    memset(inst, false, sizeof(inst));
    memset(sz, 0, sizeof(sz));
    for (int i = 1; i <= n; i++) {
        if (!num[i]) dfs(i);
    }
    memset(in, 0, sizeof(in));
    for (auto [x, y] : edge)
        if (comp[x] != comp[y]) in[comp[x]]++;
    ll kq = 1;
    for (int i = 1; i <= ncomp; i++) {
        ll cnt = modexp(2, sz[i]);
        if (!in[i]) cnt--;
        kq *= cnt;
        kq %= mod;
    }
    cout << kq;
    return 0;
}

/*
6 5
4 1
5 1
4 5
1 3
3 2
2 1
*/
