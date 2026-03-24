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
const int maxn=100005,mod=1000000007,maxb=320;
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
int task;
string s;
inline void task1() {
    int cnt_2025=0,cnt_2026=0;
    //string s2025="2025",s2026="2026";
    for(int i=0; i<=s.size()-4; ++i) {
        string t=s.substr(i,4);
        //cout << t << "\n";
        if(t=="2025") ++cnt_2025;
        else if(t=="2026") ++cnt_2026;
    }
    //cout << cnt_2025 << " " << cnt_2026;
    cout << (cnt_2026>cnt_2025?"YES":"NO");
}

struct fenwick_tree{
    static const int n=maxn<<1;
    int ft[n];
    fenwick_tree() {for(int i=0; i<n; ++i) ft[i]=0;}
    inline int sum(int i) {
        int res=0;
        while(i>0) {
            res+=ft[i];
            i-=i&-i;
        }
        return res;
    }
    inline void update(int i, int v) {
        while(i<n) {
            ft[i]+=v;
            i+=i&-i;
        }
    }
}fen;
namespace task2{
    int pre[maxn];
    inline void solve() {
        s="*"+s;
        long long ans=0;
        // for(int i=4; i<s.size(); ++i) {
        //     string t=s.substr(i-3,4);
        //     pre[i]=pre[i-1];
        //     if(t=="2025") --pre[i];
        //     else if(t=="2026") ++pre[i];
        // }
        // vector<int>comp;
        // for(int i=1; i<s.size(); ++i) comp.pb(pre[i]);
        // sortunique(comp);
        // fen.update(1,1);
        // auto idx=[&](int x) {return int(lower_bound(all(comp),x)-comp.begin()+1);};
        // for(int i=4; i<s.size(); ++i) {
        //     int id=idx(pre[i]);
        //     ans+=fen.sum(id-1);
        //     ans%=mod;
        //     fen.update(id,1);
        // }
        // cout << ans;
        int m=s.size()-3;
        for(int i=1; i<=m; ++i) {
            pre[i]=pre[i-1];
            string t=s.substr(i-1,4);
            if(t=="2026") ++pre[i];
            else if(t=="2025") --pre[i];
        }
        vector<int>comp;
        for(int i=1; i<=m; ++i) comp.pb(pre[i]);
        sortunique(comp);
        auto idx=[&](int x) {return int(lower_bound(all(comp),x)-comp.begin()+1);};
        for(int i=1; i<=m; ++i) {
            int id=idx(pre[i]);
            if(i<=1) continue;
            ans+=fen.sum(id-1);
            ans%=mod;
            fen.update(id,1);
        }
        cout << ans;
    }
}
int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> task >> s;
    if(task==1) task1();
    else task2::solve();
    return 0;
}