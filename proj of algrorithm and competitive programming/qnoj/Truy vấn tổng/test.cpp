#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    if(!(cin>>N)) return 0;
    vector<int> parent(N+1);
    for(int i=1;i<=N;i++) cin>>parent[i];
    vector<vector<int>> g(N+1);
    int root = 1;
    for(int i=1;i<=N;i++){
        if(parent[i]==0) root = i;
        else {
            g[parent[i]].push_back(i);
            g[i].push_back(parent[i]);
        }
    }
    vector<int> sz(N+1,0);
    vector<ll> distSum(N+1,0);
    // DFS1: compute sz and distSum[root]
    function<void(int,int,int)> dfs1 = [&](int u,int p,int depth){
        sz[u]=1;
        distSum[root] += depth;
        for(int v: g[u]) if(v!=p){
            dfs1(v,u,depth+1);
            sz[u]+=sz[v];
        }
    };
    distSum[root]=0;
    dfs1(root,0,0);
    // DFS2: reroot to compute distSum for all nodes
    function<void(int,int)> dfs2 = [&](int u,int p){
        for(int v: g[u]) if(v!=p){
            distSum[v] = distSum[u] + (ll)N - 2LL*sz[v];
            dfs2(v,u);
        }
    };
    dfs2(root,0);
    ll best = LLONG_MIN;
    for(int i=1;i<=N;i++) best = max(best, distSum[i]);
    ll answer = (ll)N + best;
    cout<<answer<<"\n";
    return 0;
}
