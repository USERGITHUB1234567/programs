#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mmb(x, v) memset(x, v, sizeof(x))
#define FOR(i, x, y) for (int i = (int) x; i <= (int) y; ++i)
#define REP(i, x, y) for (int i = (int) x; i >= (int) y; --i)
#define all(x) x.begin(), x.end()
#define zip(x) sort(x.begin(), x.end()); x.erase(unique(all(x)), x.end());
#define file(name) freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout);
using namespace std;
const int MOD = 1e9 + 7;
const int inf = 1e9 + 36;
const ll INF = 1e18 + 36;
const long double EPS = 1e-15;
const int N = 2002;
int minmize(int a, int b) {
    return a < b ? a : b;
}
int maxmize(int a, int b) {
    return a > b ? a : b;
}
ll Minmize(ll a, ll b) {
    return a < b ? a : b;
}
ll Maxmize(ll a, ll b) {
    return a > b ? a : b;
}
int n, a, b, y[N];
ll pre[N];
bitset<N> dp[N];
bool check(ll mask) {
    FOR(i, 0, n)
        dp[i].reset();
    dp[0][0] = 1;
    FOR(i, 0, n - 1)
        if (!dp[i].none())
            FOR(j, i + 1, n) {
                ll sum = pre[j] - pre[i];
                if (!(sum & ~mask))
                    dp[j] |= (dp[i] << 1);
            }
    FOR(i, a, b)
        if (dp[n][i])
            return true;
    return false;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //file("");
    cin >> n >> a >> b;
    FOR (i, 1, n) {
        cin >> y[i];
        pre[i] = pre[i - 1] + y[i];
    }
    ll ans = 0;
    REP(i, 60, 0) {
        ll mask = ans | ((1LL << i) - 1);
        if (!check(mask))
            ans |= (1LL << i);
    }
    cout << ans;
    return 0;
}