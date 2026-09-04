#include <bits/stdc++.h>
using namespace std;
const int maxn=200005;
int n;
vector<pair<int,int>>adj[maxn];
pair<int,long long>f[maxn][2];
void dfs(int u, int p) {
    pair<int,long long>tot={0,0};
    for(auto[v,w]:adj[u]) {
        if(v!=p) {
            f[u][1]=max(f[u][1],make_pair(1,(long long)w));
            dfs(v,u);
            //f[u][0]=max({f[u][0],f[v][0],f[v][1]});
            //tot={tot.first+f[v][0].first,tot.second+f[v][0].second};
            tot={tot.first+max(f[v][0],f[v][1]).first,tot.second+max(f[v][0],f[v][1]).second};
        }
    }
    f[u][0]=tot;
    for(auto[v,w]:adj[u]) {
        if(v==p) continue;
        pair<int,long long>best=max(f[v][0],f[v][1]);
        pair<int,long long>extra={tot.first-best.first+f[v][0].first+1,tot.second-best.second+f[v][0].second+w};
        f[u][1]=max(f[u][1],extra);
    }
}
int main(int argc, char** argv) {
    cin >> n;
    for(int i=1,u,v,w; i<n; ++i) {
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    dfs(1,0);
    pair<int, long long>res=max(f[1][0],f[1][1]);
    // for(int i=1; i<=n; ++i) {
    //     cout << f[i][0].first << ' ' << f[i][0].second << "  " << f[i][1].first << ' ' << f[i][1].second << '\n';
    // }
    cout << res.second;
}