#include <bits/stdc++.h>
using namespace std;
const int maxn=100005,mod=1000000007;
long long a[maxn],n,q,p[maxn][20],d[maxn],logn,pr[maxn][20];
vector<int>adj[maxn];
void dfs1(int u, int p, int t, int x, long long kq)
{
    kq=(__gcd(a[u],(long long)x)*kq)%mod;
    if(u==t) {
        cout << kq << "\n";
        return;
    }
    for(int v:adj[u]) {
        if(v!=p) dfs1(v,u,t,x,kq);
    }
}
void dfs2(int u, int pa)
{
    p[u][0]=pa;
    d[u]=(u==pa?1:d[pa]+1);
    for(int v:adj[u]) {
        if(v!=pa) dfs2(v,u);
    }
}
long long lca(int u, int v)
{
    long long kq=1;
    if(d[u]<d[v]) swap(u,v);
    for(int j=logn; j>=0; j--) {
        if(d[p[u][j]]>=d[v]) u=p[u][j];
    }
    if(u==v) return (long long)u;
    for(int j=logn; j>=0; j--) {
        if(p[u][j]!=p[v][j]) {
            u=p[u][j];
            v=p[v][j];
        }
    }
    return (long long)p[u][0];
}
void soup1()
{
    for(int i=1; i<=q; i++) {
        int u,v,x;
        cin >> u >> v >> x;
        //cout << dfs(u,u,v,x,1) << "\n";
        dfs1(u,u,v,x,1);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> q;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<n; i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(n<=10000 && q<=10000) {
        soup1();
        return 0;
    }
    for(logn=1; (1<<logn)<=n; logn++);
    logn--;
    dfs2(1,1);
    for(int j=1; j<=logn; j++) {
        for(int i=1; i<=n; i++) {
            p[i][j]=p[p[i][j-1]][j-1];

        }
    }
    for(int i=1; i<=q; i++) {

    }
}
/*
Input
4 3
1 2 3 4
1 2
2 3
3 4
1 4 1
4 4 2
1 4 2
*/
