#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define file(x) freopen(x".inp", "r", stdin);freopen(x".out", "w", stdout);
#define pb push_back
#define fi first
#define se second

using namespace std;
typedef long long ll;
const ll INF = 4e18;
const int N = 5e4 + 5;

int n, ptr = 0;
pair <ll, ll> a[N];

bool cmp(pair <ll, ll> a, pair <ll, ll> b)
{
    if (a.fi != b.fi) return a.fi < b.fi;
    return a.se > b.se;
}

struct Line
{
    ll m, b;
};

vector<Line> hull;

ll eval(const Line &ln, ll x)
{
    ll v = ln.m * x + ln.b;
    return v;
};

bool bad(const Line &l1, const Line &l2, const Line &l3)
{
    return (l3.b - l1.b) * (l1.m - l2.m) <= (l2.b - l1.b) * (l1.m - l3.m);
}

void add_line(ll &slope, ll &intercept)
{
    Line nw = {slope, intercept};
    while (hull.size() >= 2 && bad(hull[hull.size() - 2], hull[hull.size() - 1], nw)) hull.pop_back();
    hull.push_back(nw);
    if (ptr >= (int)hull.size()) ptr = (int)hull.size() - 1;
}

ll query(ll &x)
{
    if (hull.empty()) return INF;
    while (ptr + 1 < (int)hull.size() && eval(hull[ptr + 1], x) <= eval(hull[ptr], x)) ++ptr;
    return eval(hull[ptr], x);
}

int main()
{
    fast
    file("acquire");
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].fi >> a[i].se;
    sort(a + 1, a + n + 1, cmp);
    vector<pair<ll, ll>> b;
    for (int i = 1; i <= n; i++) {
        int w = a[i].fi, l = a[i].se;
        if (!b.empty() && b.back().fi == w) continue;
        while (!b.empty() && b.back().se <= l) b.pop_back();
        b.push_back({w, l});
    }
    int m = (int)b.size();
    if (m == 0) { cout << 0 << '\n'; return 0; }
    vector<ll> w(m + 1), h(m + 1);
    for (int i = 1; i <= m; i++) {
        w[i] = b[i - 1].fi;
        h[i] = b[i - 1].se;
    }
    hull.reserve(m + 5);
    vector<ll> dp(m + 1, 0);
    dp[0] = 0;
    add_line(h[1], dp[0]);
    for (int i = 1; i <= m; i++) {
        dp[i] = query(w[i]);
        if (i < m) add_line(h[i + 1], dp[i]);
    }
    cout << dp[m];
    return 0;
}
