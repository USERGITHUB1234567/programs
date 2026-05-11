#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
void sub12(long long n, long long a, long long b, long long c, long long d)
{
    long long kq=0;
    for(long long i=a; i<=b; i++) {
        long long t=n-i;
        if(t>=c and t<=d) kq++;
    }
    cout << kq;
}
int main()
{
    freopen("dun.inp", "r", stdin);
    freopen("dun.out", "w", stdout);
    long long n,a,b,c,d;
    cin >> n >> a >> b >> c >> d;
    if(n<300000 and b<300000 and d<300000) {
        sub12(n,a,b,c,d);
        return 0;
    }
    long long mia=b,mib=d,maa=a,mab=c;
    mia=min(mia,n-c);
    mib=min(mib,n-a);
    maa=max(maa,n-d);
    mab=max(mab,n-b);
    long long ha=mia-maa,hb=mib-mab,kq=min(ha+1,hb+1);
    if(kq<=0) cout << 0;
    else cout << kq;
}
