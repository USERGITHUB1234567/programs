#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int mx = 20000;
const int SEQ198 = (1 << 1) + (1 << 9) + (1 << 8);
int a[mx], res;
int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> dp1(1024, -1), dp2(1024, -1);
    dp1[0] = 0;
    dp1[1] = 1;
    sort(a, a + n);
    for (int i = 1; i < n; i++) {
        int d = a[i] - a[i - 1];
        fill(dp2.begin(), dp2.end(), -1);
        for (int j = 0; j < 1024; j++) {
            if (dp1[j] >= 0) {
                int k = (d >= 10 ? 0 : ((j << d) & 1023));
                dp2[k] = max(dp2[k], dp1[j]);
                if (!(k & SEQ198))
                    dp2[k | 1] = max(dp2[k | 1], dp1[j] + 1);
            }
        }
        dp1.swap(dp2);
    }
    for (int i = 0; i < 1024; i++) {
        res = max(res, dp1[i]);
    }
    cout << n - res;
    return 0;
}
