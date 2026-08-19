#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long souoc(long long n, long long k)
{
    long long d=0;
    for(int i=1; i*i<=n; i++) {
        if(n%i==0 and n/i<=k and i<=k) {
            d+=2;
            if(i*i==n) d--;
        }
    }
    return d;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    freopen("squ.inp", "r", stdin);
    freopen("squ.out", "w", stdout);
    long long n;
    cin >> n;
    long long kq=0;
    for(int i=1; i<=n; i++) {
        kq+=souoc(i*i,n);
    }
    cout << kq;
    return 0;
}
