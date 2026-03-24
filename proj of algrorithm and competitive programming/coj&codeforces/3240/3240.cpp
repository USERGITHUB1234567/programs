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
const int maxn=200005,mod=1000000007,maxb=320;
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
inline ll logarit(ll k, ll n){ll res=0;while(n>0){n/=k;++res;}return res;}
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
const int block_size=450;
int n,q,p[maxn],l[maxn],r[maxn];
struct fenwick_tree{
    long long ft[maxn];
    inline void reset() {for(int i=1; i<=n; ++i) ft[i]=0;}
    inline void update(int i, long long v) {
        while(i<=n) {
            ft[i]+=v;
            i+=i&-i;
        }
    }
    inline long long query(int i) {
        long long res=0;
        while(i>0) {
            res+=ft[i];
            i-=i&-i;
        }
        return res;
    }
}fen;
vector<int>trace[maxn];
pair<int,int>qu[maxn];
int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> q;
    for(int i=1; i<=n; ++i) {cin >> p[i];trace[p[i]].pb(i);}
    for(int i=1; i<=q; ++i) {
        cin >> qu[i].fi >> qu[i].se;
        l[i]=1,r[i]=qu[i].se-qu[i].fi+1;
    }
    // for(int i=1; i<=7; ++i) {
    //     for(int j:trace[i]) cout << j << ' ';
    //     cout << '\n';
    // }
    while(true) {
        bool stop=true;
        vector<vector<int>>bucket(maxn);
        for(int i=1; i<=q; ++i) {
            if(l[i]<r[i]) {
                stop=false;
                bucket[(l[i]+r[i]+1)>>1].pb(i);
            }
        }
        if(stop) break;
        fen.reset();
        for(int post=maxn-1; post>=1; --post) {
            //if(trace[post].empty() || bucket[post].empty()) continue;
            for(int v:trace[post]) {fen.update(v,1);}
            for(int i:bucket[post]) {
                auto[x,y]=qu[i];
                int s=fen.query(y)-fen.query(x-1);
                //cout << s << '\n';
                if(s>=post) l[i]=post;
                else r[i]=post-1;
            }
        }
    }
    //for(int i=1; i<=n; ++i) fen.update(i,1);
    for(int i=1; i<=q; ++i) {
        cout << l[i] << '\n';
    }
    return 0;
}
/*
6
1
3
2
4
5
2
4
5

2
1
1
0
2
2
2
5
4
4
3
1
3
3
1
2
2
*/