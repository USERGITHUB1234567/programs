#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    freopen("rgc.inp", "r", stdin);
    freopen("rgc.out", "w", stdout);
    ll n;
    cin >> n;
    ll a1=0,a2;
    ll t=sqrt(n);
    if(t*t==n) {
        cout << t << " " << 1;
        return 0;
    }
    for(ll i=2; i*i<=n; i++) {
        if(n%i==0) {
            ll t=n/i;
            ll t2=sqrt(t);
            if(t2*t2==t) {
                a1=t2;
                a2=i;
                break;
            }
        }
    }
    if(a1==0) cout << 1 << " " << n;
    else cout << a1 << " " << a2;
}
