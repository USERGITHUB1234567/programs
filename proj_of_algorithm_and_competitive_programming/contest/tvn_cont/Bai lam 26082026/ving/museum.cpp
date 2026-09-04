#include <bits/stdc++.h>
using namespace std;
int n,m,d;
mt19937_64 generator(chrono::steady_clock::now().time_since_epoch().count());
long long rnd(long long l, long long r) {return l+generator()%(r-l+1);}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    freopen("museum.inp", "r", stdin);
    freopen("museum.out", "w", stdout);
    cin >> n >> m >> d;
    cout << rnd(0,n);
}
