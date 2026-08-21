#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int maxn=200005;
int n,q,p[2][maxn],a[maxn],b[maxn];
int findset(int t, int u)
{
    if(p[t][u]==0) return u;
    return p[t][u]=findset(t,p[t][u]);
}
void unite(int t, int u, int v)
{
    u=findset(t,u);
    v=findset(t,v);
    if(u!=v) {
        p[t][u]=v;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> q;
    vector<pair<int,int>>a[2];
    while(q--) {
        int x,u,v;
        cin >> x >> u >> v;
        x--;
        unite(x,u,v);
        a[1-x].push_back({u,v});
        while(!a[0].empty() && findset(0,a[0].back().first)==findset(0,a[0].back().second)) a[0].pop_back();
        while(!a[1].empty() && findset(1,a[1].back().first)==findset(1,a[1].back().second)) a[1].pop_back();
        if(a[0].empty() && a[1].empty()) cout << "Yes\n";
        else cout << "No\n";
    }
}
