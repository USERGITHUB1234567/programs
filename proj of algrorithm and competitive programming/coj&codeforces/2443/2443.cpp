#include <bits/stdc++.h>
#pragma GCC optimize("O3","unroll-loops")
using namespace std;
const int maxn=100005;
int n,q,p[maxn][17],d[maxn],logn;
vector<int>adj[maxn];
void bfs(int s) {
    queue<int>qu;
    qu.push(s);
    d[s]=1;
    p[s][0]=s;
    while(!qu.empty()) {
        int u=qu.front();
        qu.pop();
        for (int v:adj[u]) {
            if (v==p[u][0]) continue;
            p[v][0]=u;
            d[v]=d[u]+1;
            qu.push(v);
        }
    }
}
int lca(int u, int v)
{
    if(d[u]<d[v]) swap(u,v);
    for(int j=logn; j>=0; j--) {
        if(d[p[u][j]]>=d[v]) u=p[u][j];
    }
    if(u==v) return u;
    for(int j=logn; j>=0; j--) {
        if(p[u][j]!=p[v][j]) {
            u=p[u][j];
            v=p[v][j];
        }
    }
    return p[u][0];
}
int dist(int u,int v) {
    int l=lca(u,v);
    return d[u]+d[v]-2*d[l];
}
int solve(int s,int f,int t) {
    return (dist(s,f)+dist(t,f)-dist(s,t)+2)/2;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> q;
    for(int i=2; i<=n; i++) {
        int pi;
        cin >> pi;
        adj[i].push_back(pi);
        adj[pi].push_back(i);
    }
    memset(d,0,sizeof(d));
    bfs(1);
    for(logn=1; (1<<logn)<=n; logn++);
    logn--;
    for(int j=1; j<=logn; j++) {
        for(int i=1; i<=n; i++) {
            p[i][j]=p[p[i][j-1]][j-1];
        }
    }
    while(q--) {
        int a,b,c;
        cin >> a >> b >> c;
        int kq=max({solve(a,b,c),solve(b,a,c),solve(c,a,b),solve(b,c,a),solve(a,c,b),solve(c,b,a)});
        cout << kq << "\n";
    }
}
