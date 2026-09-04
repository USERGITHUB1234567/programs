#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fti(i, x, y) for (int i = x; i <= y; ++i)
#define ftd(i, x, y) for (int i = x; i >= y; --i)

const int MA = 1e5 + 5;

int n;
ll dp[MA], S, t[MA], f[MA], cnt[MA], pt[MA], pf[MA], dP[202][202];

void sub2()
{
    fti(i, 0, n) fti(j, 0, n) dP[i][j] = 1e18;
    fti(i, 1, n) dP[i][1] = (pt[i] + S) * pf[i];
    fti(k, 2, n)
        fti(l, k - 1, n)
            fti(r, l + 1, n)
                dP[r][k] = min(dP[r][k], dP[l][k - 1] + (S * k + pt[r]) * (pf[r] - pf[l]));
    ll res = 1e18;
    fti(i, 1, n) res = min(res, dP[n][i]);
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("batch.inp", "r", stdin);
    freopen("batch.out", "w", stdout);
    cin >> n >> S;
    fti(i, 1, n) cin >> t[i] >> f[i];
    fti(i, 1, n) pt[i] = pt[i - 1] + t[i], pf[i] = pf[i - 1] + f[i];
    sub2();
    return 0;
}
