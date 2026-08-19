#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    long long n,m,t=2,d=1e18;
    cin >> n >> m;
    long long b[n];
    pair<long long,long long> a[n];
    for(int i=0; i<n; i++) {
        cin >> a[i].first >> a[i].second;
        d=min(d,a[i].first+a[i].second);
    }
    while(true) {

    }
}
