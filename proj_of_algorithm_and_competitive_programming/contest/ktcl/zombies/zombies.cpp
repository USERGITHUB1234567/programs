#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
vector<int>adj[100005];
int n,m;
int dfs(int i, int f, int d) {
    int kq=d;
    for (int u:adj[i]) {
        if (u!=f) {
            kq=max(kq,dfs(u,i,d+1));
        }
    }
    return kq;
}
void sub1()
{
    int kq=0;
    for(int i=1; i<=n; i++) {
        if(adj[i].size()==1) {
            kq=max(kq,dfs(i,i,0));
            //break;
        }
    }
    cout << kq;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    freopen("zombies.inp", "r", stdin);
    freopen("zombies.out", "w", stdout);
    cin >> n >> m;
    for(int i=1; i<=m; i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    sub1();
    return 0;
}
