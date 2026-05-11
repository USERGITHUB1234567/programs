#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
#define mkp make_pair
#define eb emplace_back
#define fi first
#define se second
using namespace std;
const int maxn=100005,maxl=20;
int n,m,t[maxn],p[maxn][maxl],d[maxn],logn,f[maxn][11];
vector<int>adj[maxn];
vector<int>cow[maxn];
string s="";
void dfs(int u, int pa)
{
    d[u]=(pa==u?0:d[pa]+1);
    p[u][0]=pa;
    if(pa) {
        for(int c=1; c<=10; c++) f[u][c]=f[pa][c];
    }
    f[u][t[u]]++;
    for(int v:adj[u]) {
        if(v!=pa) dfs(v,u);
    }
}
int lca(int u, int v)
{
    if(d[u]<d[v]) swap(u,v);
    for(int i=logn; i>=0; i--) {
        if(d[p[u][i]]>=d[v]) u=p[u][i];
    }
    if(u==v) return u;
    for(int i=logn; i>=0; i--) {
        if(p[u][i]!=p[v][i]) {
            u=p[u][i];
            v=p[u][i];
        }
    }
    return p[u][0];
}
void dfssoup1(int u, int pa, int like, int tar, bool ck)
{
    if(t[u]==like) ck=true;
    if(u==tar) {
        s+=(ck?'1':'0');
        return;
    }
    for(int v:adj[u]) {
        if(v!=pa) dfssoup1(v,u,like,tar,ck);
    }
}
void soup1()
{
    for(int i=1; i<=m; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        dfssoup1(a,0,c,b,false);
    }
    cout << s;
}
void soup2()
{
    dfs(1,1);
    for(logn=1; (1<<logn)<=n; logn++);
    logn--;
    for(int j=1; j<=logn; j++) {
        for(int i=1; i<=n; i++) p[i][j]=p[p[i][j-1]][j-1];
    }
    for(int i=1; i<=m; i++) {
        int a,b,c,d1=0,d2=0,mt=0;
        cin >> a >> b >> c;
        int w=lca(a,b);
        int kq=f[a][c]+f[b][c]-2*f[w][c]+(t[w]==c);
        s+=(kq>0?'1':'0');
    }
    cout << s;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> m;
    for(int i=1; i<=n; i++) cin >> t[i];
    for(int i=1; i<n; i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    soup2();
}
