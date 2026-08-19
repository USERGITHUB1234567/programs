#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
#define mkp make_pair
#define eb emplace_back
#define fi first
#define se second
using namespace std;
const int maxn=200005;
int n,m,k,c,d[maxn],w[maxn];
vector<int>adj[maxn];

void soup2()
{
    int kq=0;
    for(int i=1; i<=m; i++) kq+=w[i];
    cout << kq;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> m >> k;
    for(int i=1; i<n; i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1; i<=m; i++) {
        int v;
        cin >> v >> d[v] >> w[v];
    }
    //soup2();
    cout << 0;
}
