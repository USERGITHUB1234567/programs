#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
struct point
{
    int x,y,t;
};
long double tt(point a,point b)
{
    long double t1=abs(a.x-b.x), t2=abs(a.y-b.y);
    return sqrt(t1*t1+t2*t2);
}
bool cmp1(point a,point b)
{
    return a.y<b.y;
}
bool cmp2(point a,point b)
{
    return a.x<b.x;
}
int main()
{
    int n;
    cin >> n;
    int u,v;
    long double d=1e18;
    vector<point>p;
    for(int i=1; i<=n; i++) {
        int x,y;
        cin >> x >> y;
        p.push_back({x,y,i});
    }
    sort(p.begin(),p.end(),cmp1);
    for(int i=0; i<n-1; i++) {
        if(tt(p[i],p[i+1])<d) {
            u=p[i].t;
            v=p[i+1].t;
            if(u>v) swap(u,v);
            d=tt(p[i],p[i+1]);
        }
    }
    sort(p.begin(),p.end(),cmp2);
    for(int i=0; i<n-1; i++) {
        if(tt(p[i],p[i+1])<d) {
            u=p[i].t;
            v=p[i+1].t;
            if(u>v) swap(u,v);
            d=tt(p[i],p[i+1]);
        }
    }
    cout << u << " " << v << " " << setprecision(6) << fixed << d;
    return 0;
}
