#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int maxn=100005;
bool ck[maxn];
int n,k,m;
int p[maxn],a[maxn];
int findset(int u)
{
    if(p[u]==0) return u;
    return p[u]=findset(p[u]);
}
void unite(int u, int v)
{
    u=findset(u);
    v=findset(v);
    if(u!=v) p[u]=v;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    memset(ck,true,sizeof(ck));
    cin >> n >> k;
    for(int i=1; i<=k; i++) {
        int u,v;
        cin >> u >> v;
        unite(u,v);
    }
    cin >> m;
    for(int i=1; i<=m; i++) {
        int u,v;
        cin >> u >> v;
        u=findset(u);
        v=findset(v);
        if(u==v) ck[u]=false;
    }
    for(int i=1; i<=n; i++) {
        a[i]=findset(i);
        //cout << a[i] << " ";
    }
    map<int,int>mp;
    for(int i=1; i<=n; i++) mp[a[i]]++;
    int ma=0;
    for(auto x:mp) {
        if(ck[x.first] && x.second>ma) {
            ma=x.second;
        }
    }
    cout << ma;
}
