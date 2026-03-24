#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
#define mkp make_pair
#define eb emplace_back
#define fi first
#define se second
#define int long long
using namespace std;
const int maxn=100005,mod=1000000007;
int h[maxn],w[maxn],n,grid[51][51],presub1[51][51];
int c2(int x) {
    x%=mod;
    return x*((x+1)%mod)%mod*((mod+1)/2)%mod;
}
int cal(int n, int m)
{
    return c2(n)*c2(m)%mod;
}
void soup1()
{
    int kq=0;
    for (int l=1; l<=n; l++){
        int mih=LLONG_MAX;
        for (int r=l; r<=n; r++){
            mih=min(mih,h[r]);
            int cnt=c2(mih);
            kq=(kq+cnt)%mod;
        }
    }
    cout << kq << "\n";
}
void soup2()
{
    int tw=0,ans=0;
    for(int i=1; i<=n; i++) {

        if(h[i]==1) {
            tw+=w[i];
            continue;
        }
        else {
            int temp=0;
            while(h[i]==2) {
                temp+=w[i];
                tw+=w[i];
                i++;

            }
            i--;
            ans=(ans+(c2(temp)*h[i])%mod)%mod;
        }
    }
    int ch=*min_element(h+1,h+1+n);
    ans=(ans+(c2(tw)))%mod;
    cout << ans;
}
void soup3() {
    int ch=h[1];
    int tw=0;
    for (int i=1; i<=n; i++) {
        tw=(tw+w[i])%mod;
    }
    int ans=cal(ch,tw);
    cout << ans;
}
void soup4()
{

}
void soup5()
{

}
void soup6()
{

}
signed main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cin >> n;
    bool ck=true;
    for (int i=1; i<=n; i++) cin >> h[i];
    for (int i=1; i<=n; i++) cin >> w[i];
    for(int i=2; i<=n; i++) {
        if(h[i]!=h[i-1]) {
            ck=false;
            break;
        }
    }
    if(n<=50 && *max_element(w+1,w+1+n)==1) {
        soup1();
        return 0;
    }
    else if(*max_element(h+1,h+1+n)<=2) {
        soup2();
        return 0;
    }
    else if(ck) {
        soup3();
        return 0;
    }
    return 0;
}
