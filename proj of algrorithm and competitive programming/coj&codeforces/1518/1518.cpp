#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<long long> A(n + 1, 0);
    vector<long long> diff(n + 2, 0);

    for (int i = 0; i < m; ++i) {
        int l, r, k;
        cin >> l >> r >> k;
        diff[l] += k;
        diff[r + 1] -= k;
    }

    A[0] = diff[1];
    for (int i = 1; i < n; ++i) {
        A[i] = A[i - 1] + diff[i + 1];
    }

    for (int i = 0; i < n; ++i) {
        cout << A[i];
        if(i<n-1) cout << " ";
    }
    return 0;
}
