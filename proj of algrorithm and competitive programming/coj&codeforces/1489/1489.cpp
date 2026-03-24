#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n,logn,m,p[100001][17],depth[100001],s[100001];
vector<int>adj[100001];
int lca(int u, int v,int &u0, int &v0)
{
    bool ck=false;
    if(depth[u]<depth[v]) {
        swap(u,v);
        ck=true;
    }
    for(int j=logn; j>=0; j--) {
        if(depth[p[u][j]]>depth[v]) u=p[u][j];
    }
    if(u==v) return u;
    for(int j=logn; j>=0; j--) {
        if(p[u][j]!=p[v][j]) {
            u=p[u][j];
            v=p[v][j];
        }
    }
    u0=u,v0=v;
    if(ck) swap(u0,v0);
    return p[u][0];
}
int dist(int u, int v)
{
    return depth[u]+depth[v]-2*depth[lca(u,v,u,v)];
}
void dfs(int u,int f)
{
    s[u]=1;
    for(int v:adj[u]) {
        if(v!=f) {
            depth[v]=depth[u]+1;
            p[v][0]=u;
            dfs(v,u);
            s[u]+=s[v];
        }
    }
}
int anc(int u,int k)
{
    for(int i=0; i<=logn; i++) {
        if(k&(1<<i)) u=p[u][i];
    }
    return u;
}
int main()
{
    memset(s,1,sizeof(s));
    cin >> n;
    for(logn=1; (1<<logn)<=n; logn++);
    logn--;
    depth[1]=1;
    dfs(1,0);
    for(int j=1; j<=logn; j++) {
        for(int i=1; i<=n; i++) {
            p[i][j]=p[p[i][j-1]][j-1];
        }
    }
    for(int i=1; i<n; i++) {
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cin >> m;
    while(m--) {
        int u,v;
        cin >> u >> v;
        if(u==v) cout << n << "\n";
        else if(dist(u,v)%2==1) cout << 0 << "\n";
        else {
            int u0,v0;
            int l=lca(u,v,u0,v0);
            if(dist(u,l)==dist(v,l)) {
                lca(u,v,u0,v0);
                cout << n-s[u0]-s[v0] << "\n";
            }
            else {
                int p1=anc(u,depth[u]-dist(u,l)/2);
                int p2=anc(u,depth[u]-dist(u,l)/2-1);
                cout << s[p1]-s[p2] << "\n";
        }
    }
}
}
