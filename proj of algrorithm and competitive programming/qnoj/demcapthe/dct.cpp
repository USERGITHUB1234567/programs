#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#define int long long
using namespace std;
int n,a[100005];
signed main()
{
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    int kq=0;
    for (int i=1; i<n; i++) {
        kq+=a[i]/2;
        if (a[i]%2==1 && a[i+1]>0) {
            kq++;
            a[i+1]--;
        }
    }
    kq+=a[n]/2;
    cout << kq;
}
