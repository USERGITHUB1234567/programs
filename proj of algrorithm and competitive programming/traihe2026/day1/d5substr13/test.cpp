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
int MOD = 1e9 + 7;
const int inf = 1e9 + 36;
const ll INF = 1e18 + 36;
const long double EPS = 1e-15;
const int N = 202;
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
int add(int a, int b) {
    a = (a + b) % MOD;
    if (a < 0)
        a += MOD;
    return a;
}
int mul(int a, int b) {
    return 1LL * a * b % MOD;
}
int bin_pow(int a, ll b) {
    int s = 1;
    while (b) {
        if (b & 1)
            s = mul(s, a);
        a = mul(a, a);
        b >>= 1LL;
    }
    return s;
}
int n, m, k, nx, ny, dp[N][N][N], nxtX[26][N], nxtY[26][N];
string x, y;
int f(int idx, int px, int py) {
    if (idx == 0)
        return py == ny + 1;
    if (dp[idx][px][py] != -1)
        return dp[idx][px][py];
    int res = 0;
    FOR(c, 0, 25) {
        int npx = nxtX[c][px];
        if (npx == nx + 1)
            continue;
        int npy = nxtY[c][py];
        res = add(res, f(idx - 1, npx, npy));
    }
    return dp[idx][px][py] = res;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //file(":((");
    cin >> m >> n >> k >> x >> y;
    MOD = k;
    nx = (int) x.size();
    ny = (int) y.size();
    FOR(c, 0, 25) {
        nxtX[c][nx] = nx + 1;
        nxtY[c][ny] = ny + 1;
        nxtX[c][nx + 1] = nx + 1;
        nxtY[c][ny + 1] = ny + 1;
    }
    REP(i, nx - 1, 0) {
        FOR(c, 0, 25)
            nxtX[c][i] = nxtX[c][i + 1];
        nxtX[x[i] - 'a'][i] = i + 1;
    }
    REP(i, ny - 1, 0) {
        FOR(c, 0, 25)
            nxtY[c][i] = nxtY[c][i + 1];
        nxtY[y[i] - 'a'][i] = i + 1;
    }
    mmb(dp, -1);
    FOR(i, 0, m - 1) {
        string s;
        cin >> s;
        int ans = 0;
        int px = 0, py = 0;
        bool ok = true;
        for (char ch : s) {
            int c = ch - 'a';
            px = nxtX[c][px];
            py = nxtY[c][py];
            if (px == nx + 1) {
                ok = false;
                break;
            }
        }
        if (!ok || py != ny + 1) {
            cout << -1 << '\n';
            continue;
        }
        int rnk = 1;
        px = 0, py = 0;
        FOR(i, 0, n - 1) {
            int cur = s[i] - 'a';
            FOR(c, 0, cur - 1) {
                int npx = nxtX[c][px];
                if (npx == nx + 1)
                    continue;
                int npy = nxtY[c][py];
                rnk = add(rnk, f(n - 1 - i, npx, npy));
            }
            px = nxtX[cur][px];
            py = nxtY[cur][py];
        }
        cout << rnk << '\n';
    }
    return 0;
}