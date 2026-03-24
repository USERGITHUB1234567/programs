#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const long long mod=998244353;
long long q,k,f[10003];
void upd(char c, long long x)
{
    if(c=='+') {
        //cout << f[5] << " " << f[2] << " " << f[5]*f[2] << "\n";
        for(int i=k; i>=x; i--) {
            f[i]=(f[i]+f[i-x])%mod;
        }
    }
    else {
        for(int i=x; i<=k; i++){
            f[i]=(f[i]+mod-f[i-x])%mod;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    freopen("sum.inp", "r", stdin);
    freopen("sum.out", "w", stdout);
    memset(f,0,sizeof(f));
    cin >> q >> k;
    f[0]=1;
    while(q--) {
        char c;
        long long x;
        cin >> c >> x;
        upd(c,x);
        cout << f[k] << "\n";
    }
}
