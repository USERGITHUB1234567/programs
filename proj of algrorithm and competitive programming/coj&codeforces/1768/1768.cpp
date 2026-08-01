#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n;
    cin >> n;
    long long a[n];
    long long kq=1e18;
    for(int i=0; i<n; i++) {
        long long x;
        cin >> x;
        kq=min(kq,x);
    }
    cout << kq*(n-1);
    return 0;
}
