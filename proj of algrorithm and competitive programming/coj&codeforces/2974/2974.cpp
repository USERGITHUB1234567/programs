#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int maxn=200005;
int p[maxn],n,m,sz[maxn],slt;
long long ans=0;
struct ed
{
    int u,v,c;
}a[maxn];
bool cmp(ed a, ed b)
{
    return a.c>b.c;
}
void setup()
{
    for(int i=0; i<maxn; i++) {
        p[i]=-1;
        sz[i]=1;
    }
}
int findset(int u)
{
    if(p[u]==-1) return u;
    return p[u]=findset(p[u]);
}
bool unionset(int u, int v)
{
    u=findset(u);
    v=findset(v);
    if(u==v) return false;
    if(sz[u]<sz[v]) swap(u,v);
    p[v]=u;
    sz[u]+=sz[v];
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    setup();
    cin >> n >> m;
    slt=n;
    for(int i=1; i<=m; i++) cin >> a[i].u >> a[i].v >> a[i].c;
    sort(a+1,a+1+m,cmp);
    vector<int>w;
    for(int i=1; i<=m; i++) {
        if(unionset(a[i].u,a[i].v)) slt--;
        else w.push_back(a[i].c);
    }
    int k=w.size();
    if(k==0) {
        cout << 0;
        return 0;
    }
    for(int i=k; i>=k-(slt-1); i--) ans+=w[i];
    cout << ans;
}
