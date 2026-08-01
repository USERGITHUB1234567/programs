#include<bits/stdc++.h>
using namespace std;
long long n, m, a[100001], x, ans=0, mod=1e9+7, f[100001], cnt[100001];
long long S(long long x, long long mod){
    return ((x%mod)*(x%mod))%mod;
}
long long powmod(long long x, long long y, long long mod){
    if(y==0)return 1;
    else if(y%2==0){
        return S(powmod(x, y/2, mod), mod);
    }
    else {
        return (S(powmod(x, y/2, mod), mod)*(x%mod))%mod;
    }
}
void sub2(){
    long long ma=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ma=max(a[i], ma);
    }
    cout<<powmod(2, ma, mod);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    freopen("sch.inp", "r", stdin);
    freopen("sch.out", "w", stdout);
    cin>>n>>m;
    sub2();
    return 0;
}
