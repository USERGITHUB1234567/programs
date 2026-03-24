/**/
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
#define all(x) x.begin(), x.end()
#define sortunique(x) sort(all(x)); x.erase(unique(all(x)), x.end());
#define forw(i,a,b) for(int (i)=(a); (i)<=(b); ++(i))
#define forb(i,a,b) for(int (i)=(a); (i)>=(b); --(i))
#define eb emplace_back
#define fi first
#define se second
#define pb push_back
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
void setUpFactor() {
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
int n,b,r,w,d[maxn],t[maxn];
namespace soup1{
    inline long long f(unordered_map<int,int>&ump) {
        int sum=0;
        for(auto[u,v]:ump) sum+=v;
        long long ans=w*sum;
        for(int i=1; i<=b; ++i) {
            if(sum==0) break;
            ans+=d[i];
            if(ump[i]) {
                ans+=sum*w;
                int pas=ump[i];
                sum-=pas;
                ans+=sum*w;
            }
            
        }
        return ans;
    }
    inline void solve() {
        int fm=1<<n;
        long long ans=LLONG_MAX;
        unordered_map<int,int>ump;
        for(int mask=1; mask<fm; ++mask) {
            long long cnt=0;
            int l=0;
            if(!((1<<(n-1))&mask)) continue;
            if((1<<n)&mask) continue;
            for(int i=0; i<n; ++i) {
                if((1<<i)&mask) {
                    ++ump[t[i+1]];
                    long long temp=l*r+f(ump);
                    cnt=max(cnt,temp);
                    ump.clear();
                    ++l;
                    //cout << temp << ' ';
                }
                else ++ump[t[i+1]];
            }
            //cout << mask << ' ' << cnt << '\n';
            ans=min(ans,cnt);
        }
        /* ump[1]=1;ump[2]=1;ump[3]=1;
        cout << f(ump) << ' '; */
        cout << ans;
    }
}
namespace soup2{
    long long f[maxn];
    inline long long get_time(unordered_map<int,int>&ump) {
        int sum=0;
        for(auto[u,v]:ump) sum+=v;
        long long ans=w*sum;
        for(int i=1; i<=b; ++i) {
            if(sum==0) break;
            ans+=d[i];
            if(ump[i]) {
                ans+=sum*w;
                int pas=ump[i];
                sum-=pas;
                ans+=sum*w;
            }
            
        }
        return ans;
    }
    void solve() {
        for(int i=1; i<=n; ++i) {
            
        }
    }
}
int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    file("bus")
    cin >> n >> b >> r >> w;
    for(int i=1; i<=b; ++i) cin >> d[i];
    for(int i=1; i<=n; ++i) cin >> t[i];
    soup1::solve();
    return 0;
}
/*
3 3 20 1
2 2 2
2 3 1

4 2 1 10
3 2
1 2 2 1

5 3 3 3
2 2 1
3 3 2 1 1
*/
/**/