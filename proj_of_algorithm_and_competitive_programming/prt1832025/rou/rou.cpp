#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n,m,pre[100005];
vector<int>adj[100005];
vector<int>re;
bool vis[100005],kt=false;
int in[100005],ou[100005],e,t;
void dfs(int s, int f)
{
    if(f==-1) pre[s]=-1;
    if(adj[s].size()==0) return;
    for(int v:adj[s]) {
        //cout << v << " ";
        if(v==t and v!=f) {
            kt=true;
            e=s;
            return;
        }
        if(!vis[v] and v!=f) {
            vis[v]=true;
            pre[v]=s;
            dfs(v,s);
        }
    }
}
void trace(int u)
{
    re.push_back(u);
    if(pre[u]!=-1) trace(pre[u]);
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    freopen("rou.inp", "r", stdin);
    freopen("rou.out", "w", stdout);
    memset(in,0,sizeof(in));
    memset(ou,0,sizeof(ou));
    cin >> n >> m;
    for(int i=1; i<=m; i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        in[v]++;
        in[u]++;
        ou[u]++;
        ou[v]++;
    }
    for(int i=1; i<=n; i++) {
        if(in[i]>=2 and ou[i]>=2) {
            t=i;
            dfs(i,-1);
            break;
        }
    }
    trace(e);
    if(!kt) cout << "IMPOSSIBLE";
    else {
        cout << re.size()+1 << "\n";
        cout << re[0] << " ";
        for(int i=re.size()-1; i>=0; i--) cout << re[i] << " ";

    }
}
