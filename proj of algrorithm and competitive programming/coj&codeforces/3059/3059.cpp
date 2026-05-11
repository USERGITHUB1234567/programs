#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#define int long long
using namespace std;
int n,m,k,d[100005];
vector<int>kq;
priority_queue<int>di[100005];
vector<pair<int,int>>adj[100005];
void dijkstra(int s)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    d[s]=0;
    pq.push({d[s],s});
    di[1].push(0);
    while(!pq.empty()) {
        int u=pq.top().second,cd=pq.top().first;
        pq.pop();
        if(cd>di[u].top()) continue;
        for(int i=0; i<adj[u].size(); i++) {
            int v=adj[u][i].first,w=adj[u][i].second;
            if(di[v].size()<k) {
                di[v].push(cd+w);
                pq.push({cd+w,v});
            }
            else if(cd+w<di[v].top()) {
                di[v].pop();
                di[v].push(cd+w);
                pq.push({cd+w,v});

            }

            //if(v==n) kq.push_back(d[u]+w);
            //if(kq.size()>k) return;
        }
    }
}
signed main()
{
    //fill(d,d+100005,1e15);
    cin >> n >> m >> k;
    for(int i=1; i<=m; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
    }
    dijkstra(1);
    while(!di[n].empty()) {
        kq.push_back(di[n].top());
        di[n].pop();
    }
    sort(kq.begin(),kq.end());
    for(int i=0; i<k-1; i++) cout << kq[i] << " ";
    cout << kq[k-1];
}
