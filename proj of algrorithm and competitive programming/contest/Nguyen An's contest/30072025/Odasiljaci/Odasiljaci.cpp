#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
using namespace std;
const int maxn=1003;
const long double inf=LLONG_MAX,eps=1e-7;
struct point {
    long double x,y;
}p[maxn];
struct dowfsu {
    int p[maxn];
    int findset(int u) {
        if(p[u]==0) return u;
        return p[u]=findset(p[u]);
    }
    bool unite(int u, int v) {
        u=findset(u);
        v=findset(v);
        if(u==v) return 0;
        p[v]=u;
        return 1;
    }
}dsu;
int n;
long double d[maxn];
long double dist(point a, point b) {
    long double t1=fabsl(a.x-b.x),t2=fabsl(a.y-b.y);
    return sqrtl(t1*t1+t2*t2);
}
void souprua() {
    for(int i=1; i<=n; i++) {
        d[i]=inf;
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(i==j) continue;
            d[i]=min(d[i],dist(p[i],p[j])/2);
        }
    }
    long double kq=0;
    for(int i=1; i<=n; i++) kq=max(kq,d[i]);
    cout << setprecision(10) << fixed << kq;
}
bool check(long double r) {
    for(int i=0; i<=n; i++) dsu.p[i]=0;
    int q=n;
    long double limit=4.0L*r*r;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(i==j) continue;
            long double di=(p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y);
            if(di<=limit) {
                q-=dsu.unite(i,j);
            }
        }
    }
    return q==1;
}
void soupbinsearch() {
    long double l=0,r=inf,mid;
    while(r-l>eps) {
        mid=(l+r)/2;
        if(check(mid)) r=mid;
        else l=mid;
    }
    cout << fixed << setprecision(10) << r;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n;
    for(int i=1; i<=n; i++) cin >> p[i].x >> p[i].y;
    soupbinsearch();
}