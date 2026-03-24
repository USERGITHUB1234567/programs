#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long d[100005][55];
long long n,m;
vector<pair<long long ,long long>>adj[100005];
void dijkstra()
{
    for(int i=1; i<=n; i++) {
        for(int j=0; j<=50; j++) d[i][j]=2e9;
    }
    d[1][0]=0;
    priority_queue<pair<int,pair<int,int>>> pq;
    pq.push({0,{1,0}});
    while(!pq.empty()) {
        int cur_d=-pq.top().first, u=pq.top().second.first,w1=pq.top().second.second;
        pq.pop();
        if(cur_d>d[u][w1]) continue;
        for(auto [v,w2]:adj[u]) {
            if(w1==0) {
                if(d[v][w2]>cur_d) {
                    d[v][w2]=cur_d;
                    pq.push({-d[v][w2], {v,w2}});
                }
            }
            else {
                if(d[v][0]>cur_d+(w1+w2)*(w1+w2)) {
                    d[v][0]=cur_d+(w1+w2)*(w1+w2);
                    pq.push({-d[v][0],{v,0}});
                }
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for(int i=1; i<=m; i++) {
        long long u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    dijkstra();
    for(int i=1; i<=n; i++) {
        cout << (d[i][0]==2e9?-1:d[i][0]) << (i==n?"":" ");
    }
}
