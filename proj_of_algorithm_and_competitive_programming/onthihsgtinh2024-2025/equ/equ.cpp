#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    freopen("equ.inp", "r", stdin);
    freopen("equ.out", "w", stdout);
    long long n,m=0;
    cin >> n;
    long long a[n];
    map<long long,long long>mp;
    for(int i=0; i<n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    for(auto x : mp) {
        m=max(m,x.second);
    }
    cout << n-m;
}
