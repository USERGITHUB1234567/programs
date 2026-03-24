#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int maxn=200005;
int n,m;
struct edge
{
    int u,v,w;
} a[maxn];
int p[maxn];
void setup()
{
    for(int i=0; i<maxn; i++) p[i]=i;
}
int findset(int u)
{
    if(p[u]==u) return u;
    return p[u]=findset(p[u]);
}
bool unite(int u, int v)
{
    u=findset(u);
    v=findset(v);
    if(u==v) return false;
    p[u]=v;
    return true;
}
bool cmp(edge a, edge b)
{
    return a.w<b.w;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> m;
    setup();
    for(int i=1; i<=m; i++) {
        cin >> a[i].u >> a[i].v >> a[i].w;
    }
    sort(a+1,a+1+m,cmp);
    long long kq=0;
    for(int i=1; i<=m; i++) {
        if(unite(a[i].u, a[i].v)) kq+=a[i].w;
    }
    cout << kq;
}
