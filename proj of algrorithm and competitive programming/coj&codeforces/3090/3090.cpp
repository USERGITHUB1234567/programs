#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#define int long long
using namespace std;
const int mod1=1e9+3,mod2=1e9+7,maxn=200005;
int n,m,d[2][maxn],c[2][2][maxn],l[maxn],r[maxn],mid[maxn];
vector<pair<int,int>>adj[maxn];
void dijkstra(int t, int s)
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    for(int i=1; i<=n; i++) {
        d[t][i]=4e18;
        c[t][0][i]=c[t][1][i]=0;
    }
    d[t][s]=0;
    c[t][0][s]=c[t][1][s]=1;
    pq.push({0,s});
    while(!pq.empty()) {
        auto[cd,u]=pq.top();
        pq.pop();
        if(cd>d[t][u]) continue;
        for(auto[v,w]:adj[u]) {
            if(d[t][u]+w<d[t][v]) {
                c[t][0][v]=c[t][0][u];
                c[t][1][v]=c[t][1][u];
                d[t][v]=d[t][u]+w;
                pq.push({d[t][v],v});
            }
            else if(d[t][u]+w==d[t][v]) {
                c[t][0][v]=(c[t][0][v]+c[t][0][u])%mod1;
                c[t][1][v]=(c[t][1][v]+c[t][1][u])%mod2;
            }
        }
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> m;
    for(int i=1; i<=m; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
        l[i]=u;
        r[i]=v;
        mid[i]=w;
    }
    dijkstra(0,1);
    dijkstra(1,n);
    for(int i=1; i<=m; i++) {
        if((d[0][l[i]]+mid[i]+d[1][r[i]]==d[0][n] && (c[0][0][l[i]]*c[1][0][r[i]])%mod1==c[0][0][n] && (c[0][1][l[i]]*c[1][1][r[i]])%mod2==c[0][1][n]) ||
            d[0][r[i]]+mid[i]+d[1][l[i]]==d[0][n] && (c[0][0][r[i]]*c[1][0][l[i]])%mod1==c[0][0][n] && (c[0][1][r[i]]*c[1][1][l[i]])%mod2==c[0][1][n])
                cout << "Yes\n";
        else cout << "No\n";
    }
}
