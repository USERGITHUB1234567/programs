#include <bits/stdc++.h>
using namespace std;
const int maxn=2503;
const long long inf=1e18;
int n,m;
array<int,3>edge[maxn<<1];
long long d[maxn];
long long bellman_ford(int s) {
    for(int i=1; i<=n; ++i) {
        if(i==s) d[i]=0;
        else d[i]=LLONG_MAX;
    }
    for(int i=1; i<n; ++i) {
        for(int j=1; j<=m; ++j) {
            auto[u,v,w]=edge[j];
            if(d[u]!=LLONG_MAX && d[v]>d[u]+w) d[v]=d[u]+w;
        }
    }
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=m; ++j) {
            auto[u,v,w]=edge[j];
            if((d[u]==LLONG_MIN || d[v]>d[u]+w) && d[u]!=LLONG_MAX) d[v]=LLONG_MIN;
        }
    }
    return (d[n]==LLONG_MIN?-1:-d[n]);
    //return ans;
}
int main(int argc, char** argv) {
    cin >> n >> m;
    for(int i=1; i<=m; ++i) {
        int u,v,w;cin >> u >> v >> w;
        edge[i]={u,v,-w};
    }
    cout << bellman_ford(1);
}
