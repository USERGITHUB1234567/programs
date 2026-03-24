#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
#define all(x) x.begin(),x.end()
#define eb emplace_back
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
const int maxn=100005;
int num[maxn],low[maxn],timer=0,n,m,comp[maxn],ncomp=0,d[maxn];
vector<pair<int,int>>adj[maxn];
bool bridge[maxn];
pair<int,int>edge[maxn];
vector<int>tree[maxn];
void dfs(int u, int pa) {
    num[u]=low[u]=++timer;
    for(auto[v,i]:adj[u]) {
        if(v==pa) continue;
        if(!num[v]) {
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>num[u]) bridge[i]=true;
        }
        else low[u]=min(low[u],num[v]);
    }
}
void dfscomp(int u) {
    comp[u]=ncomp;
    for(auto[v,i]:adj[u]) {
        if(!comp[v] && !bridge[i]) dfscomp(v);
    }
}
void bfs(int s) {
    fill(d,d+maxn,INT_MAX/2);
    queue<int>q;
    q.push(s);
    d[s]=0;
    while(!q.empty()) {
        int u=q.front();q.pop();
        for(int v:tree[u]) {
            if(d[v]>d[u]+1) {
                d[v]=d[u]+1;
                q.push(v);
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> m;
    map<pair<int,int>,bool>mp;
    for(int i=1; i<=m; i++) {
        cin >> edge[i].fi >> edge[i].se;
        if(mp[{edge[i].fi,edge[i].se}]) continue;
        mp[{edge[i].fi,edge[i].se}]=true;
        mp[{edge[i].se,edge[i].fi}]=true;
        adj[edge[i].fi].eb(edge[i].se,i);
        adj[edge[i].se].eb(edge[i].fi,i);
    }
    for(int i=1; i<=n; i++) {
        if(!num[i]) dfs(i,0);
    }
    for(int i=1; i<=n; i++) {
        if(!comp[i]) {
            ++ncomp;
            dfscomp(i);
        }
    }
    for(int i=1; i<=m; i++) {
        int u=comp[edge[i].fi],v=comp[edge[i].se];
        tree[u].pb(v);
        tree[v].pb(u);
    }
    if(ncomp==1) {
        cout << 1 << " " << 2;
        return 0;
    }
    int k1,k2;
    bfs(1);
    int ma=0;
    for(int i=1; i<=ncomp; i++) {
        if(d[i]>ma) {
            ma=d[i];
            k1=i;
        }
    }
    ma=0;
    bfs(k1);
    for(int i=1; i<=ncomp; i++) {
        if(d[i]>ma) {
            ma=d[i];
            k2=i;
        }
    }
    int r1,r2;
    for(int i=1; i<=n; i++) {
        if(comp[i]==k1) r1=i;
        if(comp[i]==k2) r2=i;
    }
    cout << r1 << " " << r2;
}