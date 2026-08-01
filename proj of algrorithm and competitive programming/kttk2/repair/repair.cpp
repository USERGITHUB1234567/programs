#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
vector<int>adj[100005];
int n,m;
long long a[100005],kq=0;
bool vis[100005];
vector<int>mi;
void bfs(int u)
{
    queue<int>q;
    q.push(u);
    vis[u]=true;
    long long t=a[u];
    while(!q.empty()) {
        int v=q.front();
        q.pop();
        for(int i:adj[v]) {
            if(vis[i]) continue;
            t=min(t,a[i]);
            q.push(i);
            vis[i]=true;
        }

    }
    mi.push_back(t);
}
int main()
{
    freopen("repair.inp", "r", stdin);
    freopen("repair.out" ,"w", stdout);
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
    }
    for(int i=1; i<=m; i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        //st.insert(a[u]);
        //st.insert(a[v]);
    }
    /*vector<int>v;
    for(int i=1; i<=n; i++) {
        if(adj[i].size()==0) {
            v.push_back(a[i]);
        }
    }
    for(int i:v) {
        kq+=*st.begin();
        st.insert(i);
    }*/
    for(int i=1; i<=n; i++) {
        if(!vis[i]) {
            bfs(i);
        }
    }
    kq=*min_element(mi.begin(),mi.end())*(mi.size()-1);
    cout << kq;
}
