#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
#define all(x) x.begin(),x.end()
#define eb emplace_back
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
const int maxn=200005,maxl=20;
struct node {
    int len,mlen,mpre,vpre,msuf,vsuf;
};
int n,q,logn,a[maxn],d[maxn],p[maxn][maxl];
vector<int>g[maxn];
node ap[maxn][maxl];
void dfs(int u, int pa) {
    for(int v:g[u]) {
        if(v==pa) continue;
        p[v][0]=u;
        d[v]=d[u]+1;
        ap[v][0]={1,1,1,a[u]-a[v],1,a[u]-a[v]};
        dfs(v,u);
    }
}
node combine(node a, node b) {
    node c={0,0,0,0,0,0};
    c.len=a.len+b.len;
    c.mlen=max(a.mlen,b.mlen);
    if(a.vsuf==b.vpre) c.mlen=max(c.mlen,a.msuf+b.mpre);
    c.mpre=a.mpre;
    c.vpre=a.vpre;
    if(a.len==a.mpre && a.vpre==b.vpre) c.mpre=a.len+b.mpre;
    c.msuf=b.msuf;
    c.vsuf=b.vsuf;
    if(b.len==b.msuf && b.vsuf==a.vsuf) c.msuf=b.len+a.msuf;
    return c;
}
node query(int u, int k) {
    node res={0,0,0,0,0,0};
    for(int i=17; i>=0; i--) {
        if(((k>>i)&1)==1) {
            if(res.len==0) res=ap[u][i];
            else res=combine(res,ap[u][i]);
            u=p[u][i];
        }
    }
    return res;
}
int lca(int u, int v) {
    if(d[u]<d[v]) swap(u,v);
    int diff=d[u]-d[v];
    for(int i=0; i<maxl; i++) {
        if(((diff>>i)&1)==1) u=p[u][i];
    }
    if(u==v) return u;
    for(int i=maxl-1; i>=0; i--) {
        if(p[u][i]!=p[v][i]) {
            u=p[u][i];
            v=p[v][i];
        }
    }
    return p[u][0];
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1,u,v; i<n; i++) {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1,0);
    logn=log2(n)+1;
    for(int j=1; j<=logn; j++) {
        for(int i=1; i<=n; i++) {
            p[i][j]=p[p[i][j-1]][j-1];
            ap[i][j]=combine(ap[i][j-1],ap[p[i][j-1]][j-1]);
        }
    }
    cin >> q;
    while(q--) {
        int u,v;
        cin >> u >> v;
        int w=lca(u,v);
        node a=query(u,d[u]-d[w]);
        node b=query(v,d[v]-d[w]);
        int ans=max(a.mlen,b.mlen);
        if(a.vsuf+b.vsuf==0) ans=max(ans,a.msuf+b.msuf);
        cout << ans+1 << "\n";
    }
}