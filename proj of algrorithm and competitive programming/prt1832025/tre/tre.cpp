#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long n,k,m,a[200005];
long long f[200005];
void supc()
{
    cout << n-m;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    freopen("tre.inp", "r", stdin);
    freopen("tre.out", "w", stdout);
    cin >> n >> m >> k;
    for(int i=1; i<=m; i++) cin >> a[i];
    supc();
}
