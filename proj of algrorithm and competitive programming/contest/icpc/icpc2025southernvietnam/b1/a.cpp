#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<unsigned long long> excl;
    excl.push_back(3ULL);
    for (int k = 1; k <= 17; k += 2) {
        unsigned long long x = 1;
        for (int i = 0; i < k; ++i) x *= 10ULL;
        x -= 1ULL;
        excl.push_back(x);
    }
    sort(excl.begin(), excl.end());
    excl.erase(unique(excl.begin(), excl.end()), excl.end());

    int q;
    if (!(cin >> q)) return 0;
    while (q--) {
        unsigned long long L, R;
        cin >> L >> R;
        unsigned long long cnt = R / 3ULL - ( (L - 1ULL) / 3ULL );
        for (auto x : excl) {
            if (x < L) continue;
            if (x > R) break;
            cnt -= 1ULL;
        }
        cout << cnt << '\n';
    }
    return 0;
}