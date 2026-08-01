#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int maxn=100005;
int n,m,a[maxn],b[maxn],ft[maxn];
int sum(int i)
{
    int s=0;
    while(i>0) {
        s+=ft[i];
        i-=i&-i;
    }
    return s;
}
void upd(int i, int v)
{
    while(i<=n) {
        ft[i]+=v;
        i+=i&-i;
    }
}
int main()
{
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    cin >> m;
    for(int i=1; i<=m; i++) cin >> b[i];
    sort(a+1,a+n+1,greater<int>());
    for(int i=1; i<=m; i++)
    {
        if(b[i]>a[1]-sum(n))
            cout << 0 << "\n";
        else
        {
            int l=1, r=n;
            while(l<r)
            {
                int c=(l+r+1)>>1;
                if(b[i]<=a[c]-(sum(n)-sum(c-1)))
                    l=c;
                else
                    r=c-1;
            }
            cout << l << "\n";
            upd(l,1);
        }
    }
    return 0;
}
