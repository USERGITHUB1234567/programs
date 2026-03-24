#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int maxn=100005,inf=1000000009;
int n,m,d[maxn],k;
bool hd[maxn];
vector<pair<int,int>>adj[maxn];
void dijkstra(int s)
{
    for(int i=0; i<maxn; i++) d[i]=inf;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    d[s]=0;
    pq.push({0,s});
    while(!pq.empty()) {
        auto[cd,u]=pq.top();
        pq.pop();
        if(cd>d[u]) continue;
        for(auto [v,w]:adj[u]) {
            if(d[v]>d[u]+w) {
                d[v]=d[u]+w;
                pq.push({d[v],v});
            }
        }
    }
}
void soup1(int t)
{
    dijkstra(1);
    cout << d[t];
}
void soup2()
{
    dijkstra(1);
    cout << *max_element(d+1,d+1+n);
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> m;
    for(int i=1; i<=m; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    cin >> k;
    int t;
    for(int i=1; i<=k; i++) {
        int x;
        cin >> x;
        hd[x]=true;
        t=x;
    }
    if(k==1) soup1(t);
    if(k==n) {
        soup2();
    }
}
