#include <bits/stdc++.h>
using namespace std;
mt19937_64 generator(chrono::steady_clock::now().time_since_epoch().count());
long long rnd(long long l, long long r) {return l+generator()%(r-l+1);}
int main(int argc, char** argv) {
    freopen("topic.inp", "w", stdout);
    int n=rnd(1,1000),k=10000/n;
    cout << n << ' ' << k << '\n';
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=k; ++j) {
            if(i<=1) cout << 0 << ' ';
            else cout << rnd(1,1000000000) << ' ';
        }
        cout << '\n';
    }
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=k; ++j) {
            cout << rnd(1,1000000000) << ' ';
        }
        cout << '\n';
    }
}