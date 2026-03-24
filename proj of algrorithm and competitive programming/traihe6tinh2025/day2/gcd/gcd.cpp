#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#define int long long
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn=20;
const long double inf=1e18;
int n,fm;
long double f[1<<maxn];
struct point
{
    ld x,y;
} p[maxn];
long double dist(point a, point b)
{
    ld t1=abs(a.x-b.x), t2=abs(a.y-b.y);
    return sqrt(t1*t1+t2*t2);
}
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n;
    n*=2;
    fm=1<<n;
    for(int i=0; i<=fm+1; i++) f[i]=inf;
    f[0]=0;
    for(int i=0; i<n; i++) cin >> p[i].x >> p[i].y;
    for(int mask=0; mask<fm; mask++) {
        for(int i=0; i<n; i++) {
            if((mask&(1<<i))) continue;
            for(int j=0; j<n; j++) {
                if(mask&(1<<j) || i==j) continue;
                int nm=mask|(1<<j);
                nm|=(1<<i);
                long double di=dist(p[i],p[j]);
                f[nm]=min(f[nm],f[mask]+di);
            }
        }
    }
    cout << fixed << setprecision(6) << f[fm-1];
}
