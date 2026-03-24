#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;

    vector<long long> d;

    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            d.push_back(i);
            if (i != n / i) {
                d.push_back(n / i);
            }
        }
    }

    sort(d.begin(), d.end());

    if (d.size() < k) {
        cout << -1;
    } else {
        cout << d[k - 1];
    }

    return 0;
}
