#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    freopen("col.inp", "r", stdin);
    freopen("col.out", "w", stdout);
    int n;
    cin >> n;
    long long t1=0,t2=0;
    long long a[n];
    for(int i=0; i<n; i++) cin >> a[i];
    sort(a,a+n);
    for(int i=0; i<n/2; i++) {
        t1+=a[i];
    }
    for(int i=n-n/2; i<n; i++) t2+=a[i];
    cout << t2-t1;
    return 0;
}
