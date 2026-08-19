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
const int N = 20;
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
int n, a[N], ans[N];\
ll t;
ll dp[20][20][20][20];
void update(int &mn1, int &mn2, int &mx, int x) {
    if (x < mn1) {
        mn2 = mn1;
        mn1 = x;
    }
    else if (x < mn2)
        mn2 = x;
    mx = maxmize(mx, x);
}
ll f(int idx, int mn1, int mn2, int mx) {
    if (idx == n + 1)
        return mn1 + mn2 > mx;
    if (dp[idx][mn1][mn2][mx] != -1)
        return dp[idx][mn1][mn2][mx];
    ll res = 0;
    FOR(x, 1, n) {
        int nmn1 = mn1, nmn2 = mn2, nmx = mx;
        update(nmn1, nmn2, nmx, x);
        res += f(idx + 1, nmn1, nmn2, nmx);
    }
    return dp[idx][mn1][mn2][mx] = res;
}
ll pw(int a, int b) {
    ll s = 1;
    FOR(i, 1, b)
        s *= b;
    return s;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //file(":((");
    cin >> n >> t;
    FOR(i, 1, n)
        cin >> a[i];

    mmb(dp, -1);
    int mn1 = n + 1, mn2 = n + 1, mx = 0;
    FOR(idx, 1, n)
        FOR(x, 1, n) {
            int nmn1 = mn1, nmn2 = mn2, nmx = mx;
            update(nmn1, nmn2, nmx, x);
            ll k = f(idx + 1, nmn1, nmn2, nmx);
            if (t > k)
                t -=k;
            else {
                ans[idx] = x;
                mn1 = nmn1;
                mn2 = nmn2;
                mx = nmx;
                break;
            }
        }
    ll rnk = 1;
    mn1 = n + 1, mn2 = n + 1, mx = 0;
    mmb(dp, -1);
    FOR(idx, 1, n) {
        FOR(x, 1, a[idx] - 1) {
            int nmn1 = mn1, nmn2 = mn2, nmx = mx;
            update(nmn1, nmn2, nmx, x);
            rnk += f(idx + 1, nmn1, nmn2, nmx);
        }
        update(mn1, mn2, mx, a[idx]);
    }
    mmb(dp, -1);
    cout << f(1, n + 1, n + 1, 0) << '\n';
    FOR(i, 1, n)
        cout << ans[i] << ' ';
    cout << '\n';
    cout << rnk << '\n';
    return 0;
}