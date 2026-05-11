#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#define int long long
using namespace std;
int n,k,s,c1,c2,m,a[10000007];
signed main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> k >> s >> c1 >> c2 >> m;
    a[1]=s;
    for(int i=2; i<=n; i++) {
        a[i]=c1*a[i-1]+c2;
        a[i]%=m;
    }
    sort(a+1,a+1+n);
    for(int i=1; i<=k; i++) cout << a[i] << (i<k? " " : "\n");
}