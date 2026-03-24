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
const int maxn=5000006,mod=1000000007;
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
long long n,a[maxn],res=0;
string s;
struct hashing {
    const ll mod1=1000000007,mod2=1000000003,base=128;
    long long h1[maxn],h2[maxn],p1[maxn],p2[maxn];
    void init(const string &t, bool type) {
        p1[0]=p2[0]=1;
        for(int i=1; i<=n; ++i) {
            p1[i]=(p1[i-1]*base)%mod1;
            p2[i]=(p2[i-1]*base)%mod2;
        }
        if(!type) {
            for(int i=1; i<=n; ++i) {
                int c=t[i-1];
                h1[i]=(h1[i-1]*base+c)%mod1;
                h2[i]=(h2[i-1]*base+c)%mod2;
            }
        }
        else {
            for(int i=1; i<=n; ++i){
                int c=t[n-i]; 
                h1[i]=(h1[i+1]*base+c)%mod1;
                h2[i]=(h2[i+1]*base+c)%mod2;
            }
        }
    }
    pair<ll,ll>query(int l, int r) {
        long long a=(((h1[r]-h1[l-1]*p1[r-l+1])%mod1)+mod1)%mod1,b=(((h2[r]-h2[l-1]*p2[r-l+1])%mod2)+mod2)%mod2;
        return {a,b};
    }
}ha[2];
void implement() {

}
int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    memset(a,0,sizeof(a));
    cin >> s;
    n=s.size();
    //t=s;
    //reverse(all(t));
    ha[0].init(s,0);
    ha[1].init(s,1);
    for(int i=1; i<=n; ++i) {
        auto q1=ha[0].query(1,i),q2=ha[1].query(1,i);
        if(q1==q2) {
            a[i]=1+a[i/2];
            res+=a[i];
        }
    }
    cout << res;
    return 0;
}