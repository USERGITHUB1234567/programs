#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int maxn=102,mod=1e9+7;
long long n,k,x,t[maxn];
void soup1()
{
    long long h=1,ans=0;
    for(int i=1; i<=n; i++) {
        if(h>t[i]) {
            ans+=h-t[i];
        }
        else h=t[i];
        h+=x;
    }
    cout << ans;
}
long long f[maxn];
void soup2()
{
    for(int i=0; i<maxn; i++) f[i]=4e18;
    f[0]=0;
    int nn=*max_element(t+1,t+1+n);
    for(long long i=1; i<=nn; i++) {
        int ti=0;
        int j=0;
        for(j; j<=n; j++) {
            if(t[j]>i) break;
        }
        j--;
        for(j; j>=max(0LL,i-k); j--) {
            ti+=abs(i-t[j]);
            f[i]=min(f[i],f[j-1]+ti);
        }
    }
    cout << f[n] << "\n";
}
void souplo()
{
    cout << 0;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> k >> x;
    for(int i=1; i<=n; i++) cin >> t[i];
    if(n==1) {
        cout << 0;
        return 0;
    }
    if(k==1) {
        soup1();
        return 0;
    }
    if(*max_element(t+1,t+1+n)<=1000) {
        soup2();
        return 0;
    }
}
