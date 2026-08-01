#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(n) freopen(n".inp", "r", stdin); freopen(n".out", "w", stdout);
using namespace std;
const int maxn=10004;
struct edge{int v,w,h;};
vector<edge>adj[maxn];
int k,n,m,a,b,d[maxn];
void dijkstra(int s) {
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
    pq.push({0,{s,k}});for(int i=1; i<=n; ++i) d[i]=INT_MAX/2;
    d[s]=0;
    
    while(!pq.empty()) {
        auto[cd,p]=pq.top();pq.pop();
        auto[u,th]=p;
        if(cd>d[u]) continue;
        for(auto[v,w,h]:adj[u]) {
            if(d[v]>d[u]+w && th>h) {
                d[v]=d[u]+w;
                //cout << w << "\n";
                pq.push({d[v],{v,th-h}});
                //cout << u << " " << d[v] << " " << v << " " << th-h << " " << w << "\n";
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    file("trip")
    cin >> k >> n >> m;
    for(int i=1,u,v,h,w; i<=m; ++i) {
        cin >> u >> v >> w >> h;
        adj[u].push_back({v,w,h});
        adj[v].push_back({u,w,h});
    }
    cin >> a >> b;
    dijkstra(a);
    cout << (d[b]==INT_MAX?-1:d[b]);
    //cout << "a";
}