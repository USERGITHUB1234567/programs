#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n,m,p[10001],h[10001];
set<int>kq;
void setup()
{
    for(int i=0; i<n; i++) {
        p[i]=i;
        h[i]=0;
    }
}
int findset(int u)
{
    if(p[u]==u) return u;
    return p[u]=findset(p[u]);
}
bool unionset(int u, int v)
{
    u=findset(u);
    v=findset(v);
    if(u==v) return false;
    if(h[u]<h[v]) swap(u,v);
    p[v]=u;
    if(h[u]==h[v]) h[u]++;
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> m;
    int ans=0;
    setup();
    for(int i=1; i<=m; i++) {
        int u,v;
        cin >> u >> v;
        if(unionset(u,v)) {
            ans++;
            kq.insert(u);
            kq.insert(v);
        }
        else if(kq.size()!=n) {
            ans++;
        }
    }
    cout << ans;
}
