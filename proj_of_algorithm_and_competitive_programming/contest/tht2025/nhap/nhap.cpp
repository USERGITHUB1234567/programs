#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

const int MAX_N = 1002;
const int MAX_SIEVE = 1000002;

int n, res = 0;
bool ok[MAX_SIEVE];
long long mx = 0;
vector<long long> a(MAX_N), b(MAX_N);
vector<int> primes;
void sub1() {
    if (__gcd(a[1], a[2]) != 1)
        res = 2;
    else {
        if (a[1] != 1 || a[2] != 1)
            res = 1;
    }
}
void sub2() {
    int totalMasks = 1 << n;
    for (int mask = 0; mask < totalMasks; mask++) {
        int count = 0;
        long long currentGCD = 0;
        for (int i = 0; i < n; i++) {
            if ((mask >> i) & 1) {
                currentGCD = __gcd(currentGCD, a[i + 1]);
                count++;
            }
        }
        if (currentGCD > 1)
            res = max(res, count);
    }
}
void sub3() {
    memset(ok, true, sizeof(ok));
    ok[0] = ok[1] = false;
    for (int i = 2; i * i <= 1000000; i++) {
        if (ok[i]) {
            for (int j = i * i; j <= 1000000; j += i)
                ok[j] = false;
        }
    }
    for (int j = 2; j <= 1000000; j++) {
        if (ok[j]) {
            int count = 0;
            for (int i = 1; i <= n; i++) {
                if (a[i] % j == 0)
                    count++;
            }
            res = max(res, count);
        }
    }
}
void sub4() {
    memset(ok, true, sizeof(ok));
    ok[0] = ok[1] = false;
    for (int i = 2; i <= 1000000; i++) {
        if (ok[i]) {
            primes.push_back(i);
            if (i * i <= 1000000)
                break;
            for (int j = i * i; j <= 1000000; j += i)
                ok[j] = false;
        }
    }
    for (int prime : primes) {
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (b[i] % prime == 0)
                count++;
        }
        res = max(res, count);
        for (int i = 1; i <= n; i++) {
            while (a[i] % prime == 0)
                a[i] /= prime;
        }
    }
    unordered_map<long long, int> freq;
    for (int i = 1; i <= n; i++) {
        if (b[i] > 1)
            freq[b[i]]++;
    }
    for (auto &entry : freq)
        res = max(res, entry.second);
    unordered_set<long long> commonDivisors;
    for (int i = 1; i <= n; i++) {
        if (b[i] > 1) {
            for (int j = i + 1; j <= n; j++) {
                if (b[j] > 1) {
                    long long g = __gcd(b[i], b[j]);
                    if (g > 1)
                        commonDivisors.insert(g);
                }
            }
        }
    }
    for (long long g : commonDivisors) {
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] % g == 0)
                count++;
        }
        res = max(res, count);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    a.resize(n + 1);
    b.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
        mx = max(mx, a[i]);
    }

    if (n <= 2)
        sub1();
    else if (n <= 18)
        sub2();
    else if (mx <= 1000000)
        sub3();
    else
        sub4();

    cout << res;
    return 0;
}
