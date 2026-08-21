#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        long long a[n+1], m[n+1], ma = 0, re[n+1];
        a[0] = 0;
        m[0] = 0;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++) {
            ma = max(ma, a[i]);
            m[i] = ma;
        }
        long long s = 0;
        for (int i = n; i >= 1; i--) {
            s += a[i];
            if (a[i] < m[i-1])
                re[i] = max(s, s - a[i] + m[i-1]);
            else
                re[i] = s;
        }
        for (int i = n; i >= 1; i--)
            cout << re[i] << " ";
        cout << "\n";
    }
    return 0;
}
