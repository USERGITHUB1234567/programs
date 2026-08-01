#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#define int long long
using namespace std;
int n,a[200005];
signed main()
{
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    int kq=0;
    for(int i=2; i<=n; i++) {
        if(a[i]<a[i-1]) {
            kq+=a[i-1]-a[i];
            a[i]=a[i-1];
        }
    }
    cout << kq;
}
