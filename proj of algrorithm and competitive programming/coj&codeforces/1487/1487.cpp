#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#define file(name) freopen(name".inp","r",stdin); freopen(name".out","w",stdout)
using namespace std;

int n, m, logn, d[2][100005], p[2][100005][18], di[200005];
vector<int> a[100005];

void dfs1(int u, int f)
{
    for(int v: a[u])
    {
        if(v!=f)
        {
            di[v]=di[u]+1;
            dfs1(v,u);
        }
    }
}

void dfs(int i, int u, int f)
{
    for(auto v: a[u])
    {
        if(v!=f)
        {
            d[i][v]=d[i][u]+1;
            p[i][v][0]=u;
            dfs(i,v,u);
        }
    }
}

int anc(int i, int u, int l)
{
    for(int j=0;j<=logn;j++)
        if(((l>>j)&1)==1)
            u=p[i][u][j];
    return u;
}

int lca(int i, int u, int v)
{
    if(d[i][u]<d[i][v])swap(u,v);
    for(int j=logn;j>=0;j--)
        if(d[i][p[i][u][j]]>=d[i][v])u=p[i][u][j];
    if(u==v)return u;
    for(int j=logn;j>=0;j--)
        if(p[i][u][j]!=p[i][v][j])
        {
            u=p[i][u][j];
            v=p[i][v][j];
        }
    return p[i][u][0];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //file("1487");
    cin >>  n >> m;
    for(int i=1;i<=n-1;i++)
    {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    int root1, root2;
    dfs1(1,0);
    root1=max_element(di+1,di+n+1)-di;
    dfs1(root1,0);
    root2=max_element(di+1,di+n+1)-di;
    dfs(0,root1,0);
    dfs(1,root2,0);
    for(logn=1;(1<<logn)<=n;logn++);
    logn--;
    for(int k=0;k<=1;k++)
        for(int j=1;j<=logn;j++)
            for(int i=1;i<=n;i++)
                p[k][i][j]=p[k][p[k][i][j-1]][j-1];
    for(int i=1;i<=m;i++)
    {
        int u, l;
        cin >> u >> l;
        if(d[0][u]>=l) cout << anc(0,u,l) << "\n";
        else
            if(d[1][u]>=l) cout << anc(1,u,l) << "\n";
            else cout << "0\n";
    }
    return 0;
}
