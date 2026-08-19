#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define file(name) freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout);
#define fi first
#define se second
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
const int maxn=300005;
int n,m,q,k[maxn],num[maxn],low[maxn],ncomp,comp[maxn],query[maxn],timer=0;
vector<pair<int,int>>adj[maxn];
int stor[maxn];
bool bridge[maxn];
void dfs(int u, int p)
{
    num[u]=low[u]=++timer;
    for(auto[v,i]:adj[u]) {
        if(v==p) continue;
        if(!num[v]) {
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(num[v]==low[v]) bridge[i]=true;
        }
        else {
            low[u]=min(low[u],num[v]);
        }
    }
}
void dfscomp(int u)
{
    comp[u]=ncomp;
    for(auto[v,i]:adj[u]) {
        if(!comp[v] && !bridge[i]) dfscomp(v);
    }
}
bool vis[maxn];
void bfscheck(int s, int ta, int pa, bool &kq)
{
    queue<int>q;
    q.push(s);
    while(!q.empty()) {
        int u=q.front();
        q.pop();
        //cout << u << "\n";
        vis[u]=true;
        if(u==ta) {
            kq=true;
            return;
        }
        for(auto[v,i]:adj[u]) {
            if(vis[v]) continue;
            q.push(v);
        }
    }
}
void soup1()
{
    map<pair<int,int>,bool>mp;
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=n; ++j) {
            for(int t=1; t<=n; t++) vis[t]=false;
            bool kt1=false,kt2=false;
            bfscheck(i,j,0,kt1);
            for(int t=1; t<=n; t++) vis[t]=false;
            bfscheck(j,i,0,kt2);
            if(kt1 && kt2) {
                mp[{i,j}]=true;
                mp[{j,i}]=true;
            }
            //cout << kt1 << " " << kt2 << " " << i << " " << j << "\n";
        }
    }
    int fm=1<<n;
    for(int i=1; i<=q; ++i) {
        int k=query[i];
        int res=0;
        for(int mask=0; mask<fm; ++mask) {
            int cnt=__builtin_popcount(mask),kt=0;
            for(int j=0; j<n; ++j) {
                if(!(mask&(1<<j))) continue;
                for(int t=j+1; t<n; ++t) {
                    if(!(mask&(1<<t))) continue;
                    if(!mp[{j+1,t+1}] || !mp[{t+1,j+1}]) kt++;
                    if(kt>k) break;
                }
                if(kt>k) break;
            }
            if(kt<=k) res=max(res,cnt);
        }
        cout << res << "\n";
    }
    //cout << mp[{1,4}];
    /*for(auto x:mp) {
        cout << x.fi.fi << " " << x.fi.se << " " << x.se << "\n";
    }*/
    /*bool kt=false;
    bfscheck(2,1,0,kt);
    cout << kt;*/
}
void soupfull()
{

    for(int i=1; i<=n; ++i) {
        if(!num[i]) dfs(i,0);
    }
    for(int i=1; i<=n; ++i) {
        if(!comp[i]) {
            ++ncomp;
            dfscomp(i);
        }
    }
    map<int,int>mp;
    for(int i=1; i<=n; i++) {
        mp[comp[i]]++;
    }
    int p=0;
    for(auto x:mp) {
        //stor.pb(x.se);
        stor[++p]=x.se;
        //cout << stor[p] << " ";
    }
    for(int i=1; i<=m; i++) cout << bridge[i] << " ";
    for(int i=1; i<=q; ++i) {
        int k=query[i];
        int res=0,pre=0;
        for(int j=1; j<=ncomp; ++j) {

        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    file("cost")
    cin >> n >> m;
    for(int i=1; i<=m; ++i) {
        int u,v;
        cin >> u >> v;
        adj[u].eb(v,i);
        //adj[v].eb(u,i);
    }
    cin >> q;
    for(int i=1; i<=q; ++i) cin >> query[i];
    //soupfull();
    soup1();
}
