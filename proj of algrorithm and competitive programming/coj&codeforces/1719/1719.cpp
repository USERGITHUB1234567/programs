#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n,re=1e9;
struct point
{
    int x,y;
}p[302];
int dist(point a, point b)
{
    int t1=abs(a.x-b.x),t2=abs(a.y-b.y);
    return abs(t1*t1+t2*t2);
}
int cal(int s)
{
    int kq=0;
    bool vis[n+1];
    memset(vis,false,sizeof(vis));
    vis[s]=true;
    for(int i=2; i<=n; i++) {
        int mi=1e9,t;
        for(int j=1; j<=n; j++) {
            if(j==s) continue;
            if(dist(p[s],p[j])<mi && !vis[j]) {
                t=j;
                mi=dist(p[s],p[j]);
            }
        }
        kq+=mi;
        s=t;
        vis[s]=true;
    }
    return kq;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n;
    for(int i=1; i<=n; i++) cin >> p[i].x >> p[i].y;
    for(int i=1; i<=n; i++) {
        re=min(re,cal(i));
    }
    cout << re;
}
