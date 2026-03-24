#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
struct point
{
    int x,y;
};
bool used[8];
int n;
int main()
{
    cin >> n;
    int minx=1e9,miny=1e9,maxx=-1e9,maxy=-1e9,minxmy=1e9,maxxmy=-1e9,minxpy=1e9,maxxpy=-1e9;
    memset(used,true,sizeof(used));
    for(int i=1; i<=n; i++) {
        int x,y;
        cin >> x >> y;
        minx=min(minx,x);
        maxx=max(maxx,x);
        miny=min(miny,y);
        maxy=max(maxy,y);
        minxmy=min(minxmy,x-y);
        maxxmy=max(maxxmy,x-y);
        minxpy=min(minxpy,x+y);
        maxxpy=max(maxxpy,x+y);
    }
    point a[8];
    a[0]={miny+maxxmy,miny};
    a[1]={maxx,maxx-maxxmy};
    a[2]={maxx,maxxpy-maxx};
    a[3]={maxxpy-maxy,maxy};
    a[4]={maxy+minxmy,maxy};
    a[5]={minx,minx-minxmy};
    a[6]={minx,minxpy-minx};
    a[7]={minxpy-miny,miny};
    vector<point>res;
    for(int i=1; i<8; i++) {
        if(a[i].x==a[i-1].x and a[i].y==a[i-1].y) used[i]=false;
    }
    if(a[7].x==a[0].x and a[7].y==a[0].y) used[7]=false;
    for(int i=0; i<8;i++) {
        if(used[i]) res.push_back(a[i]);
    }
    cout << res.size() << "\n";
    for(int i=0; i<res.size(); i++) cout << res[i].x << " " << res[i].y << "\n";
}
