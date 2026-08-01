#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long ll;
const ll maxn=21,inf=1e18;
ll c[maxn][maxn],n,k,f[1<<maxn],fm,ans=inf;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> k;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) cin >> c[i][j];
    }
    for(int i=0; i<(1<<n); i++) f[i]=inf;
    f[(1<<n)-1]=0;
    fm=1<<n;
    for(int k=0; k<n; k++) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                c[i][j]=min(c[i][k]+c[k][j],c[i][j]);
            }
        }
    }
    for(ll mask=fm; mask>=0; mask--) {
        if(__builtin_popcount(mask)<=k) {
            continue;
        }
        for(int i=0; i<n; i++) {
            if(!(mask&(1<<i))) continue;
            for(int j=0; j<n; j++) {
                if(!(mask&(1<<j)) || i==j) continue;
                int nm=mask&~(1<<i);
                f[nm]=min(f[nm],f[mask]+c[i][j]);
            }
        }
    }
    //cout << f[fm-1];
    for(int mask=0; mask<fm; mask++) {
        if(__builtin_popcount(mask)==k) ans=min(ans,f[mask]);
    }
    cout << ans;
}
