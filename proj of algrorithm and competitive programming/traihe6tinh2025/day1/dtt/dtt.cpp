#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#define int long long
using namespace std;
const int maxn=1003,maxm=16,inf=1e18;
int n,m,f[1<<maxm][maxm],cost[maxm][maxm],cnt[maxm];
string s[maxm];
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> m;
    for(int i=0; i<(1<<maxm); i++) {
        for(int j=0; j<maxm; j++) f[i][j]=inf;
    }
    for(int i=0; i<m; i++) cin >> s[i];
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) if(s[i][j]=='1') cnt[i]++;
    }
    for(int i=0; i<m; i++) {
        for(int j=0; j<m; j++) {
            if (i==j) continue;
            cost[i][j]=0;
            for (int p=0; p<n; p++) {
                if (s[i][p]!=s[j][p])
                    cost[i][j]++;
            }
        }
    }
    for(int i=0; i<m; i++) f[1<<i][i]=cnt[i];
    for(int mask=0; mask<(1<<m); mask++) {
        for(int i=0; i<m; i++) {
            if(!(mask&(1<<i))) continue;
            for(int j=0; j<m; j++) {
                if(mask&(1<<j)) continue;
                int nm=mask|(1<<j);
                f[nm][j]=min(f[nm][j],f[mask][i]+cost[i][j]);
            }
        }
    }
    int ans=1e18;
    for(int i=0; i<m; i++) {
        ans=min(ans,f[(1<<m)-1][i]);
    }
    cout << ans;
}
