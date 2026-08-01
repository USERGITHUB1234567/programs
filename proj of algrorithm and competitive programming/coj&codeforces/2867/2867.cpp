#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n,q;
    cin >> n >> q;
    int a[n+1],b[n+1],c[n+1];
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    for(int i=1; i<=n; i++) {
        int x;
        cin >> x;
        a[i]=a[i-1];
        b[i]=b[i-1];
        c[i]=c[i-1];
        if(x==1) a[i]++;
        else if(x==2) b[i]++;
        else c[i]++;
    }
    for(int i=1; i<=q; i++) {
        int l,r;
        cin >> l >> r;
        cout << a[r]-a[l-1] << " " << b[r]-b[l-1] << " " << c[r]-c[l-1] << "\n";
    }
}
