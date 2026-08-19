#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

const int maxn=100005;
int n,m,logn,p[maxn][17],d[maxn];
vector<int>adj[maxn];
void dfs(int u,int pr) {
    p[u][0]=pr;
    d[u]=(u==pr?1:d[pr]+1);
    for (int v:adj[u]) {
        if (v==pr) continue;
        dfs(v,u);
    }
}
int lca(int u, int v) {
    if (d[u]<d[v])
        swap(u,v);
    for (int j=logn; j>=0; j--) {
        if (d[p[u][j]]>=d[v])
            u=p[u][j];
    }
    if (u==v)
        return u;
    for (int j=logn; j>=0; j--) {
        if (p[u][j]!=p[v][j]) {
            u=p[u][j];
            v=p[v][j];
        }
    }
    return p[u][0];
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> m;
    for (int i=1; i<n; i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(d,0,sizeof(d));
    dfs(1,1);
    for (logn=1; (1<<logn)<=n; logn++);
    logn--;
    for (int j=1; j<=logn; j++) {
        for (int i=1; i<=n; i++) {
            p[i][j]=p[p[i][j-1]][j-1];
        }
    }
    while (m--) {
        int a,b,c;
        cin >> a >> b >> c;
        int t1=lca(a,b),t2=lca(a,c),t3=lca(b,c);
        int ans=t1;
        if(d[t2]>d[ans]) ans=t2;
        if(d[t3]>d[ans]) ans=t3;
        cout << ans << "\n";
    }
    return 0;
}
