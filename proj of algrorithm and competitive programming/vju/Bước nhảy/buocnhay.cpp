#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        vector<long long> dp(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            dp[i]=a[i];
        }
        for(int i = 0; i < n; i++) {
            if (i + a[i] < n) {
                dp[i + a[i]] = max(dp[i + a[i]], dp[i] + a[i + a[i]]);
            }
        }
        cout << *max_element(dp.begin(), dp.end()) << "\n";
    }
    return 0;
}
