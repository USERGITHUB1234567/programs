#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int m,k;
double re=0;
struct point
{
    double x,y;
};
struct shape
{
    int n,c;
    vector<point>p;
    double are;
}a[1003];
double area(vector<point>v)
{
    double ar=0;
    for(int i=0; i<v.size(); i++) {
        int j=(i+1)%v.size();
        ar+=v[i].x*v[j].y;
        ar-=v[i].y*v[j].x;
    }
    return abs(ar)/2;
}
bool cmp(shape a, shape b)
{
    return a.are<b.are;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    map<int, double>mp;
    cin >> m >> k;
    for(int i=1; i<=m; i++) {
        cin >> a[i].n >> a[i].c;
        for(int j=1; j<=a[i].n; j++) {
            double x,y;
            cin >> x >> y;
            a[i].p.push_back({x,y});

        }
        a[i].are=area(a[i].p);
    }
    sort(a+1,a+1+m,cmp);
    double t=0;
    for(int i=1; i<=m; i++) {
        a[i].are-=t;
        t+=a[i].are;
    }
    for(int i=1; i<=m; i++) {
        mp[a[i].c]+=a[i].are;
    }
    double ma=0;
    int co=-1;
    for(auto x:mp) {
        if(x.second>ma) {
            ma=x.second;
            co=x.first;
        }
    }
    re+=ma;
    for(int i=m; i>=1; i--) {
        if(a[i].c!=co) {
            re+=a[i].are;
            k--;
        }
        if(k==0) break;
    }
    cout << fixed << setprecision(1) << re;
}
