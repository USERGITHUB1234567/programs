#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
const int maxn=100005,inf=INT_MAX;
int n,m,k,a[maxn],b[maxn],d[2][maxn];
vector<int>adj[maxn];
bool vis[maxn],reach[maxn];
void dijkstra(int s, int t)
{
    for(int i=0; i<=n; i++) d[t][i]=inf;
    for(int i=1; i<=n; i++) vis[i]=false;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,s});
    d[t][s]=0;
    vis[s]=true;
    while(!pq.empty()) {
        auto[cd,u]=pq.top();
        pq.pop();
        for(int v:adj[u]) {
            if(!vis[v]) {
                vis[v]=true;
                d[t][v]=d[t][u]+1;
                pq.push({d[t][v],v});
                //cout << d[t][v] << "\n";
            }
        }
    }
}
void sub1()
{
    dijkstra(1,0);
    for(int i=1; i<=n; i++) cout << d[0][i] << " ";
}
/*void sub2()
{
    int s;
    for(int i=1; i<=n; i++) {
        if(b[i]!=-1) {
            s=i;
            break;
        }
    }
    dij2(1);
    vector<pair<int,int>>ans;
    for(int i=1; i<=n; i++) {
        if(a[i]!=-1) {
            ans.push_back({i,d2[i]});
        }
    }
    dij2(s);
    for(int i=1; i<=n; i++) {
        if(a[i]==-1) {
            int t=d2[i];
            dij2(1);
            ans.push_back({i,d2[i]+t});
        }
    }
    sort(ans.begin(),ans.end());
    for(int i=0; i<ans.size(); i++) cout << ans[i].second << ' ';
}*/
void subrua()
{
    vector<int>lock,key;
    for(int i=1; i<=n; i++) {
        if(a[i]!=-1) lock.push_back(i);
        if(b[i]!=-1) key.push_back(i);
    }
    dijkstra(1,0);
    vector<pair<int,int>>ans;
    for(int i=1; i<=n; i++) {
        if(a[i]==-1) ans.push_back({i,d[0][i]});
    }
    for(int i=0; i<lock.size(); i++) {
        int t=lock[i],s;
        for(int j=0; j<key.size(); j++) {
            if(b[key[j]]==a[t]) {
                s=key[j];
            }
        }
        dijkstra(s,1);
        //for(int j=1; j<=n; j++) cout << d[1][j] << "\n";
        ans.push_back({t,d[0][s]+d[1][t]});
        //cout << d[0][s]+d[1][lock[i]] << " ";
    }
    sort(ans.begin(),ans.end());
    for(auto i:ans) {
        cout << i.second << " ";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    freopen("spymove.inp", "r", stdin);
    freopen("spymove.out", "w", stdout);
    cin >> n >> m >> k;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++) cin >> b[i];
    for(int i=1; i<=m; i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(k==0) {
        sub1();
        return 0;
    }
    subrua();

}
/*
4 3 1
-1 -1 1 -1
-1 -1 -1 1
1 2
2 3
1 4
*/
