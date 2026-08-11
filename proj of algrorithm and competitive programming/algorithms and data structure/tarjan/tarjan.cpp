#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;
int n,m;vector<int>adj[maxn];
int num[maxn],low[maxn],mk[maxn],timer=0,scc=0;
bool inst[maxn];
stack<int>st;
vector<int>store;
void dfs(int u) {
    low[u]=num[u]=++timer;
    inst[u]=true;
    st.push(u);
    for(int v:adj[u]) {
        if(!num[v]) {
            dfs(v);
            low[u]=min(low[u],low[v]);
        }
        else if(inst[v])low[u]=min(low[u],num[v]);
    }
    if(low[u]==num[u]) {
        ++scc;
        while(true) {
            int v=st.top();
            mk[v]=scc;
            inst[v]=false;
            st.pop();
            if(v==u) break;
        }
    }
}
int main(int argc, char** argv) {
    cin >> n >> m;
    for(int i=1,u,v; i<=m; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        //adj[v].push_back(u);
    }
    dfs(1);
    if(scc==1 && timer==n) {cout << "YES";}
    else {
        cout << "NO\n";
        int t1,t2;
        for(int i=1; i<=n; ++i) {
            if(mk[i]==1) t1=i;
            else t2=i;
        }
        cout << t1 << ' ' << t2;
    }
}