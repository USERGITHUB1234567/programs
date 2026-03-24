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
const int maxn=1505,maxm=20;
const ll inf=LLONG_MAX;
long long n,m,q,f[maxm],d[maxn][maxn],di[maxn][maxn];
void floyd_warshall()
{
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) di[i][j]=d[i][j];
    }
    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                di[i][j]=min(di[i][j],di[i][k]+di[k][j]);
            }
        }
    }
}
void soup1()
{
    floyd_warshall();
    while(q--) {
        int u,v;
        cin >> u >> v;
        cout << min({di[u][f[1]]+di[f[1]][v],di[u][v]+di[v][f[1]]+di[f[1]][v]}) << " ";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    file("luoidien")
    cin >> n >> m >> q;
    for(int i=1; i<=m; i++) cin >> f[i];
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++) cin >> d[i][j];
    if(m==1) soup1();
}
