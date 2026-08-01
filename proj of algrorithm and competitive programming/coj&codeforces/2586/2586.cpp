#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define pl pair <ll, ll>
#define pll pair <pl, ll>
#define pb push_back
#define fi first
#define se second
#define fti(i, x, y) for(ll i = (x), _y = (y); i <= _y; ++ i)
#define ftd(i, x, y) for(ll i = (x), _y = (y); i >= _y; -- i)
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const ll inf=1e18;
const ll mx=1e6+1;
ll dp[mx][26],T;
ll val[26]= {1,5,10,50,100,500,1000,5000,10000,50000,100000,500000,1000000,5000000,10000000,50000000,100000000,500000000,1000000000,5000000000,10000000000,50000000000,100000000000,500000000000,1000000000000,5000000000000};
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>T;
    while(T--)
    {
        string s;
        cin>>s;
        ll n=s.size();
        fti(i,0,n)
        fti(j,0,25)
        dp[i][j]=-inf;
        dp[n][0]=0;
        ftd(i,n-1,0)
        if(s[i]!='?')
        {
            ll k=s[i]-'A',tmp=-inf;
            fti(j,0,k)tmp=max(tmp,dp[i+1][j]);
            dp[i][k]=tmp+val[k];
            fti(j,k+1,25)
            dp[i][j]=dp[i+1][j]-val[k];
        }
        else
        {
            ll tmp=-inf;
            fti(j,0,25)
            {
                tmp=max(tmp,dp[i+1][j]);
                dp[i][j]=tmp+val[j];
            }
        }
        ll j=max_element(dp[0],dp[0]+26)-dp[0];
        cout<<dp[0][j]<<"\n";
        fti(i,0,n-1)
        {
            if(s[i]=='?')
                s[i]='A'+j;
            j=max_element(dp[i+1],dp[i+1]+j+1)-dp[i+1];
        }
        cout<<s<<"\n";
    }
    return 0;
}
