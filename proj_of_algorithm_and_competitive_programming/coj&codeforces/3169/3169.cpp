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
int n;
long long a[maxn],b[maxn];
map<long long,int>posb;
vector<pair<long long, long long>>ans;
int log2(long long x) {int kq=0;while(x){x>>=1;++kq;}return kq;}

namespace soup1 {
    inline void conv(long long &k, long long &t) {
        int l=20;
        ans.pb({k,k^(1<<14)});
        k^=(1<<14);
        while(k!=t) {
            for(int i=0; i<15; ++i) {
                if((k&(1<<i))!=(t&(1<<i))) {
                    ans.pb({k,(k^(1<<i))});
                    k^=1<<i;
                }
            }
        }
        //ans.pb({k,k^(1<<16)});
        //k^=(1<<16);

    }
    void solve() {
        for(int i=1; i<=n; ++i) {
            //if(a[i]>b[i]) swap(a[i],b[i]);
            conv(a[i],b[i]);
        } 
        cout << ans.size() << "\n";
        for(auto[f,s]:ans) cout << f << ' ' << s << '\n';
    }
}
namespace soupfull {
    const int maxv=(1<<15)+10;
    int inv[maxv];
    bool ok[maxv];
    vector<pair<int,int>>ans;
    set<int>miss,s;
    void move(int i, int num, int j) {
        if(a[i]==num) return;
        for(int b=j; b<15; ++b) {
            if((a[i]&(1<<b))==(num&(1<<b))) continue;
            int z=a[i]^(1<<b);
            if(inv[z]!=0 && inv[z]!=i) move(inv[z],num,b+1);
            int old=a[i];
            ans.eb(old,z);
            inv[old]=0;
            a[i]=z;
            inv[z]=i;
            if(ok[z]) miss.erase(z);
            if(ok[a[i]]) s.erase(i);
            else s.insert(i);
        }
    }
    void solve() {
        for(int i=1; i<=n; ++i) inv[a[i]]=i;
        for(int i=1; i<=n; ++i) ok[b[i]]=true;
        for(int i=1; i<=n; ++i) {
            if(!ok[a[i]]) s.insert(a[i]);
        }
        for(int i=1; i<=n; ++i) if(!inv[b[i]]) miss.insert(b[i]);
        while(!s.empty()) {
            int i=*s.begin(),t=*miss.begin();
            move(i,t,0);
            miss.erase(t);
            s.erase(i);

        }
        cout << ans.size() << '\n';
        for(auto[f,s]:ans) cout << f << ' ' << s << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    //file("3169")
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];
    for(int i=1; i<=n; ++i) cin >> b[i];
    if(*max_element(a+1,a+1+n)<=(1<<14) && *max_element(b+1,b+1+n)<=(1<<14)) soup1::solve();
    else soupfull::solve();
    return 0;
}