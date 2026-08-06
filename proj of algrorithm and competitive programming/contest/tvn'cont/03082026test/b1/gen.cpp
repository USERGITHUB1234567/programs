#include <bits/stdc++.h>
using namespace std;
mt19937_64 generator(chrono::steady_clock::now().time_since_epoch().count());
long long rnd(long long l, long long r) {return l+generator()%(r-l+1);}
int main(int argc, char** argv) {
    freopen("rabit.inp", "w", stdout);
    int n=10,q=10;
    cout << n << ' ' << q << '\n';
    for(int i=1; i<=n; ++i) cout << rnd(1,1000000000) << ' ';
    cout << '\n';
    for(int i=1; i<=q; ++i) {
        int l=rnd(0,n-1),r=rnd(0,n-1);
        if(l>r) swap(l,r);
        cout << l << ' ' << r << '\n';
    }
}