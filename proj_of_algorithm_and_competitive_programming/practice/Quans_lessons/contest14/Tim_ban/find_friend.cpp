#include <bits/stdc++.h>
using namespace std;
const int maxn=200005;
int n,m,k,c[maxn];
vector<pair<int,int>>adj[maxn];
namespace soup1{
    long long dist[maxn];
    pair<long long,int>ans;
    bool mk[maxn];
    void dijkstra(int st) {
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        for(int i=1; i<=n; ++i) dist[i]=1e18;
        dist[st]=0;
        pq.push({0,st});
        dist[st]=0;
        while(!pq.empty()) {
            auto[cd,u]=pq.top();pq.pop();
            if(cd>dist[u]) continue;
            if(mk[u] && u!=st) ans=min(ans,make_pair(cd,u));
            for(auto[v,w]:adj[u]) {
                if(dist[v]>cd+w) {
                    dist[v]=cd+w;
                    pq.push({dist[v],v});
                }
            }
        }
    } 
    void implement() {
        for(int i=1; i<=k; ++i) mk[c[i]]=true;
        for(int i=1; i<=k; ++i) {
            ans={1e18,1e18};
            dijkstra(c[i]);
            cout << ans.second << '\n';
        }
    }
}
int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> m >> k;
    for(int i=1,u,v,w; i<=m; ++i) {
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    for(int i=1; i<=k; ++i) cin >> c[i];
    soup1::implement();
}