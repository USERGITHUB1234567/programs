#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long ll;
const ll maxn=11,maxm=102,mod=1000000007;
ll n,m,fm,f[1<<maxn],g[1<<maxn];
void dfs(int r, int mask, int nxt, ll ways, int n, ll g[])
{
    if(r==n) {
        g[nxt]=(g[nxt]+ways)%mod;
        return;
    }
    if(mask&(1<<r)) {
        dfs(r+1,mask,nxt,ways,n,g);
    }
    else {
        dfs(r+1,mask,nxt|(1<<r),ways,n,g);
        if(r+1<n && !(mask&(1<<(r+1)))) {
            dfs(r+2,mask,nxt,ways,n,g);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> m;
    fm=1<<n;
    f[0]=1;
    for(int c=0; c<m; c++) {
        for(int i=0; i<fm; i++) g[i]=0;
        for(int mask=0; mask<fm; mask++) {
            if(f[mask]!=0) {
                dfs(0,mask,0,f[mask],n,g);
            }
        }
        for(int mask=0; mask<fm; mask++) {
            f[mask]=g[mask];
        }
    }
    cout << f[0]%mod;
}
