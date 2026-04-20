#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#define int long long
using namespace std;
const int maxn=100005,mod=1e9+7;
struct node
{
    int u,w,t;
};
vector<node>adj[maxn];
int n,m,k, t[maxn],c[maxn],d[maxn],xb[maxn],pre[maxn];
/*void dijkstra(int s)
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>q;
    d[s]=0;
    xb[s]=0;
    q.push({0,s});
    while(!q.empty()) {
        int cd=q.top().first,u=q.top().second;
        q.pop();
        //cout << u << ' ';
        if(cd>d[u]) continue;
        for(int i=0; i<adj[u].size(); i++) {
            int v=adj[u][i].u, w=adj[u][i].w, t=adj[u][i].t;
            //cout << w << ' ' << d[u]+w << " ";
            if(d[v]>=d[u]+w) {
                d[v]=d[u]+w;
                pre[v]=u;
                if(t==1) xb[v]=min(xb[u]+1,xb[v]);
                else xb[v]=min(xb[u],xb[v]);
                q.push({d[v],v});
                //cout << xb[u] << ' ' << xb[v] << "\n";
            }
        }
    }
}
/*vector<int>v;
void trace(int u)
{
    if(pre[u]==-1) return;
}*/
void dij(int s)
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>q;
    d[s]=0;
    q.push({0,s});
    while(!q.empty()) {
        int cd=q.top().first,u=q.top().second;
        q.pop();
        //cout << u << ' ';
        if(cd>d[u]) continue;
        for(int i=0; i<adj[u].size(); i++) {
            int v=adj[u][i].u, w=adj[u][i].w, t=adj[u][i].t;
            if(d[v]>d[u]+w) {
                d[v]=d[u]+w;
                q.push({d[v],v});
            }
        }
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    for(int i=0; i<maxn; i++) {
        d[i]=4e18;
        pre[i]=-1;
        xb[i]=4e18;
    }
    cin >> n >> m >> k;
    for(int i=1; i<=k; i++) {
        cin >> t[i];
    }
    for(int i=1; i<=k; i++) {
        cin >> c[i];
    }
    for(int i=1; i<=m; i++) {
        int u,v,p;
        cin >> u >> v >> p;
        int ti=t[p],ci=c[p];
        adj[u].push_back({v,ci,ti});
        adj[v].push_back({u,ci,ti});
    }
    dij(1);
    cout << d[n] << " " << 0;
    for(int i=1; i<=n; i++) cout << d[i] << ' ';
    //cout << d[1] << " ";
}
