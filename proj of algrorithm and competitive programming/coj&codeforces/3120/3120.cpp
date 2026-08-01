#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
using namespace std;
const int maxn=100005;
long long n,m,kq=0;
long long up(long long n) {
    long long d=n/2;
    if((d)*2>=n) return d;
    return d+1;
}
long long down(long long m) {
    long long d=sqrt(m);
    if(d*d<m) return d;
    return d-1;
}
void soup1() {

    /*for(int i=1; i<n; i++) {
        kq+=up(i);
        //cout << up(i) << " ";
    }
    for(int i=1; i<m; i++) {
        kq+=down(i);
        //cout << down(i) << " ";
    }
    cout << kq;*/
    for(int i=1; i<=100; i++) cout << down(i) << " ";
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> m;
    long long u=0,v=0;
    long long d=n/2;
    u=d*(d+1);
    if(n%2==0) u-=d;
    for(long long i=1; i*i<m-1; i++) {
        long long st=i*i;
        long long ls=min((i+1)*(i+1)-1,m-2);
        long long cnt=ls-st+1;
        v+=i*cnt;
    }
    cout << u << ' ' << v;
}