#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long aaa(long long n) {
    long long cnt = 0;
    for (long long i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            cnt++;
            if (i != n / i) cnt++;
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<long long> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    long long g = a[0];
    for (int i = 1; i < n; ++i) {
        g = __gcd(g, a[i]);
    }
    cout << aaa(g) << endl;
    return 0;
}
