#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        long long n;
        cin >> n;
        long long a[n];
        for(int i=0; i<n; i++) cin >> a[i];
        int p=min_element(a,a+n)-a;
        long long g=0;
        for(int i=0; i<n; i++) {
            if(i!=p && a[i]%a[p]==0) {
                g=__gcd(g,a[i]);
            }
        }
        cout << (g==a[p]?"YES\n":"NO\n");
    }
}
