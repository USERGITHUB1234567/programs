#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n,l,r,t,ph;
pair<int,char>p[100005];
int main()
{
    cin >> n;
    for(int i=1; i<=n; i++) cin >> p[i].first >> p[i].second;
    for(int i=1; i<=n; i++) {
        if(p[i].second=='L') {
            l=p[i].first;
            break;
        }
    }
    for(int i=1; i<=n;i++) {
        if(p[i].second=='R') {
            r=p[i].first;
            break;
        }
    }
    for(int i=1; i<=n; i++) {
        if(p[i].second=='L') {
            t+=abs(l-p[i].first);
            l=p[i].first;
        }
        else {
            ph+=abs(r-p[i].first);
            r=p[i].first;
        }
    }
    cout << t+ph;
}
