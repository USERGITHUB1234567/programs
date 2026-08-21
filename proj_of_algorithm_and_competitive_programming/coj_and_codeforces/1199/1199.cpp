#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define pl pair <ll, ll>
#define pll pair <pl, ll>
#define __ << ' ' <<
#define pb push_back
#define point pair <ld, ld>
#define x first
#define y second
#define quit return 0
#define fti(i, x, y) for(ll i = (x), _y = (y); i <= _y; ++ i)
#define ftd(i, x, y) for(ll i = (x), _y = (y); i >= _y; -- i)
#define ftx(i, a) for (auto i : a)
#define file(NAME) freopen(NAME".inp", "r", stdin); freopen(NAME".out", "w", stdout)
#define vl vector <ll>
#define mmb(a) memset(a, 0, sizeof(a))
#define mms(a) memset(a, 1, sizeof(a))
#define fil(a, sz, k) fill(a, a + sz, k)
using namespace std;
const ll oo = 1e18, MA = 1e6 + 10;
ll n, m;
point a[105], b[105];
ld res = 1e6;

ld dist(point a, point b){
    ld xx = a.x - b.x, yy = a.y - b.y;
    return sqrt(xx * xx + yy * yy);
}

ld h(point a, point b, point c){
    ld ab = dist(a, b), bc = dist(b, c), ca = dist(c, a), p = (ab + bc + ca) / 2;
    ld s = abs((b.x - a.x) * (c.y - b.y) - (b.y - a.y) * (c.x - b.x)) * 0.5;
    return 2 * s / ab;
}

bool loi(point a, point b, point c){
    ld ab = dist(a, b), bc = dist(b, c), ca = dist(c, a);
    return (ab * ab + bc * bc < ca * ca || ab * ab + ca * ca < bc * bc);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //file("name");
    cin >> n;
    fti(i, 1, n)
        cin >> a[i].x >> a[i].y;
    cin >> m;
    fti(i, 1, m)
        cin >> b[i].x >> b[i].y;
    a[n + 1] = {a[1].x, 1e15}; a[0] = {a[n].x, -1e15};
    b[m + 1] = {b[1].x, 1e15}; b[0] = {b[m].x, -1e15};
    fti(i, 0, n){
        point A1 = a[i], A2 = a[i + 1];
        ld d = dist(A1, A2);
        fti(j, 1, m){
            point B = b[j]; ld A1B = dist(A1, B), A2B = dist(A2, B);
            if (loi(A1, A2, B)){
                res = min({res, A1B, A2B});
            }
            else{
                res = min(res, h(A1, A2, B));
            }
        }
    };
    fti(i, 0, m){
        point A1 = b[i], A2 = b[i + 1];
        ld d = dist(A1, A2);
        fti(j, 1, n){
            point B = a[j]; ld A1B = dist(A1, B), A2B = dist(A2, B);
            if (loi(A1, A2, B)){
                res = min({res, A1B, A2B});
            }
            else{
                res = min(res, h(A1, A2, B));
            }
        }
    }
    cout << fixed << setprecision(5) << res;
    quit;
}
