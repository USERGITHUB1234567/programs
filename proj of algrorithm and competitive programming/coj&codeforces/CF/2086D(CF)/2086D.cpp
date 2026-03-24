#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;

// fast exponentiation mod mod
long long modexp(long long base, long long exp, long long mod = MOD) {
    long long res = 1 % mod;
    base %= mod;
    while(exp > 0) {
        if(exp & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    // Precompute factorials and inverse factorials up to MAXN.
    const int MAXN = 500000;
    vector<long long> fact(MAXN+1), invfact(MAXN+1);
    fact[0] = 1;
    for (int i = 1; i <= MAXN; i++){
        fact[i] = (fact[i-1] * i) % MOD;
    }
    invfact[MAXN] = modexp(fact[MAXN], MOD-2, MOD);
    for (int i = MAXN; i > 0; i--){
        invfact[i-1] = (invfact[i] * i) % MOD;
    }

    while(t--){
        vector<int> cnt(26);
        int total = 0;
        for (int i = 0; i < 26; i++){
            cin >> cnt[i];
            total += cnt[i];
        }

        // Determine counts for even and odd positions.
        int evenCount, oddCount;
        if(total % 2 == 0){
            evenCount = total / 2;
            oddCount = total / 2;
        } else {
            // Using 0-indexing: even positions = (n+1)/2
            evenCount = (total + 1) / 2;
            oddCount = total - evenCount;
        }

        // Only consider letters with positive count.
        vector<int> pos;
        for (int i = 0; i < 26; i++){
            if(cnt[i] > 0) pos.push_back(cnt[i]);
        }

        // DP: count number of ways to choose a subset of letters (with c>0)
        // so that the sum of their counts equals evenCount.
        vector<int> dp(evenCount + 1, 0);
        dp[0] = 1;
        for (int a : pos) {
            for (int s = evenCount; s >= a; s--){
                dp[s] = (dp[s] + dp[s - a]) % MOD;
            }
        }

        int waysSubset = dp[evenCount]; // number of valid assignments.

        // If there is no valid assignment, the answer is 0.
        if(waysSubset == 0){
            cout << 0 << "\n";
            continue;
        }

        // For any fixed valid assignment, the number of arrangements is:
        // (evenCount! / (product_{x in S} c_x!)) * (oddCount! / (product_{x not in S} c_x!))
        // = (evenCount! * oddCount!) / (product_{x with c_x>0} c_x!)
        long long arrangements = (fact[evenCount] * fact[oddCount]) % MOD;
        for (int a : pos){
            arrangements = (arrangements * invfact[a]) % MOD;
        }

        long long ans = ((long long)waysSubset * arrangements) % MOD;
        cout << ans % MOD << "\n";
    }

    return 0;
}
