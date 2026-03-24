#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    //freopen("fra.inp", "r", stdin);
    //freopen("fra.out", "w", stdout);
    long long n,m,d,r;
    cin >> n >> m;
    if(n==0 or m==0)
    {
        if(n==0)
        {
            long long a=m/4, b=m/4;
            long long r=m%4;
            if(r>=2)
                a++;
            cout << 2*a*2*b;
            return 0;
        }
        if(m==0)
        {
            long long a=n/4, b=n/4;
            long long r=n%4;
            if(r>=2)
                a++;
            cout << a*b;
            return 0;
        }
    }
    int t=n/2;
    m+=n/2;
    d=(m/4)*2;r=d;
    if(m%4==1) {
        if(n>=2) d++;
    }
    if(m%4==2) {
        if(n>=4) {
            d++;
            r++;
        }
        else if(n>=2) d+=2;
    }
    if(m%4==3) {
        if(n>=6) {
            d+=2;
            r++;
        }
        else if(n>=4) {
            d+=2;
            r++;
        }
        else if(n>=2) {
            d+=2;
            r++;
        }
    }
    cout << d*r;
    return 0;
}
/*code ac
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#define file(name) freopen(name".inp","r",stdin); freopen(name".out","w",stdout)
using namespace std;

int main()
{
    file("fra")
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n, m;
    cin >> n >> m;
    if(n==0 ot m==0)
    {
        if(n==0)
        {
            long long a=m/4, b=m/4;
            long long r=m%4;
            if(r>=2)
                a++;
            cout << 2*a*2*b;
            return 0;
        }
        if(m==0)
        {
            long long a=n/4, b=n/4;
            long long r=n%4;
            if(r>=2)
                a++;
            cout << a*b;
            return 0;
        }
    }
    long long maxx=(n+2*m)/2, ans=0, ca=(n+2*m)/4;
    for(long long a=ca-1; a<=ca; a++)
    {
        if(n<2*(a%2))
            continue;
        long long b=maxx-a;
        if(n<2*(a%2+b%2))
            b--;
        ans=max(ans,a*b);
    }
    cout << ans;
    return 0;
}*/
