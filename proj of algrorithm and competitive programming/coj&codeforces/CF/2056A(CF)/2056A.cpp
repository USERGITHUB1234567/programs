#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n,m;
        cin >> n >> m;
        int x=0,y=0,curx=0,cury=0;
        pair<int,int>p[n];
        for(int i=0; i<n; i++) cin >> p[i].first >> p[i].second;
        curx=p[0].first;cury=p[0].second;
        int kq=0;
        for(int i=0; i<n; i++) {
            curx+=p[i].first;
            cury+=p[i].second;
            kq+=m*4;
            if(curx<x) kq-=2*abs(x-curx);
            if(cury<y) kq-=2*abs(y-cury);
            x=curx+m;
            y=cury+m;
        }
        cout << kq << "\n";
    }
}
