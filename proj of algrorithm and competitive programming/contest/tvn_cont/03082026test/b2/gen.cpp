#include <bits/stdc++.h>
using namespace std;
mt19937_64 generator(chrono::steady_clock::now().time_since_epoch().count());
long long rnd(long long l, long long r) {return l+generator()%(r-l+1);}
int main(int argc, char** argv) {
    freopen("split.inp", "w", stdout);
    int n=22,k=rnd(1,n);
    cout << n << ' ' << k << '\n';
    for(int i=1; i<=n; ++i) cout << rnd(0,2000) << ' ';
}