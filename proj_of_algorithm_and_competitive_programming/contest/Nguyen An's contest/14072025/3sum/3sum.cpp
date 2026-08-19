#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
#define mkp make_pair
#define eb emplace_back
#define fi first
#define se second
#define int long long
using namespace std;
typedef long long ll;
const int maxn=5003;
int n,q,a[maxn],pre[maxn][maxn],ans[maxn][maxn],num[maxn][maxn];
void souplo()
{
    while(q--){
        int l, r;
        cin >> l >> r;
        ll cnt=0;
        for(int i=l; i<=r; i++){
            for(int j=i+1; j<=r; j++){
                for(int k=j+1; k<=r; k++){
                    if(a[i]+a[j]+a[k]==0)
                        cnt++;
                    }
                }
            }
            cout << cnt << "\n";
        }

}
void soup2()
{
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; i++) {
            pre[i][j]=a[i]+a[j];
        }
    }
    while(q--) {

    }
}
void soup3()
{
    for(int r=1; r<=n; r++) {
        map<int,int>cnt;
        for(int l=r-1; l>=1; l--) {
            num[l][r]=cnt[-a[l]-a[r]];
            cnt[a[l]]++;
        }
    }
    for(int l=n; l>=1; l--) {
        for(int r=l+2; r<=n; r++) {
            ans[l][r]=ans[l+1][r]+ans[l][r-1]-ans[l+1][r-1]+num[l][r];
        }
    }
    while(q--) {
        int l,r;
        cin >> l >> r;
        cout << (r-l<2?0:ans[l][r]) << "\n";
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> q;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
    }
    soup3();
}
