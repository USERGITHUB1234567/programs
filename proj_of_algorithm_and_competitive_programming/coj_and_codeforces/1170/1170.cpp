#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, d;
    long long t = 0;
    cin >> n >> d;
    vector<long long> v;
    long long a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] % d == 0) {
            v.push_back(a[i]);
            t = __gcd(t, a[i]);
        }
    }
    if (v.empty() || t != d) {
        cout << -1;
    } else {
        cout << v.size() << "\n";

        for (int i = 0; i < v.size(); i++) {
            cout << v[i];
            if (i < v.size() - 1) cout << " ";
        }
        cout << "\n";
    }

    return 0;
}
