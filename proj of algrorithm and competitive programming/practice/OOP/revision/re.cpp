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
using namespace std::chrono;
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
mt19937_64 generator1(steady_clock::now().time_since_epoch().count());
mt19937_64 generator2(high_resolution_clock::now().time_since_epoch().count());
inline long long rnd1(long long a, long long b) {return a+generator1()%(b-a+1);}
inline long long rnd2(long long a, long long b) {return a+generator2()%(b-a+1);}
auto imp_st=high_resolution_clock::now();
inline void start_timer() {imp_st=high_resolution_clock::now();}
inline void get_execution_time() {
    auto imp_en=high_resolution_clock::now();
    cerr << "Implementation Time: "<< duration_cast<milliseconds>(imp_en-imp_st).count() << " ms\n";
}

class asset{
public:
    virtual void change(ld v)=0;
    virtual long double valuation()=0;
    virtual ~asset()=default;
};
class gold:public asset{
long double val=0;
public:
    void change(ld v) override{val+=v;}
    long double valuation() override{return val;}
};
class share:public asset{
long double val=0;
public:
    void change(ld v) override{val+=v;}
    long double valuation() override{return val;}
};
class cash:public asset{
long double val=0;
public:
    void change(ld v) override{val+=v;}
    long double valuation() override{return val;}
};
vector<asset*>a;
inline void report() {
    long double t=0;
    for(asset*as:a) {
        t+=as->valuation();
    }
    cout << "total value:" << t << '\n';
}
int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int q;string type;
    cin >> q;
    while(q--) {
        cin >> type;
        if(type=="gold") {asset* as=new gold();a.pb(as);}
        else if(type=="share") {asset* as=new share();a.pb(as);}
        else {asset* as=new cash();a.pb(as);}
    }
    asset* as=a[0];as->change(1.0);
    report();
    return 0;
}