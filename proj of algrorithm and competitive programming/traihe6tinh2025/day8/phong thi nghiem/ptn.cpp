#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    ll n, x;
    cin >> n >> x;
    ll ans = 0;
    for (ll a = 1; a <= n; a++) {
        if (x != 0 && a == x) continue;
        for (ll c = 1; c < a; c++) {
            ll diff = a - c;
            ll d_max = (n-1) / diff;
            for (ll d = 1; d <= d_max; d++) {
                ll t = n + c*d;
                if (t % a) continue;
                ll b = t / a;
                if (b <= d) continue;
                if (x != 0 && b == x) continue;
                ans++;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
