#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main() {
    //freopen("");
    //freopen("");
    long long n, w;
    cin >> n >> w;
    pair<long long, long long> p[n];
    for (int i=0; i<n; i++) {
        cin >> p[i].first >> p[i].second;
    }
    long long dp[w+1]={0};
    for (long long i=0; i<n; i++) {
        for (int j=w; j>=p[i].first; j--) {
            dp[j]=max(dp[j], dp[j-p[i].first]+p[i].second);
        }
    }
    cout << dp[w];
    return 0;
}
