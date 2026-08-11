#include <bits/stdc++.h>
using namespace std;
const int maxn=100005,inf=2e9;
int n,m,id[maxn],total[maxn],num[maxn],low[maxn],f1[maxn],f2[maxn],timer,scc;
vector<int>adj[maxn],rev[maxn],dag[maxn],rdag[maxn];
stack<int>st;
bool inst[maxn],vis[maxn],vis1[maxn],vis2[maxn];
void dfs(int u) {
    low[u]=num[u]=++timer;
    st.push(u);
    inst[u]=true;
    for(int v:adj[u]) {
        if(!num[v]) {
            dfs(v);
            low[u]=min(low[u],low[v]);
        }
        else if(inst[v]) low[u]=min(low[u],num[v]);
    }
    if(low[u]==num[u]) {
        ++scc;
        while(true) {
            int v=st.top();
            st.pop();
            id[v]=scc;
            inst[v]=false;
            ++total[scc];
            if(v==u) {break;}
        }
    }
}
int dfs1(int u) {
    //f1[u]+=total[u];
    if(u==id[1]) return total[id[1]];
    if(vis1[u]) return f1[u];
    int mx=-inf;
    vis1[u]=true;
    for(int v:rdag[u]) {
        mx=max(mx,dfs1(v));
    }
    if(mx!=-inf) mx+=total[u];
    return f1[u]=mx;
}
int dfs2(int u) {
    if(u==id[1]) return total[id[1]];
    if(vis2[u]) return f2[u];
    int mx=-inf;
    vis2[u]=true;
    for(int v:dag[u]) {
        mx=max(mx,dfs2(v));
    }
    if(mx!=-inf) mx+=total[u];
    return f2[u]=mx;
}
int main(int argc, char** argv) {
    cin >> n >> m;
    for(int i=1; i<=m; ++i) {
        int u,v;cin >> u >> v;
        adj[u].push_back(v);
        //adj[v].push_back(u);
    }
    for(int i=1; i<=n; ++i) if(!num[i]) dfs(i);
    for(int i=1; i<=n; ++i) {
        for(int j:adj[i]) {
            if(id[i]!=id[j]) {
                dag[id[i]].push_back(id[j]);
                rdag[id[j]].push_back(id[i]);
            }
        }
    }
    int ans=total[id[1]];
    for(int i=1; i<=n; ++i) {
        for(int j:adj[i]) {
            if(id[i]!=id[j]) {
                int t1=dfs1(id[j]),t2=dfs2(id[i]);
                if(t1!=-inf && t2!=-inf) {
                    ans=max(ans,t1+t2-total[id[1]]);
                }
            }
        }
    }
    cout << ans;
}