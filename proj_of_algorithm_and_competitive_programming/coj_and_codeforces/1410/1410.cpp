#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
const int maxn=100005;
int n,m,cnt=0,nbr=0,ncut=0,num[maxn],low[maxn],par[maxn];
vector<int> adj[maxn];;
bool cut[maxn];
pair<int,int>bridge[maxn];
void dfs(int u) {
    num[u]=low[u]=++cnt;
    for(int v:adj[u]) {
        if(par[v]==0) {
            par[v]=u;
            dfs(v);
            low[u]=min(low[u],low[v]);
        }
        else if(v!=par[u]) {
            low[u]=min(low[u],num[v]);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> m;
    for(int i=1; i<=m; i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(par, 0, sizeof(par));
    for(int i=1; i<=n; i++) {
        if(par[i]==0) {
            par[i]=-1;
            dfs(i);
        }
    }
    int nchild[maxn];
    memset(nchild,0,sizeof(nchild));
    for(int i=1; i<=n; i++) {
        if(par[i]!=-1) nchild[par[i]]++;
    }
    memset(cut,false,sizeof(cut));
    for(int i=1; i<=n; i++) {
        if(par[i]==-1 && nchild[i]>1) {
            ncut++;
            cut[i]=true;
        }
    }
    for(int v=1; v<=n; v++) {
        int u=par[v];
        if(u!=-1 && par[u]!=-1 && !cut[u] && low[v]>=num[u]) {
            ncut++;
            cut[u]=true;
        }
    }
    cout << ncut << "\n";
    bool fir=true;
    for (int i=1; i<=n; i++) {
        if (cut[i]) {
            if (fir) {
                cout << i;
                fir=false;
            } else {
                cout << " " << i;
            }
        }
    }
    if(ncut!=0) cout << "\n";
    for(int i=1; i<=n; i++) {
        if(par[i]!=-1 && low[i]==num[i]) bridge[++nbr]={min(par[i],i),max(par[i],i)};
    }
    sort(bridge+1,bridge+nbr+1);
    cout << nbr << "\n";
    for(int i=1; i<=nbr; i++) {
        cout << bridge[i].first << " " << bridge[i].second << "\n";
    }
}