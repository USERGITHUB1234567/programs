#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
struct point
{
    double x,y;
}p[2003];
int n;
bool cmp(point a, point b)
{
    return (a.x<b.x) || (a.x==b.x && a.y<b.y);
}
double dist(point a, point b)
{
    double t1=abs(a.x-b.x),t2=abs(a.y-b.y);
    return sqrt(t1*t1+t2*t2);
}
bool ck(point a, point b, point c, point d)
{
    vector<point>p;
    p.push_back(a);
    p.push_back(b);
    p.push_back(c);
    p.push_back(d);
    sort(p.begin(),p.end(),cmp);
    if(dist(p[0],p[1])==dist(p[2],p[3])) return true;
    else return false;
}
void sup1()
{
    long long kq=0;
    for(int i=1; i<=n; i++) {
        for(int j=i+1; j<=n; j++) {
            for(int k=j+1; k<=n; k++) {
                for(int t=k+1; t<=n; t++) {
                    if(ck(p[i],p[j],p[k],p[t])) kq++;
                }
            }
        }
    }
    cout << kq;
}
void sup2()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    vector<pair<int,int>>ans;
    long long kq=0, cnt=1;
    for(int i=1;i<=n;i++) {
        for(int j=i+1;j<=n;j++) {
            long long x=p[i].x+p[j].x;
            long long y=p[i].y+p[j].y;
            ans.push_back({x,y});
        }
    }
    sort(ans.begin(),ans.end());
    for(int i=1;i<ans.size();i++)
    {
        long long x=ans[i].first, y=ans[i].second;
        if(x==ans[i-1].first && y==ans[i-1].second)
            cnt++;
        else
        {
            if(cnt>1)
                kq+=cnt*(cnt-1)/2;
            cnt=1;
        }
    }
    if(cnt>1) kq+=cnt*(cnt-1)/2;
    cout << kq;
}
int main()
{
    cin >> n;
    for(int i=1; i<=n; i++) cin >> p[i].x >> p[i].y;
    sup2();
}
