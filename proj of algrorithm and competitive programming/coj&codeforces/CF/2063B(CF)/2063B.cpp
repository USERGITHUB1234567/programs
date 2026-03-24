#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        long long n,l,r,kq=0;
        cin >> n >> l >> r;
        long long a[n];
        for(int i=0; i<n; i++) cin >> a[i];
        sort(a,a+n);
        int m=r-l+1;
        for(int i=0; i<m; i++) kq+=a[i];
        cout << kq << "\n";
    }
}
