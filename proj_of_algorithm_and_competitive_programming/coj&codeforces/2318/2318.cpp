#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long n,s,a[100005],b[100005];
int main()
{
    cin >> n >> s;
    for(int i=1;i<=n;i++)
    {
          cin >> a[i];
          b[i]=b[i-1]+a[i];
    }
    if(b[n]<s)
    {
        cout << -1;
        return 0;
    }
    int l=1, r=1, minn=4e18;
    while(r<=n)
    {
         r++;
         if(b[r]-b[l-1]<s) continue;
         while (b[r]-b[l-1]>s) l++;
         if(b[r]-b[l-1]<s) l--;
         minn=min(minn,r-l+1);
    }
    cout << minn;
    return 0;
}
