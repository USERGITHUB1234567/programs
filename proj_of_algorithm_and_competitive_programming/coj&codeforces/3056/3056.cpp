#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n,m,pre[100005];
long long dist[100005];
vector<pair<int,int>>adj[100005];
void dijkstra(int s)
{
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
    dist[s]=0;
    pq.push({dist[s],s});
    while(!pq.empty()) {
        auto[cd,u]=pq.top();
        pq.pop();
        if(cd>dist[u]) continue;
        for(auto[v,w]:adj[u]) {
            if(dist[v]>dist[u]+w) {
                dist[v]=dist[u]+w;
                pq.push({dist[v],v});
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    fill(dist,dist+100005,1e15);
    cin >> n >> m;
    for(int i=1; i<=m; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
    }
    dijkstra(1);
    for(int i=1; i<n; i++) {
        cout << dist[i] << " ";
    }
    cout << dist[n];
}
