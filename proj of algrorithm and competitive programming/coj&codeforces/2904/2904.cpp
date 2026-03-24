#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const long long MOD = 1e9 + 7;
const long long PHI_MOD = MOD - 1;

long long modularExponentiation(long long a, long long b, long long m) {
    long long result = 1;
    a = a % m;
    while (b > 0) {
        if (b % 2 == 1) {
            result = (result * a) % m;
        }
        b /= 2;
        a = (a * a) % m;
    }
    return result;
}
long long powerTowerMod(long long a, long long b, long long c) {
    long long exponent = modularExponentiation(b, c, PHI_MOD);
    return modularExponentiation(a, exponent, MOD);
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long t;
    cin >> t;
    while(t--) {
        long long a, b, c;
        cin >> a >> b >> c;
        cout << powerTowerMod(a, b, c) << "\n";
    }
    return 0;
}
