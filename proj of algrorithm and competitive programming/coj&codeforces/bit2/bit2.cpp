#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("bit2.inp", "r", stdin);
    freopen("bit2.out", "w", stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long t;
    cin >> t;
    while (t--) {
        unsigned long long a, b;
        cin >> a >> b;
        unsigned long long c=a&b;
        int cnt=__builtin_popcountll(c);
        cout << cnt << "\n";
    }
    return 0;
}
