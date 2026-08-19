#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n,t,k,a[500005];
int main()
{
    cin >> n >> t;
    for(int i=1; i<=n; i++) cin >> a[i];
    cin >> k;
    int mi=a[1],ma=a[n];
    if(a[k]-mi<t) {
        cout << ma-mi << "\n";
        for(int i=1; i<=n; i++) cout << i << " ";
        return 0;
    }
    if(ma-a[k]<t) {
        cout << ma-mi << "\n";
        for(int i=n; i>=1; i--) cout << i << " ";
        return 0;
    }
    if(k==1) {
        cout << ma-mi << "\n";
        for(int i=1; i<=n; i++) cout << i << " ";
        return 0;
    }
    if(k==n) {
        cout << ma-mi;
        for(int i=1; i<=n; i++) cout << i << " ";
        return 0;
    }
    if(ma-a[k]<a[k]-mi) {
        cout << ma-a[k]+ma-mi << "\n";
        for(int i=k; i<=n; i++) cout << i << " ";
        for(int i=k-1; i>=1; i--) cout << i << " ";
    }
    else {
        cout << a[k]-mi+ma-mi << "\n";
        for(int i=k; i>=1; i--) cout << i << " ";
        for(int i=k+1; i<=n; i++) cout << i << " ";

    }
}
