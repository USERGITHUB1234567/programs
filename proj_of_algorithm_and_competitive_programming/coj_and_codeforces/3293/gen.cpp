#include <bits/stdc++.h>
using namespace std;
mt19937_64 generator(chrono::steady_clock::now().time_since_epoch().count());
long long rnd(long long l, long long r) {return l+generator()%(r-l+1);}
int main(int argc, char** argv) {
    freopen("3293.inp", "w", stdout);
    int n=rnd(200000,200000),q=rnd(1,min(20,n-1));
    cout << n << ' ' << q << '\n';
    for(int i=1; i<=n; ++i) cout << rnd(1,1000000000) << ' ';
    cout << '\n';
    int p[n];for(int i=0; i<n; ++i) p[i]=i+1;
    shuffle(p,p+n,generator);
    for(int i=1; i<=q; ++i) cout << p[i-1] << '\n';
    ifstream ifs("3293.out");
    string s;
    while(ifs>>s) cout << s << '\n';
}