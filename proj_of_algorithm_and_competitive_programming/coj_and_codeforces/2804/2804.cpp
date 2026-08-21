#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
#define all(x) x.begin(),x.end()
#define eb emplace_back
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
const int maxn=100005;
const long double eps=1e-12;
int n;
long double a[maxn];
pair<long double,long double> cal(long double x) {
    long double mx,mn,f,g;
    mx=mn=f=g=a[1]-x;
    for(int i=2; i<=n; ++i) {
        long double b=a[i]-x;
        mx=max(b,mx+b);
        mn=min(b,mn+b);
        f=max(f,mx);
        g=min(g,mn);
    }
    g=max((long double)0,-g);
    return {f,g};
}
long double binary_search(long double l,long double r) {
    while(r-l>eps) {
        long double m=(l+r)/2;
        auto [f,g]=cal(m);
        if(f<g) r=m;
        else l=m;
    }
    return max(cal((l+r)/2).first,cal((l+r)/2).second);
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];
    cout << fixed << setprecision(6) << binary_search(*min_element(a+1,a+n+1),*max_element(a+1,a+n+1));
}