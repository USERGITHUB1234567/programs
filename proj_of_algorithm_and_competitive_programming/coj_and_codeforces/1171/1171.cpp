#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) {
    while (b != 0) {
        ll t = b;
        b = a % b;
        a = t;
    }
    return a;
}

ll lcm(ll a, ll b) {
    return (a / gcd(a, b)) * b;
}

int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    ll lcm_nm = lcm(n + 1, m + 1);
    ll pv = k / lcm_nm;
    ll s = k / (n + 1) - pv;
    ll vn = k / (m + 1) - pv;
    ll hh = k - s - vn - pv;
    cout << hh << " " << pv << " " << vn << " " << s;
    return 0;
}
