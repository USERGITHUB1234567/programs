#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int maxn=200005;
int p[maxn],n,m,kq=0,u[maxn],v[maxn];
map<int,int>val;
vector<int>a;
int findset(int u)
{
    if(p[u]==u) return u;
    return p[u]=(findset(p[u]));
}
bool unite(int l, int r)
{
    bool ck=true;
    int u=l,dest=findset(r+1);
    while(u<=r) {
        int x=findset(u);
        if(x!=u) ck=false;
        p[x]=dest;
        u=x+1;
    }
    return ck;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> m >> n;
    for(int i=1; i<=n; i++) {
        cin >> u[i] >> v[i];
        a.push_back(u[i]);
        a.push_back(v[i]);
    }
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());
    int cnt=0;
    for(auto x:a) val[x]=++cnt;
    for(int i=1; i<=cnt+1; i++) p[i]=i;
    int ans=0;
    for(int i=n; i>=1; i--) {
        u[i]=val[u[i]];
        v[i]=val[v[i]];
        if(unite(u[i],v[i])) kq++;
    }
    cout << kq;
}
