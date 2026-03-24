#include <bits/stdc++.h>
using namespace std;

int n, m, dist1[150509];
vector <int> a[150509], dist2[150509];

void dfs1(int u, int p)
{
    for(int i=0; i<a[u].size(); i++)
    {
        int v=a[u][i];
        if(v!=p)
        {
            dfs1(v, u);
            dist1[u] = max(dist1[u], dist1[v]+1);
        }
    }
}

void dfs2(int u, int p, int d)
{
    int ans=d, res=0;
    if(d>0) dist2[u].push_back(d);
    for(int v:a[u])
    {
        if(v==p) continue;
        int cur_d=dist1[v]+1;
        dist2[u].push_back(cur_d);
        if(cur_d>ans)
        {
            res = ans;
            ans = cur_d;
        }
        else if(cur_d>res) res=cur_d;
    }
    sort(dist2[u].begin(), dist2[u].end());
    for(auto v : a[u])
    {
        if(v==p) continue;
        if(dist1[v] + 1 == ans) dfs2(v, u, res + 1);
        else dfs2(v, u, ans + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n-1; i++){
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs1(1, 0);
    dfs2(1, 0, 0);
    for(int i=1; i<=m; i++)
    {
        int v, d;
        cin >> v >> d;
        auto it = upper_bound(dist2[v].begin(), dist2[v].end(), d);
        cout << dist2[v].end() - it << "\n";
    }
    return 0;
}
