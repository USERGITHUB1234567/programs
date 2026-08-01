#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
#define mkp make_pair
#define eb emplace_back
#define fi first
#define se second
#define int long long
using namespace std;
typedef long long ll;
const int maxn=100005,mod=1000000007;
int n,p2[2*maxn],ft[2*maxn],pre[2*maxn];
pair<int,int>p[maxn];
void upd(int i, int v)
{
    while(i<=n) {
        ft[i]+=v;
        i+=i&-i;
    }
}
int sum(int i)
{
    int ans=0;
    while(i>0) {
        ans+=ft[i];
        i-=i&-i;
    }
    return ans;
}
int modexp(int b, int e)
{
    int re=1;
    while(e>0) {
        if(e&1) {
            re=(re*b)%mod;
        }
        b=(b*b)%mod;
        e>>=1;
    }
    return re;
}
void soup1()
{
    int kq=0;
    for(int i=0; i<(1<<n); i++) {
        int r=0,pr=0;
        vector<pair<int,int>>v;
        for(int j=0; j<n; j++) {
            if(i&(1<<j)) {
                v.push_back(p[j+1]);
            }
        }
        for(int j=0; j<v.size(); j++) {
            if(v[j].fi>r) pr++;
            r=max(r,v[j].se);
        }
        kq+=pr;
    }
    cout << kq;
}
void soup2()
{
    /*int r=0,kq=0,d=0;
    vector<int>pre;
    for(int i=1; i<=n; i++) {
        if(v[j].fi>r) {
            if(d!=0) pre.push_back(d);
            d=0;
        }
        else {
            d++;
        }
        r=max(r,v[i].se);
    }
    pre.push_back(d);
    kq=modexp(2,(int)pre.size());
    for(int i=0; i<pre.size(); i++) {

    }
    p2[0]=1;
    for(int i=1; i<=2*n; i++) {
        p2[i]=(p2[i-1]<<1)&mod;
    }*/
    int ans=0;
    for(int i=1; i<=n; i++) {
        int l=p[i].fi;
        int cnt=0;
        for(int j=1; j<i; j++){
            if(p[j].se<l) cnt++;
        }
        int exp=cnt+(n-i);
        ans=(ans+modexp(2,exp))%mod;
    }
    cout << ans;
}
void soup3()
{
    int ans=0;
    //for(int i=1; i<=n; i++) upd(p[i].se,1);
    int pos=0;
    vector<int>v;
    for(int i=1; i<=n; i++) {
        v.push_back(p[i].se);
    }
    sort(v.begin(),v.end());
    for(int i=1; i<=2*n; i++) {
        if(i==v[pos]) {
            pre[i]=pre[i-1]+1;
            pos++;
        }
        else pre[i]=pre[i-1];
    }
    for(int i=1; i<=n; i++) {
        int l=p[i].fi,r=p[i].se,cnt=pre[l-1],exp=cnt+(n-i);
        ans=(ans+modexp(2,exp))%mod;

    }
    cout << ans;
}
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n;
    for(int i=1; i<=n; i++) cin >> p[i].fi >> p[i].se;
    sort(p+1,p+1+n);
    if(n<=16) {
        soup1();
        return 0;
    }
    if(n<=1000) {
        soup2();
        return 0;
    }
    soup3();
    return 0;
}
