#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(n) freopen(n".inp", "r", stdin); freopen(n".out", "w", stdout);
using namespace std;
const int maxn=5003;
struct ed {int v,w,id;};
int n,m,d[2][maxn],t1,t2,timer=0,num[maxn],low[maxn];
vector<ed>adj[maxn];
pair<int,int>edge[maxn];
bool bridge[maxn];
void dijkstra(int s, int t) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    for(int i=1; i<=n; ++i) d[t][i]=INT_MAX;
    pq.push({0,s});
    d[t][s]=0;
    while(!pq.empty()) {
        auto[cd,u]=pq.top();pq.pop();
        if(cd>d[t][u]) continue;
        for(auto[v,w,i]:adj[u]) {
            if(d[t][v]>d[t][u]+w) {
                d[t][v]=d[t][u]+w;
                pq.push({d[t][v],v});
            }
        }
    }
}
void dfs(int u, int p) {
    num[u]=low[u]=++timer;
    for(auto[v,w,i]:adj[u]) {
        if(v==p) continue;
        if(!num[v]) {
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>num[u]) bridge[i]=true;
        }
        else low[u]=min(low[u],num[v]);
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    file("robots")
    cin >> n >> m;
    for(int i=1,u,v,w; i<=m; ++i) {
        cin >> u >> v >> w;
        adj[u].push_back({v,w,i});
        adj[v].push_back({u,w,i});
        edge[i]={u,v};
    }
    cin >> t1 >> t2;
    dijkstra(t1,0);
    dijkstra(t2,1);
    dfs(1,0);
    int res=INT_MAX;
    for(int i=1; i<=m; ++i) {
        auto[u,v]=edge[i];
        if(!bridge[i]) continue;
        res=min(res,max(d[0][u],d[1][v]));
        res=min(res,max(d[0][v],d[1][u]));
        //cout << res << " " << u << ' ' << v << "\n";
    }
    cout << res;
    //cout << "a";
}
/*
8 11
1 2 3
1 3 5
1 4 8
2 4 3
3 4 4
4 5 2
5 6 9
5 7 3
6 7 4
6 8 5
7 8 6
3 6
*/