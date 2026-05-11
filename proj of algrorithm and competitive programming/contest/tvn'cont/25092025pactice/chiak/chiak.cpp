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
using namespace std;
static const int maxd=1003;
typedef short bignum[maxd];
typedef long long ll;
typedef long double ld;
const int maxn=1000006,mod=1000000007;
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
int n,res=0,d=0;
long long a[maxn],k,pre[maxn];
void soup1() {
    int res=0;
    for(int i=1; i<=n; ++i) {
        for(int j=i; j<=n; ++j) {
            if((pre[j]-pre[i-1])%k==0) {
                ++res;
                //cout << i << ' ' << j << '\n';
            }
        }
    }
    cout << res;
}
map<int,int>mp;
int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    file("chiak")
    cin >> n >> k;
    mp[0]=1;
    for(int i=1; i<=n; ++i) {
        cin >> a[i];
        pre[i]=pre[i-1]+a[i];
    }
    long long cur=0;
    for(int i=1; i<=n; ++i) {
        cur=(cur+a[i])%k;
        if(cur<0) cur+=k;
        if(mp.find(cur)!=mp.end()) res+=mp[cur];
        ++mp[cur];
    }
    if(n<=1000) {
        soup1();
        return 0;
    }
    //cout << "\n";
    cout << res;
    //soup1();
    return 0;
}
/*
10 7
-3 1 4 -2 2 -1 6 -5 3 7

20 6
10 7 -3 1 4 -2 2 -1 6 -5 3 7 -4 5 -6 8 -7 9 -8 11
*/