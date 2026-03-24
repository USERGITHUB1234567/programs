#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int maxn=100005,maxx=10004;
struct edge
{
    int u,v,w;
} e[maxx];
int p[maxn],n,m,kq=1e9;
void setup()
{
    for(int i=0; i<maxx; i++) p[i]=i;
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
    for(int i=1; i<=m; i++) {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    sort(e+1,e+1+m,cmp);
    setup();
    for(int i=1; i<=m; i++) {
        unite(e[i].u,e[i].v);
    }
    int t=findset(1);
    for(int i=2; i<=n; i++) {
        if(findset(i)!=t) {
            cout << "NO";
            return 0;
        }
    }
    for(int i=1; i<=m-n+2; i++) {
        setup();
        int ln=-1000000000,cnt=0;;
        for(int j=i; j<=m; j++) {
            if(unite(e[j].u,e[j].v)) {
                ln=max(ln,e[j].w);
                cnt++;
                if(cnt==n-1) break;
            }
        }
        if(cnt==n-1) {
            kq=min(kq,ln-e[i].w);
        }
        else break;
    }
    cout << "YES\n" << kq;
}
