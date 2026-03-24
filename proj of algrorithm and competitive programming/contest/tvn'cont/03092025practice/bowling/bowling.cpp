#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define file(name) freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout);
#define fi first
#define se second
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
const int maxn = 200005;
int n;
ll kq=0,a[maxn],d=0,s1[maxn],s2[maxn];
struct convexhulltrick {
    vector<pair<ll,ll>> hull;
    bool bad(pair<ll,ll>&l1, pair<ll,ll>&l2, pair<ll,ll>&l3) {
        return (long double)(l3.fi-l1.fi)/(l1.se-l3.se)<(long double)(l2.fi-l1.fi)/(l1.se-l2.se);
    }
    void add(pair<ll,ll>l) {
        while(hull.size()>=2 && bad(hull[hull.size()-2],hull.back(),l)) hull.pop_back();
        hull.push_back(l);
    }
    long long query(long long x) {
        int l=0,r=hull.size()-1;
        while(l<r) {
            int m=(l+r)>>1;
            long long v1=hull[m].fi*x+hull[m].se;
            long long v2=hull[m+1].fi*x+hull[m+1].se;
            if(v1<=v2) l=m+1;
            else r=m;
        }
        return hull[l].fi*x+hull[l].se;
    }
} cht;
void soup2() {
    ll best = 0;
    for (int i = 1; i <= n; ++i) {
        ll t = 0;
        d = 0;
        for (int j = i; j <= n; ++j) {
            ++d;
            t += d * a[j];
            best = max(best, t);
        }
    }
    cout << best;
}
void soup3() {
    d=0;
    s1[0]=s2[0]=0;
    for (int i=1; i<=n; ++i) {
        s1[i]=s1[i-1]+a[i];
        ++d;
        s2[i]=s2[i-1]+d*a[i];
    }
    cht.hull.clear();
    kq=0;
    for (int i=1; i<=n; ++i) {
        ll k=i-1;
        ll m=-k;
        ll b=-s2[k]+k*s1[k];
        cht.add({m,b});
        ll cur=s2[i]+cht.query(s1[i]);
        kq=max(kq,cur);
    }
    cout << kq;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    if(n<=1000) {
        soup2();
        return 0;
    }
    soup3();
    return 0;
}
