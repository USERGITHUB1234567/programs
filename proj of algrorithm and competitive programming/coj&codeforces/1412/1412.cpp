#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;
int n,m,cnt=0,num[maxn],low[maxn];
vector<int>adj[maxn];
stack<pair<int,int>>st;
vector<vector<int>>bcc;
void dfs(int u, int p) {
    num[u]=low[u]=++cnt;
    for(int v:adj[u]) {
        if(v==p) continue;
        if(num[v]!=0) low[u]=min(low[u],num[v]);
        else {
            st.push({u,v});
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>=num[u]) {
                vector<int>comp={u};
                while(true) {
                    pair<int,int>e=st.top();
                    st.pop();
                    comp.push_back(e.second);
                    if(e==make_pair(u,v)) break;
                }
                sort(comp.begin(),comp.end());
                bcc.push_back(comp);
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    memset(num,0,sizeof(num));
    cin >> n >> m;
    for(int i=1; i<=m; i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1; i<=n; i++) {
        if(num[i]==0) {
            dfs(i,0);
            if(adj[i].size()==0) {
                vector<int>comp={i};
                bcc.push_back(comp);
            }
        }
    }
    sort(bcc.begin(),bcc.end());
    cout << bcc.size() << "\n";
    for(int i=0; i<bcc.size(); i++) {
        for(int j=0; j<bcc[i].size(); j++) {
            cout << bcc[i][j] << (j<bcc[i].size()-1?" ":"");
        }
        cout << "\n";
    }
}