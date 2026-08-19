#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int maxn=100005,maxlog=20;
int a[maxn],st[maxn][maxlog],logv[maxn],n,m;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> m;
    for(int i=0; i<n; i++) cin >> a[i];
    logv[1]=0;
    for(int i=2; i<=n; i++) {
        logv[i]=logv[i>>1]+1;
    }
    for(int i=0; i<n; i++) st[i][0]=a[i];
    for(int j=1; j<maxlog; j++) {
        for(int i=0; i+(1<<j)<=n; i++) {
            st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
        }
    }
    while(m--) {
        int l,r;
        cin >> l >> r;
        l--;r--;
        int len=r-l+1,j=logv[len];
        int ans=min(st[l][j],st[r-(1<<j)+1][j]);
        cout << ans << "\n";
    }
}
