#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long a[55][55], dp[55][55];
long long to(long long i, long long j, long long r, long long c)
{
    return dp[r][c]-dp[i][c]-dp[r][j]+dp[i][j];
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    long long d=0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cin >> a[i][j];
        }
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            dp[i][j]=a[i][j]+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
        }
    }
    for(int i=1;i<=n-1;i++) {
        for(int j=1;j<=n-1;j++)
        {
            map<long long, long long> mp;
            for(int r=0;r<=i-1;r++) {
                for(int c=0;c<=j-1;c++)
                {
                    long long ans=to(r,c,i,j);
                    mp[ans]++;
                }
            }
            for(int r=i+1;r<=n;r++) {
                for(int c=j+1;c<=n;c++)
                {
                    long long ans=to(i,j,r,c);
                    if(mp.find(ans)!=mp.end())
                        d+=mp[ans];
                }
            }
        }
    }
    for(int i=1;i<=n-1;i++) {
        for(int j=1;j<=n-1;j++)
        {
            map<long long, long long> mp;
            for(int c=0;c<=j-1;c++) {
                for(int r=i+1;r<=n;r++)
                {
                    long long ans=to(i,c,r,j);
                    mp[ans]++;
                }
            }
            for(int r=0;r<=i-1;r++) {
                for(int c=j+1;c<=n;c++)
                {
                    long long ans=to(r,j,i,c);
                    if(mp.find(ans)!=mp.end())
                        d+=mp[ans];
                }
            }
        }
    }
    cout << d;
    return 0;
}
