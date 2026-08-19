#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int maxn=100005;
int n,m,q;
vector<pair<int,int>>adj[maxn];
int main()
{
    cin >> n >> m;
    for(int i=1; i<=m; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[w].push_back({u,w});
    }

}
