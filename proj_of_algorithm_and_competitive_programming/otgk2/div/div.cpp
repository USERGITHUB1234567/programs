#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int tcs(int n)
{
    int re=0;
    while(n>0) {
        re+=n%10;
        n/=10;
    }
    return re;
}
int main()
{
    freopen("div.inp", "r", stdin);
    freopen("div.out", "w", stdout);
    int a,b,kq=0,m=0;
    cin >> a >> b;
    for(int i=1; i*i<=__gcd(a,b); i++) {
        if(a%i==0 and b%i==0 and tcs(i)>m) {
            m=tcs(i);
            kq=i;
        }
        int t=__gcd(a,b)/i;
        if(tcs(t)>m and a%t==0 and b%t==0) {
            m=tcs(t);
            kq=t;
        }
    }
    cout << kq;
}
