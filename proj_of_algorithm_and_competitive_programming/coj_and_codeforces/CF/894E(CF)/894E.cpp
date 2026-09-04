#include <bits/stdc++.h>
using namespace std;
const int maxn=1000006;
int n,m,s,comp[maxn],low[maxn],num[maxn],timer=0,scc;
vector<pair<int,int>>adj[maxn];
array<int,3>edge[maxn];
stack<int>st;
bool inst[maxn];
void tarjan(int u) {
    low[u]=num[u]=++timer;
    inst[u]=true;
    st.push(u);
    for(auto[v,w]:adj[u]) {
        if(!num[v]) {
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }else if(inst[v]) low[u]=min(low[u],num[v]);
    }
    while(low[u]==num[u]) {
        ++scc;
        
    }
}
int main(int argc, char** argv) {
    cin >> n >> m;
    for(int i=1; i<=m; ++i) {
        cin >> edge[i][0] >> edge[i][1] >> edge[i][2];
        adj[edge[i][0]].push_back({edge[i][1],edge[i][2]});
    }

}