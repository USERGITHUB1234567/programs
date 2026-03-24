#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int maxn=100005;
int n,m,d,mi=1e9;
vector<int>kq;
vector<pair<int,int>>adj[maxn];
struct nod
{
    int v,m;
    vector<int>p;
};
void bfs(int s)
{
    queue<nod>q;
    vector<int>v;
    q.push({s,0,v});
    while(!q.empty()) {
        int u=q.front().v,m=q.front().m;
        vector<int>ve=q.front().p;
        q.pop();
        if(u==n) {
            if(m<mi) {
                kq=v;
                continue;
            }
        }
        if(v.size()==d) continue;
        for(auto [v,w]:adj[u]) {
            int ma=m;
            if(w>m) ma=w;
            ve.push_back(v);
            q.push({v,ma,ve});
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> m >> d;
    for(int i=1; i<=m; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        if(u>v) adj[u].push_back({v,w});
        else adj[v].push_back({u,w});
    }
    bfs(1);
    if(kq.size()==0) cout << -1;
    else cout << kq.size() << "\n";
    for(int i:kq) cout << i << " ";
}
