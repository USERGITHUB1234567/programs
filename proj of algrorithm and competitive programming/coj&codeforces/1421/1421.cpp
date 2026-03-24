#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int maxn=100005;
int n,m,cnt=0,scc=0,num[maxn],low[maxn],avail[maxn];
vector<int>adj[maxn];
stack<int>st;
void dfs(int u)
{
    num[u]=low[u]=++cnt;
    st.push(u);
    for(int v:adj[u]) {
        if(avail[v]!=0) continue;
        if(num[v]==0) {
            dfs(v);
            low[u]=min(low[u],low[v]);
        }
        else {
            low[u]=min(low[u],num[v]);
        }
    }
    if(low[u]==num[u]) {
        scc++;
        while(true) {
            int v=st.top();
            st.pop();
            avail[v]=scc;
            if(v==u) break;
        }
    }
}vector<int>an[maxn];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for(int i=1; i<=n; i++) if(num[i]==0) dfs(i);

    for(int i=1; i<=n; i++) {
        for(int u:adj[i]) {
            if(avail[i]!=avail[u]) an[avail[i]].push_back(avail[u]);
        }
    }
    for(int i=scc; i>=2; i--) {
        bool ck=false;
        for(int j:an[i]) {
            if(j==i-1) {
                ck=true;
                break;
            }
        }
        if(!ck) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}
