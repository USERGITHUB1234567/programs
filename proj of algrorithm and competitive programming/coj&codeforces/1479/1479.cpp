#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
struct ga
{
    int t,p,s;
};
int n,k,t,f[102][102];
ga a[102];
bool cmp(ga u, ga v)
{
    return u.t<v.t;
}
int main()
{
    cin >> n >> k >> t;
    for(int i=1; i<=n; i++) cin >> a[i].t;
    for(int i=1; i<=n; i++) cin >> a[i].p;
    for(int i=1; i<=n; i++) cin >> a[i].s;
    memset(f,-1,sizeof(f));
    sort(a+1,a+1+n,cmp);
    f[0][0]=0;
    a[0]={0,0,0};
    for(int i=1; i<=n; i++) {
        int dt=a[i].t-a[i-1].t;
        for(int j=0; j<=k; j++) {
            for(int l=max(j-dt,0); l<=min(j+dt,k); l++) {
                if(f[i-1][l]!=-1) {
                    int s=f[i-1][l];
                    if(j==a[i].s) s+=a[i].p;
                    f[i][j]=max(f[i][j],s);
                }
            }
        }
    }
    int re=0;
    for(int i=0; i<=k; i++) re=max(re,f[n][i]);
    cout << re;
}
