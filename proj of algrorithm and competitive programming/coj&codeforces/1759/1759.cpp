#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int maxn=100005,maxe=100005;
int n,m,num[maxn],low[maxn],par[maxn][20],cnt=0,numout[maxn],q;
vector<int>adj[maxn];
void setup() {
    memset(par,0,sizeof(par));
    memset(low,0,sizeof(low));
    memset(num,0,sizeof(num));
}
bool descendant(int u, int v) {
    return (num[u]>=num[v] && numout[u]<=numout[v]);
}
int child(int u, int v) {
    for(int i=17; i>=0; i--) {
        if(descendant(par[v][i],u) && par[v][i]!=u) v=par[v][i];
    }
    return v;
}
void dfs(int u) {
    num[u]=low[u]=++cnt;
    for(int v:adj[u]) {
        if(num[v]==0) {
            par[v][0]=u;
            dfs(v);
            low[u]=min(low[u],low[v]);
        }
        else if(v!=par[u][0]) low[u]=min(low[u],num[v]);
    }
    numout[u]=cnt;
}
bool query1(int a, int b, int g1, int g2) {
    if(num[g1]>num[g2]) swap(g1,g2);
    if(par[g2][0]!=g1) return true;
    if(low[g2]<=num[g1]) return true;
    if(descendant(a,g2) == descendant(b,g2)) return true;
    return false;
}
bool query2(int a, int b, int c) {
    if(num[a]>num[b]) swap(a,b);
    if(par[b][0]==a) return true;
    if(descendant(b,a)) {
        if(descendant(c,a) && descendant(b,c)) {
            b=child(c,b);
            if(low[b]>=num[c]) return false;
            return true;
        }
    }
    if(descendant(a,c) && descendant(b,c)) {
        a=child(c,a);
        b=child(c,b);
        if(a==b) return true;
        if(low[a]<num[c] && low[b]<num[c]) return true;
        return false;
    }
    if(descendant(a,c) || descendant(b,c)) {
        if(descendant(b,c)) swap(a,b);
        a=child(c,a);
        if(low[a]<num[c]) return true;
        return false;
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    setup();
    cin >> n >> m;
    for(int i=1; i<=m; i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    for(int j=1; j<=17; j++) {
        for(int i=1; i<=n; i++) par[i][j]=par[par[i][j-1]][j-1];
    }
    cin >> q;
    for(int i=1; i<=q; i++) {
        int t;
        cin >> t;
        if(t==1) {
            int a,b,g1,g2;
            cin >> a >> b >> g1 >> g2;
            cout << (query1(a,b,g1,g2)?"yes\n":"no\n");
        }
        else {
            int a,b,c;
            cin >> a >> b >> c;
            cout << (query2(a,b,c)?"yes\n":"no\n");
        }
    }
}