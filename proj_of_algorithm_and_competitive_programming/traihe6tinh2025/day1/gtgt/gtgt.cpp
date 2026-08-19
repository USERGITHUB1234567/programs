#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#define int long long
using namespace std;
const int maxn=21;
int a[maxn],b[maxn],fm,p1[maxn],p2[maxn],f[1<<maxn],pre[maxn],n;
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n;
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];
    for(int i=0; i<n; i++) {
        p1[a[i]]=i;
        p2[b[i]]=i;
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(i==j) continue;
            if(p1[j]<p1[i] && p2[j]<p2[i]) pre[i-1]|=(1<<(j-1));
        }
    }
    fm=1<<n;
    f[0]=1;
    for(int mask=0; mask<fm; mask++) {
        for(int i=0; i<n; i++) {
            if((mask&(1<<i))) continue;
            if((mask&pre[i])==pre[i]) f[mask|(1<<i)]+=f[mask];
        }
    }
    cout << f[fm-1];
}
