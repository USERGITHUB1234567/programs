#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const long long mod=1000000007,maxn=100005;
long long n,k,a[maxn],ft[20][maxn];
long long sum(int l, int i)
{
    long long s=0;
    while(i>0) {
        s+=ft[l][i];
        s%=mod;
        i-=i&-i;
    }
    return s;
}
void upd(int l, int i, long long v)
{
    while(i<=n) {
        ft[l][i]+=v;
        ft[l][i]%=mod;
        i+=i&-i;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> k;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++) {
        for(int l=k+1; l>=1; l--) {
            int ca;
            if(l==1) ca=1;
            else {
                ca=sum(l-1,a[i]-1);
            }
            upd(l,a[i],ca);
        }
    }
    cout << sum(k+1,n);
}
