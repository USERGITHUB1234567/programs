#include <bits/stdc++.h>
using namespace std;
mt19937_64 generator(chrono::steady_clock::now().time_since_epoch().count());
long long rnd(long long l, long long r) {return l+generator()%(r-l+1);}
int main(int argc, char** argv) {
    freopen("3294.inp", "w", stdout);
    int n=rnd(1000,1000),q=rnd(1000,1000);
    cout << n << ' ' << q << '\n';
    for(int i=1; i<=n; ++i) cout << rnd(0,2) << ' ';
    for(int i=1; i<n; ++i) cout << i << ' ' << i+1 << '\n';
    for(int i=1; i<=q; ++i) {
        int l=rnd(1,n),r=rnd(1,n),w=rnd(0,4);
        if(l>r) swap(l,r);
        cout << l << ' ' << r << ' ' << w << '\n';
    }
}