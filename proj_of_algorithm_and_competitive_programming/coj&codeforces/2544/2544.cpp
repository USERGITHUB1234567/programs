#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long dp1[1505][1505],a[1505][1505],dp2[1505][1505];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long m,n;
    cin >> m >> n;
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) cin >> a[i][j];
    }
    memset(dp1,0,sizeof(dp1));
    memset(dp2,0,sizeof(dp2));
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            dp1[i][j]=max(dp1[i][j-1],dp1[i-1][j])+a[i][j];
        }
    }
    for(int i=m; i>=1; i--)
        for(int j=n; j>=1; j--)
            dp2[i][j]=max(dp2[i][j+1],dp2[i+1][j])+a[i][j];
    long long ans=1e18;
    for(int k=3; k<=m+n-1; k++) {
        long long s1=-1e18,s2=-1e18;
        for(int i=1; i<=m and i<k; i++) {
            int j=k-i;
            if(j>n) continue;
            long long s=dp1[i][j]+dp2[i][j]-a[i][j];
            if(s>=s1) {
                s2=s1;
                s1=s;
            }
            else if(s>s2) {
                s2=s;
            }
        }
        ans=min(ans,s2);
    }
    cout << ans;
}
