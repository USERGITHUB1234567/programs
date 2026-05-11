#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int a[200005],f[200005];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    freopen("lrquest.inp", "r", stdin);
    freopen("lrquest.out", "w", stdout);
    int n,q;
    cin >> n >> q;
    fill(f,f+200005,0);
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++) f[i]=f[i-1]+a[i];
    while(q--) {
        int l,r;
        cin >> l >> r;
        cout << f[r]-f[l-1] << "\n";
    }
    return 0;
}
