#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n,k,f[2003];
int main()
{
    cin >> n >> k;
    for(int i=1; i<=n; i++) cin >> f[i];
    sort(f+1,f+1+n,greater<int>());
    int ans=0;
    for(int i=1; i<=n; i+=k) ans+=(f[i]-1)*2;
    cout << ans;
}
