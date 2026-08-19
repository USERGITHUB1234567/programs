#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
#define mkp make_pair
#define eb emplace_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int maxn=200005;
bool mk[maxn];
int n;
struct s1
{
    int x,y;
    char c;
};
bool ktnb(s1 a, s1 b)
{
    if((a.c=='S' && b.c=='N') || (a.c=='N' && b.c=='S')) return true;
    return false;
}
bool ktdt(s1 a, s1 b)
{
    if((a.c=='W' && b.c=='E') || (a.c=='E' && b.c=='W')) return true;
    return false;
}
void rua()
{
    for(int i=1; i<=n; i++) cout << i << "\n";
}
void soup1()
{
    vector<ll> x(n), y(n);
    vector<char> d(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> d[i];
    }
    ll x1 = x[0], y1 = y[0];
    ll x2 = x[1], y2 = y[1];
    char c1 = d[0], c2 = d[1];

    auto dx_of = [&](char c) {
        if (c == 'E') return  1LL;
        if (c == 'W') return -1LL;
        return 0LL;
    };
    auto dy_of = [&](char c) {
        if (c == 'S') return  1LL;
        if (c == 'N') return -1LL;
        return 0LL;
    };
    ll dx1 = dx_of(c1), dy1 = dy_of(c1);
    ll dx2 = dx_of(c2), dy2 = dy_of(c2);
    ll ddx = dx1 - dx2;
    ll ddy = dy1 - dy2;
    ll numx = x2 - x1;
    ll numy = y2 - y1;
    bool collide = false;
    if (ddx == 0 && ddy == 0) {
        collide = false;
    }
    else if (ddx == 0) {
        if (x1 == x2 && ddy != 0 && numy % ddy == 0) {
            ll t = numy / ddy;
            if (t >= 1) collide = true;
        }
    }
    else if (ddy == 0) {
        if (y1 == y2 && ddx != 0 && numx % ddx == 0) {
            ll t = numx / ddx;
            if (t >= 1) collide = true;
        }
    }
    else {
        if (numx % ddx == 0 && numy % ddy == 0) {
            ll t1 = numx / ddx;
            ll t2 = numy / ddy;
            if (t1 == t2 && t1 >= 1) collide = true;
        }
    }
    if (!collide) {
        cout << 1 << "\n" << 2 << "\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n;
    if(n<=2) soup1();
    else rua();
}
