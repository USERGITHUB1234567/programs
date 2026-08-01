#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
using namespace std;
const int dx[4][4]={{0,1,0,-1},{1,1,1,0},{0,1,0,-1},{-1,0,-1,-1}};
const int dy[4][4]={{-1,-1,0,-1},{-1,0,1,0},{0,1,1,1},{-1,0,1,0}};
int x[12042], y[13243], h[13232];

int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   int n, d;
   cin >> n >> d;
   for(int i=1;i<=n;i++)
       cin >> x[i] >> y[i];
   x[0]=x[n];
   x[n+1]=x[1];
   y[0]=y[n];
   y[n+1]=y[1];
   int v;
   int u=min_element(y+1,y+1+n)-y;
   if(y[u+1]==y[u])
       v=u+1;
   else
       v=u-1;
   if((u-v)*(x[u]-x[v])<0)
       d=-d;
   for(int i=1;i<=n;i++)
   {
       if(x[i]==x[i+1])
       {
           if(y[i]<y[i+1])
               h[i]=1;
           else
               h[i]=3;
       }
       else
       {
           if(x[i]<x[i+1])
               h[i]=0;
           else
               h[i]=2;
       }
   }
   h[0]=h[n];
   h[n+1]=h[1];
   for(int i=1;i<=n;i++)
       cout << x[i]+d*dx[h[i-1]][h[i]] << " " << y[i]+d*dy[h[i-1]][h[i]] << "\n";
   return 0;
}
