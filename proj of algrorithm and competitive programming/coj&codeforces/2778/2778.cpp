#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long dp[100007],up[100007],down[100007];
const long long ad=1e9+7;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n,k;
    cin >> n >> k;
    bool a[3][n+1];
    dp[0]=1;
    up[0]=0;
    down[0]=0;
    memset(a,false,sizeof(a));
    for(int i=0; i<k; i++) {
        int x,t;
        cin >> x >> t;
        a[x][t]=true;
    }
    for(int i=1; i<=n; i++) {
        if(a[1][i] and !a[2][i]) {
            dp[i]=(dp[i-1]+(a[2][i-1]? 0 : down[i-1]))%ad;
            down[i]=dp[i-1]%ad;
            up[i]=0%ad;
        }
        else if(!a[1][i] and a[2][i]) {
            dp[i]=(dp[i-1]+(a[1][i-1]? 0 : up[i-1]))%ad;
            down[i]=0%ad;
            up[i]=dp[i-1]%ad;
        }
        else if(a[1][i] and a[2][i]) {
            dp[i]=dp[i-1]%ad;
            up[i]=0;
            down[i]=0;
        }
        else {
            dp[i]=(dp[i-1]*2+(a[1][i-1]? 0 : up[i-1]) + (a[2][i-1]? 0 : down[i-1]) + (i>1 and !a[1][i-1] and !a[2][i-1]? dp[i-2] : 0))%ad;
            up[i]=dp[i-1]+(a[2][i-1]? 0 : down[i-1])%ad;
            down[i]=dp[i-1]+(a[1][i-1]? 0 : up[i-1])%ad;
        }
    }
    cout << dp[n];
}
