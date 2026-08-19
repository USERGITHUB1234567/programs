#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
using namespace std;
const int maxn=300005;
int n;
long double c[maxn],a=0,b=0,ta=0,tb=0,mi=LLONG_MIN,t=0,tbb;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> c[i];
        t+=c[i];
    }
    sort(c+1,c+1+n,greater<long double>());
    for(int i=1; i<=n; i++) {
        tbb+=c[i];
        tb=tbb/t;
        ta=(long double)i/n;
        if(tb-ta>mi) {
            mi=tb-ta;
            a=ta*100;
            b=tb*100;
        }
    }
    cout << setprecision(14) << fixed << a << "\n" << b;
}