#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define file(name) freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout);
#define fi first
#define se second
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
const int maxn=300005;
const ll mod=998244353;
int n,m;
long long kq=0;
vector<int>adj[maxn];
bool vis[maxn];
void dfs(int u)
{
    kq++;
    kq%=mod;
    vis[u]=true;
    for(int v:adj[u]) {
        if(!vis[v]) dfs(v);
    }
}
void soup1()
{
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=n; ++j) vis[j]=false;
        dfs(i);
        //cout << kq << "\n";
    }
    //cout << kq;
    cout << adj[2].size();
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    file("treval")
    cin >> n >> m;
    for(int i=1,u,v; i<=n; ++i) {
        cin >> u >> v;
        adj[u].pb(v);
        //adj[v].pb(u);
    }
    soup1();
}
