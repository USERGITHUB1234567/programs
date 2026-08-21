#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
#define mkp make_pair
#define eb emplace_back 
using namespace std;
const int maxn=200005,maxl=20;
int low[maxn],num[maxn],cnt=0,dcomp=0,comp[maxn],n,m,q,p[maxn][maxl],logn,d[maxn],comp1[maxn],comcnt=0;
bool bridge[maxn],vis[maxn];
vector<pair<int,int>>adj[maxn];
pair<int,int>edge[maxn];
vector<int>tree;
void dfs(int u, int p) {
    low[u]=num[u]=++cnt;
    comp1[u]=comcnt;
    for(auto [v,i]:adj[u]) {
        if(num[u]) {
            low[u]=min(low[u],num[v]);
        }
        else {
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]==num[v]) bridge[i]=true;
        }
    }
}
void dfslca(int u, int pa) {
    d[u]=(pa==u?0:d[pa]+1);
    p[u][0]=pa;
    for(auto [v,i]:adj[u]) {
        if(v!=pa) dfs(v,u);
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> m >> q;
    for(int i=1; i<=m; i++) {
        cin >> edge[i].first >> edge[i].second;
        adj[edge[i].first].emplace_back(edge[i].second,i);
        adj[edge[i].second].emplace_back(edge[i].first,i);
    }
    for(int i=1; i<=n; i++) {
        if(num[i]==1) {
            ++comcnt;
            dfs(i,0);
        }
    }
    dfslca(1,1);
}