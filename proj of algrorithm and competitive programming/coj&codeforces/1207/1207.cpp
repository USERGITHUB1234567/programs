#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#define int long long
using namespace std;
int x[255], y[255];
int d[1000006];

signed main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   int n, m;
   cin >> n >> m;
   int ans=0;
   for(int i=1;i<=m;i++)
       cin >> x[i] >> y[i];
   for(int i=1;i<=n;i++)d[i]=1;
   for(int i=1;i<=m;i++)
       for(int j=i+1;j<=m;j++)
       {
           int a= y[i] - y[j], b= -(x[i]-x[j]),  c= -a * x[i] - b * y[i];
           if(a!=0 && c%a==0 && -c/a >= 1 && -c/a <= n)
           {
               int xx=-c/a;
               int cnt=2;
               for(int k=j+1;k<=m;k++)
                   if(a*x[k]+b*y[k]+c==0) cnt++;
               d[xx]=max(d[xx],cnt);
           }
       }
   for(int i=1;i<=n;i++) ans+=d[i];
   cout << ans;
   return 0;
}

