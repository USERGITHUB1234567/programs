#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    freopen("dri.inp", "r", stdin);
    freopen("dri.out", "w", stdout);
    long long n,k,kq=0,l=0;
    cin >> n >> k;
    map<long long,long long>mp;
    for(int i=0; i<k; i++) {
        long long x,y;
        cin >> x >> y;
        mp[x]+=y;
    }
    for(auto x:mp) {
        kq+=x.second;
        l++;
        if(l>=n) break;
    }
    cout << kq;
    return 0;
}
