#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        long long a[n],b[n-1];
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n-1; i++) cin >> b[i];
        sort(a,a+n);
        sort(b,b+n-1);
        long long a1=abs(a[0]-b[0]),an=abs(a[n-1]-b[n-2]);
        if(n==3) {
            if(a[2]-b[1]==a[0]-b[0]) {
                cout << abs(a[2]-b[1]);
                continue;
            }
            if(a[1]-b[0]==a[2]-b[1]) {
                cout << abs(a[1]-b[0]);
                continue;
            }
            else {
                cout << abs(a[0]-b[0]);
                continue;
            }
            continue;
        }
        if(a1==an) {
            cout << a1 << "\n";
            continue;
        }
        else {
            long long a1p=abs(a[1]-b[0]),anp=abs(a[n-2]-b[n-2]),b1p=abs(a[1]-b[1]),bnp=abs(a[n-2]-b[n-3]);
            long long k1=1e18,k2=1e18,k3=1e18,k4=1e18;
            if(a1p==anp and b1p==bnp or n==2) {
                cout << min(a1p,b1p) << "\n";
                continue;
            }
            if(a1p==anp) {
                k1=a1p;
            }
            if(b1p==bnp) {
                k2=a1p;
            }
            if(b1p==anp) {
                k3=b1p;
            }
            if(a1p==bnp) {
                k4=a1p;
            }
            cout << min({k1,k2,k3,k4}) << "\n";
        }
    }
}
