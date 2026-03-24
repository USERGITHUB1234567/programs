#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
struct point
{
    double x,y;
};
struct vec
{
    double x,y;
};
double crpd(vec a, vec b)
{
    return (a.x*b.y-a.y*b.x);
}
double tdt(vector<point>&a)
{
    double kq=0;
    for(int i=0; i<a.size(); i++) {
            int j=(i+1)%n;
        kq+=(a[i].x*a[j].y)-(a[j].x*a[i].y);
    }
    return abs(kq)/2;
}
int side(point a, point b, point b)
{
    vec ab={b.x-a.x,b.y-a.y},ac={c.x-a.x,c.y-a.y};
    double s=crpd(ab,ac);
    if(s<0) return -1;

}
int n;
point p[1001];
int main()
{
    cin >> n;
    for(int i=1; i<=n; i++) cin >> p[i].x >> p[i].y;
    double k1=0,k2=0;
    double a=a[n].x-a[1].x,b=a[n].y-a[1].y;
    vec n={-b,a};
    double c=-a*p[1].x-b*p[1].y;
    vector<point>la;
    la.push_back(p[1]);
    for(int i=2; i<=n; i++) {
        double al=p[i].x-p[i-1].x,bl=p[i].y-p[i-1].y;
        vec nc={-bl,al};

    }
}
