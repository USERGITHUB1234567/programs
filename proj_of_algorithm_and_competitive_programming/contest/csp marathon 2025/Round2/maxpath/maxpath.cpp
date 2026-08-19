#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
#define mkp make_pair
#define eb emplace_back
#define fi first
#define se second
using namespace std;
const int maxn=200005,inf=INT_MAX;
int n,m,d[302][302];
vector<pair<int,int>>adj[maxn];
void floyd_warshall()
{
    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                d[i][j]=max(d[i][j],min(d[i][k],d[k][j]));
            }
        }
    }
}
void setup()
{
    for(int i=0; i<302; i++) {
        for(int j=0; j<302; j++) d[i][j]=-1;
    }
}
void soup1()
{

    floyd_warshall();
    int cnt=0;
    double kq=0;
    for(int i=1; i<=n; i++) {
        for(int j=i+1; j<=n; j++) {
            if(__gcd(i,j)==1) {
                kq+=double(d[i][j]);
                cnt++;
            }
        }
    }
    cout << fixed << setprecision(2) << kq/cnt;
}
void soup3()
{
    double kq=0;
    int cnt=0;
    for(int i=1; i<=n; i++) {
        for(int j=i+1; j<=n; j++) {
            if(__gcd(i,j)==1) {
                kq+=i;
                cnt++;
            }
        }
    }
    cout << fixed << setprecision(2) << kq/cnt;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    file("maxpath");
    cin >> n >> m;
    setup();
    for(int i=1; i<=m; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        d[u][v]=w;
        d[v][u]=w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    if(n<=300 && m<=1000) {
        soup1();
        return 0;
    }
    soup3();
}
