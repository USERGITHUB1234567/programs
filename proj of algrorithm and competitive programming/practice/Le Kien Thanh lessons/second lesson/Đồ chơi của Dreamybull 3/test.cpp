#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n;
vector<ll> primes;
vector<int> exps;
vector<ll> divisors; // all divisors >= 2
vector<ll> answers;

void gen_divisors(int idx, ll cur) {
    if (idx == (int)primes.size()) {
        if (cur >= 2) divisors.push_back(cur);
        return;
    }
    ll p = primes[idx];
    ll val = 1;
    for (int e = 0; e <= exps[idx]; ++e) {
        gen_divisors(idx + 1, cur * val);
        val *= p;
    }
}

void dfs(ll x, int startIdx, ll sumMinus) {
    if (x == 1) {
        answers.push_back(sumMinus);
        return;
    }
    // iterate divisors from startIdx to end
    for (int i = startIdx; i < (int)divisors.size(); ++i) {
        ll d = divisors[i];
        if (d > x) break;
        if (x % d != 0) continue;
        dfs(x / d, i, sumMinus + (d - 1));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (!(cin >> n)) return 0;

    if (n == 1) {
        cout << 1 << '\n' << 0 << '\n';
        return 0;
    }

    // factor n by trial division
    ll tmp = n;
    for (ll p = 2; p * p <= tmp; ++p) {
        if (tmp % p == 0) {
            int cnt = 0;
            while (tmp % p == 0) {
                tmp /= p;
                ++cnt;
            }
            primes.push_back(p);
            exps.push_back(cnt);
        }
    }
    if (tmp > 1) {
        primes.push_back(tmp);
        exps.push_back(1);
    }

    // generate divisors (excluding 1)
    gen_divisors(0, 1);
    sort(divisors.begin(), divisors.end());

    // DFS to enumerate multiplicative partitions
    dfs(n, 0, 0);

    sort(answers.begin(), answers.end());
    answers.erase(unique(answers.begin(), answers.end()), answers.end());

    cout << answers.size() << '\n';
    for (size_t i = 0; i < answers.size(); ++i) {
        if (i) cout << ' ';
        cout << answers[i];
    }
    cout << '\n';
    return 0;
}
