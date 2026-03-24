#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    freopen("squ.inp", "r", stdin);
    freopen("squ.out", "w", stdout);
    map<int,int>mp;
    int kq=1;
    for(int i=1; i<=4; i++) {
        int x,y;
        cin >> x >> y;
        if(mp[x]!=0) {
            kq*=mp[x]-y;
        }
        else mp[x]+=y;
        if(kq<0) kq=-kq;
    }
    cout << kq;
    return 0;
}
