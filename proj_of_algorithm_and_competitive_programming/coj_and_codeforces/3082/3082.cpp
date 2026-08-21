#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int inf=2147483647;
long long n, a[200001], dp[200001], be[200001];
int main() {
    cin >> n;
    for (int i=2; i<=n; i++) dp[i]=inf;
    for (int i=0; i<=n; i++) be[i]=inf;
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<=n; i++) {
        dp[i]=min(dp[i], be[a[i]]+1);
        if (a[i]>=a[i-1]) dp[i]=min(dp[i], dp[i-1]);
        if (a[i-1]<=a[i]) be[a[i]]=min(be[a[i]], dp[i]);
    }
    if(dp[n]==inf) cout << -1;
    else cout << dp[n];
    return 0;
}
