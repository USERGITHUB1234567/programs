#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int mh[200005],lr[200005],f[200005];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n,k,q,m=0;
    cin >> n >> k >> q;
    for(int i=1; i<=n; i++) {
        int l,r;
        cin >> l >> r;
        mh[l]=1;
        mh[r+1]=-1;
        m=max(m,r);
    }
    int t=0;
    for(int i=0; i<=m; i++) {
        t+=mh[i];
        lr[i]+=t;
    }
    for(int i=1; i<=200001; i++) {
        if(lr[i]>=k) f[i]=f[i-1]+1;
        else f[i]=f[i-1];
    }
    for(int i=1; i<=q; i++) {
        int a,b;
        cin >> a >> b;
        cout << (f[b]-f[a-1]<=0?0:f[b]-f[a-1]) << "\n";
    }
}
