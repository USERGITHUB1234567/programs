#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const long long INF = 1e15;
struct firo {
    int l, r, c;
};
long long dp[305][305];
long long co[305][305];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < 305; i++){
        for (int j = 0; j < 305; j++){
            dp[i][j] = INF;
            co[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++){
        dp[i][0] = 0;
    }
    for (int i = 1; i <= m; i++){
        int l, r, c;
        cin >> l >> r >> c;
        for (int j = l; j <= r; j++){
            co[l][j] = min(co[l][j], (long long)c);
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= i; j++){
            dp[i][j] = dp[i-1][j];
            for (int l = 1; l <= j && l <= i; l++){
                int s = i - l + 1;
                if (co[s][i] < INF){
                    dp[i][j] = min(dp[i][j], dp[s-1][j-l] + co[s][i]);
                }
            }
        }
    }
    long long ans = INF;
    for (int j = k; j <= n; j++){
        ans = min(ans, dp[n][j]);
    }
    cout << (ans >= INF ? -1 : ans);
    return 0;
}
