#include <bits/stdc++.h>
#define file(name) freopen(name".inp","r",stdin); freopen(name".out","w",stdout)
using namespace std;
long long n, a[200005], x[200005];
long long check(long long s)
{
    long long cnt=0;
    for(int i=1;i<=n;i++)
    {
        cnt+=(abs(s-x[i]))*a[i];
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> x[i];
    long long l=1, r=1e9, kq;
    while(l<=r)
    {
        long long mid1 = l + (r-l)/3;
        long long mid2 = r - (r-l)/3;
        //cerr << mid1 << " " << mid2 << "\n";
        if(check(mid1) > check(mid2)) l=mid1+1;
        else
        {
            r=mid2-1;
            kq=mid2;
        }
    }
    cout << kq;
    return 0;
}
