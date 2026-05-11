#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
struct point
{
    int x,y;
};
struct vec
{
    double x,y;
};
int crpd(vec a, vec b)
{
    return a.x*b.y-a.y*b.x;
}
int side(point a, point b, point c)
{
    vec ab={b.x-a.x,b.y-a.y}, ac={c.x-a.x,c.y-a.y};
    double s=crpd(ab,ac);
    if(s>0) return 1;
    if(s<0) return -1;
    return 0;
}
double dis(point a, point b)
{
    int t1=abs(a.x-b.x),t2=abs(a.y-b.y);
    return sqrt(t1*t1+t2*t2);
}
int main()
{
    int x,y,kq=0;
    double r;
    cin >> x >> y >> r;
    point g={x,y};
    int n;
    cin >> n;
    vector<point>pv;
    for(int i=1; i<=n; i++) {
        point a;
        cin >> a.x >> a.y;
        if(dis(g,a)<=r) pv.push_back(a);
    }
    for(int i=0; i<pv.size(); i++) {
        for(int j=i+1; j<pv.size(); j++) {
            int d=0;
            int s=side(g,pv[i],pv[j]);
            for(int k=0; k<pv.size(); k++) {
                if(k!=i and k!=j) {
                    if(side(pv[i],pv[j],pv[k])!=s or side(pv[i],pv[j],pv[k])==0) d++;
                }
            }
            kq=max(d+2,kq);
        }
    }
    cout << kq;
    return 0;
}
