#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long n,m,a[1003][1003],f[1003][1003];
int main()
{
    freopen("table.inp", "r", stdin);
    freopen("table.out", "w", stdout);
    cin >> n >> m;
    for(int i=0; i<1003; i++)
        for(int j=0; j<1003; j++) f[i][j]=1e10;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++) cin >> a[i][j];
    f[1][1]=a[1][1];
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(i==1 and j==1) continue;
            int v1=f[i-1][j],v2=f[i][j-1];
            f[i][j]=min(v1,v2);
            if(f[i][j]<=1e10) f[i][j]+=a[i][j];
        }
    }
    cout << f[n][m];
}
