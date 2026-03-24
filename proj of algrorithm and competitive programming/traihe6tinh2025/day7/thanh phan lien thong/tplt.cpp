#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int maxn=1000006;
int n,m,p[maxn];
int findset(int u)
{
    if(p[u]==0) return u;
    return p[u]=findset(p[u]);
}
void unite(int u, int v)
{
    u=findset(u);
    v=findset(v);
    if(u==v) return;
    p[u]=v;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> m;
    for(int i=1; i<=m; i++) {
        int t,u,v;
        cin >> t >> u >> v;
        if(t==1) unite(u,v);
        else {
            u=findset(u);
            v=findset(v);
            if(u==v) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
    }
}
