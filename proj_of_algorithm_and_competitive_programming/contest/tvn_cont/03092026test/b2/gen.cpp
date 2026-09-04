#include <bits/stdc++.h>
using namespace std;
mt19937_64 generator(chrono::steady_clock::now().time_since_epoch().count());
long long rnd(long long l, long long r) {return l+generator()%(r-l+1);}
int main(int argc, char** argv) {
    freopen("shopping.inp", "w", stdout);
    int n=rnd(1,100),a=rnd(1,100),b=rnd(1,100);
    cout << n << ' ' << a << ' ' << 0 << '\n';
    for(int i=1; i<=n; ++i) {
        cout << rnd(1,100) << ' ' << rnd(1,100) << ' ' << rnd(1,100) << '\n';
    }
}