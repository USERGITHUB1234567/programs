#include <bits/stdc++.h>
using namespace std;

const int maxn = 10004;
int n;
int a[5][maxn];
int dp[maxn][1 << 4];

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n;
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= 4; i++){
            cin >> a[i][j];
        }
    }
    vector<int> masks;
    for (int mask = 0; mask < (1 << 4); mask++){
        bool ok = true;
        for (int i = 0; i < 3; i++){
            if ((mask & (1 << i)) && (mask & (1 << (i + 1)))) {
                ok = false;
                break;
            }
        }
        if(ok){
            masks.push_back(mask);
        }
    }
    for (int j = 0; j <= n; j++){
        for (int mask = 0; mask < (1 << 4); mask++){
            dp[j][mask] = -1e9;
        }
    }
    dp[0][0] = 0;
    for (int j = 1; j <= n; j++){
        for (int mask : masks) {
            int cost = 0;
            for (int i = 0; i < 4; i++){
                if(mask & (1 << i))
                    cost += a[i + 1][j];
            }
            for (int prev = 0; prev < (1 << 4); prev++){
                if(dp[j - 1][prev] == -1e9) continue;
                if(mask & prev) continue;
                dp[j][mask] = max(dp[j][mask], dp[j - 1][prev] + cost);
            }
        }
    }
    int ans = -1e9;
    for (int mask = 0; mask < (1 << 4); mask++){
        ans = max(ans, dp[n][mask]);
    }
    cout << ans << "\n";

    return 0;
}
