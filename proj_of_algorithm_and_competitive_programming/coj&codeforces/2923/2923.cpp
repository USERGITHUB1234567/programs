#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n,c=0,kq=0;
pair<int,int>p[200005];
bool cmp(pair<int,int>a, pair<int,int> b)
{
    return a.second<b.second;
}
int main()
{
    cin >> n;
    for(int i=1; i<=n; i++) cin >> p[i].first >> p[i].second;
    sort(p+1,p+1+n,cmp);
    p[0].second=-1000;
    for(int i=1; i<=n; i++) {
        if(p[i].first>=p[c].second) {
            c=i;
            kq++;
        }
    }
    cout << kq;
}
