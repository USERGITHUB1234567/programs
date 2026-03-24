#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n;
long long a[2000006],d[30],kq=0;
int main()
{
    freopen("div.inp", "r", stdin);
    freopen("div.out", "w", stdout);
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    if(n>=1) d[a[1]%29]++;
    for(int i=2; i<=n; i++) {
        kq+=d[a[i]%29];
        d[a[i-1]%29]++;

    }
    cout << kq;
    return 0;
}
