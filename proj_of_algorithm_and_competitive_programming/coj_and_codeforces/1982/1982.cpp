// sea_algae_population.cpp
// Calculates the number of brown algae individuals after k days
// Growth rule:
// Day 0: n individuals at level 1.
// Each day, each individual at level i produces i new individuals at level 1 (effective next day),
// and the original individuals advance to level i+1.
// We maintain:
//   T = total number of individuals
//   W = weighted sum of levels (sum i * count[i])
// Recurrence per day:
//   T' = T + W
//   W' = 2*W + T
// Answer: T after k days modulo 1e9+7

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, k;
    cin >> n >> k;
    const ll MOD = 1000000007;

    ll T = n % MOD;       // total individuals at current day
    ll W = (n % MOD);     // weighted sum of levels at current day (all at level 1)

    for (ll day = 1; day <= k; ++day) {
        ll newT = (T + W) % MOD;
        ll newW = (W * 2 % MOD + T) % MOD;
        T = newT;
        W = newW;
    }

    cout << T << "\n";
    return 0;
}
