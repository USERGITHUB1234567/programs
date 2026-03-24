#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#define int long long
using namespace std;
const int maxn=22,inf=1e18;
int n,a[maxn][maxn],fm,f[1<<maxn+1];
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n;
    fm=1<<n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) cin >> a[i][j];
    }
    f[0]=0;
    for(int mask=0; mask<fm; mask++) {
        int p=__builtin_popcount(mask);
        for(int pe=0; pe<n; pe++) {
            if(!(mask&(1<<pe))) {
                int nm=mask|(1<<pe);
                f[nm]=max(f[nm],f[mask]+a[pe][p]);
            }
        }
    }
    cout << f[fm-1];
}
