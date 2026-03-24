#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
#define foutput(name) freopen(name, "w", stdout);
#define finput(name) freopen(name,"r", stdin);
#define all(x) x.begin(), x.end()
#define sortunique(x) sort(all(x)); x.erase(unique(all(x)), x.end());
#define forw(i,a,b) for(int (i)=(a); (i)<=(b); ++(i))
#define forb(i,a,b) for(int (i)=(a); (i)>=(b); --(i))
#define eb emplace_back
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
static const int maxd=1003;
typedef short bignum[maxd];
typedef long long ll;
typedef long double ld;
const int maxn=100005,mod=1000000007;
long long fact[maxn],ifact[maxn];
inline int maxi(int a, int b) {return (a>b?a:b);}
inline int mini(int a, int b) {return (a<b?a:b);}
inline ll maxill(ll a, ll b) {return (a>b?a:b);}
inline ll minill(ll a, ll b) {return (a<b?a:b);}
inline double maxid(double a, double b) {return (a>b?a:b);}
inline double minid(double a, double b) {return (a<b?a:b);}
inline ld maxild(ld a, ld b) {return (a>b?a:b);}
inline ld minild(ld a, ld b) {return (a<b?a:b);}
inline ll modexp(ll b, ll e, ll m) {
    ll res=1%m;
    while(e>0) {
        if(e&1) res=(res*b)%m;
        b=(b*b)%m;
        e>>=1;
    }
    return res;
}
inline ll log(ll k, ll n){ll res=0;while(n>0){n/=k;++res;}return res;}
void setupfactor() {
    fact[0]=1;
    for(int i=1; i<maxn; ++i) fact[i]=fact[i-1]*i%mod;
    int tc=maxn-1;
    ifact[tc]=modexp(fact[tc],mod-2,mod);
    for(int i=tc; i>=1; --i) ifact[i-1]=ifact[i]*i%mod; 
}
inline long long ncr(long long k, long long n) {return (k==n?1:fact[n]*ifact[n-k]%mod*ifact[k]%mod);}
mt19937_64 generator1(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 generator2(chrono::high_resolution_clock::now().time_since_epoch().count());
inline long long rnd1(long long a, long long b) {return a+generator1()%(b-a+1);}
inline long long rnd2(long long a, long long b) {return a+generator2()%(b-a+1);}
const int d='d'-'a',k='k'-'a',o='o'-'a',r='r'-'a';
int n,m,cnt[30],ex=0;
string s;
vector<int>ans;
namespace soup1 {
    void solve() {
        sort(all(ans),greater<int>());
        for(int i=0; i<ans.size(); ++i) {
            if(!i) ex+=(ans[i]+m)*(ans[i]+m);
            else ex+=ans[i]*ans[i];
            //printf("%d ",ans[i]);
            //printf("%d ",ex);
        }
        printf("%d",ex);
    }
}
namespace soup2 {
    int kq=0,d1=0,d2=0,d3=0,d4=0;
    void solve() {
        for(int i=0; i<ans.size(); ++i) {
            if(!i) {
                ans[i]+=m;
                d1+=(ans[i])*(ans[i]);
                ex=7*min({ans[0],ans[1]/2,ans[2]/2,ans[3]});
                ans[i]-=m;
            }
            else d1+=ans[i]*ans[i];
            //printf("%d ",ans[i]);
            //printf("%d ",ex);
        }
        kq=max(kq,ex+d1);
        for(int i=0; i<ans.size(); ++i) {
            if(i==1) {
                ans[i]+=m;
                d2+=(ans[i])*(ans[i]);
                ex=7*min({ans[0],ans[1]/2,ans[2]/2,ans[3]});
                ans[i]-=m;
            }
            else d2+=ans[i]*ans[i];
            //printf("%d ",ans[i]);
            //printf("%d ",ex);
        }
        kq=max(kq,ex+d2);
        for(int i=0; i<ans.size(); ++i) {
            if(i==2) {
                ans[i]+=m;
                d3+=(ans[i])*(ans[i]);
                ex=7*min({ans[0],ans[1]/2,ans[2]/2,ans[3]});
                ans[i]-=m;
            }
            else d3+=ans[i]*ans[i];
            //printf("%d ",ans[i]);
            //printf("%d ",ex);
        }
        kq=max(kq,ex+d3);
        for(int i=0; i<ans.size(); ++i) {
            if(i==3) {
                ans[i]+=m;
                d4+=(ans[i])*(ans[i]);
                ex=7*min({ans[0],ans[1]/2,ans[2]/2,ans[3]});
                ans[i]-=m;
            }
            else d4+=ans[i]*ans[i];
            //printf("%d ",ans[i]);
            //printf("%d ",ex);
        }
        kq=max(kq,ex+d4);
        printf("%d",kq);
    }
}
namespace soup3 {
    int kq=0,ex[5];
    inline int cal(vector<int>&pr) {
        int res=0;
        for(int i=0; i<4; ++i) res+=pr[i]*pr[i];
        return res+7*min({pr[0],pr[1]/2,pr[2]/2,pr[3]});
    }
    inline void dfs(int u, int r) {
        if(u==4) {
            for(int i=0; i<4; ++i) {ans[i]+=ex[i];}
            kq=max(kq,cal(ans));
            for(int i=0; i<4; ++i) ans[i]-=ex[i];
            //printf("%d\n",kq);
            return;
        }
        for(int i=0; i<=r; ++i) {
            ex[u]+=i;
            dfs(u+1,r-i);
            ex[u]-=i;
        }
    }
    void solve() {
        dfs(0,m);
        printf("%d",kq);
    }
}
int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    file("krokod")
    scanf("%d%d",&n,&m);cin >> s;
    //cout << s;
    for(char c:s) ++cnt[c-'a'];
    ans.pb(cnt[d]);ans.pb(cnt[k]);ans.pb(cnt[o]);ans.pb(cnt[r]);
    ex=7*min({cnt[k]/2,cnt[r],cnt[o]/2,cnt[d]});
    //printf("%d ",ex);
    /*for(int i=0; i<ans.size(); ++i) {
        if(!i) ex+=(ans[i]+m)*(ans[i]+m);
        else ex+=ans[i]*ans[i];
        //printf("%d ",ans[i]);
        //printf("%d ",ex);
    }
    printf("%d",ex);*/
    if(!m) soup1::solve();
    else if(m==1) soup2::solve();
    else soup3::solve();
    //soup3::solve();
    return 0;
}
/*
15 0
krokodkrokodkrk

5 1
rokod

8 2
ddkkoorr
*/
