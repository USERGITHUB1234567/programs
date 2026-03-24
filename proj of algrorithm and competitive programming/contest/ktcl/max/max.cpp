#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int a[3000][3000];
int dp[3000][3000];
int main()
{
    freopen("max.inp", "r", stdin);
    freopen("max.out", "w", stdout);
    int m,n;
    cin >> m >> n;
    for(int i=1; i<=m; i++) for(int j=1; j<=n; j++) cin >> a[i][j];
    memset(dp,0,sizeof(dp));
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            if(j==1) dp[i-1][j-1]=-1e9;
            if(j==n) dp[i-1][j+1]=-1e9;
            dp[i][j]=max({dp[i-1][j],dp[i-1][j-1],dp[i-1][j+1]})+a[i][j];
        }
    }
    int kq=-1e9;
    for(int i=1; i<=n; i++) kq=max(kq,dp[m][i]);
    cout << kq;
    /*for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) cout << dp[i][j] << " ";
        cout << "\n";
    }*/
    return 0;
}
