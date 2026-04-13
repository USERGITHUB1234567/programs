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
const int maxn=200005,mod=1000000007,maxb=320; 
namespace mathematics{ 
    long long fact[maxn],ifact[maxn]; 
    long long __gcd(long long a, long long b) { if(a<b) swap(a,b); while(a%b!=0) {long long c=a%b;a=b,b=c;} return b; } 
    inline ll __logarit(ll k, ll n){ll res=0;while(n>0){n/=k;++res;}return res;} 
    inline ll modexp(ll b, ll e, ll m) { ll res=1%m; while(e>0) { if(e&1) res=(res*b)%m; b=(b*b)%m; e>>=1; } return res; } 
    inline int maxi(int a, int b) {return (a>b?a:b);} 
    inline int mini(int a, int b) {return (a<b?a:b);} 
    inline ll maxill(ll a, ll b) {return (a>b?a:b);} 
    inline ll minill(ll a, ll b) {return (a<b?a:b);} 
    inline double maxid(double a, double b) {return (a>b?a:b);} 
    inline double minid(double a, double b) {return (a<b?a:b);} 
    inline ld maxild(ld a, ld b) {return (a>b?a:b);} 
    inline ld minild(ld a, ld b) {return (a<b?a:b);} 
    void setUpFactor() { fact[0]=1; for(int i=1; i<maxn; ++i) fact[i]=fact[i-1]*i%mod; int tc=maxn-1; ifact[tc]=modexp(fact[tc],mod-2,mod); for(int i=tc; i>=1; --i) ifact[i-1]=ifact[i]*i%mod; } 
    inline long long ncr(long long k, long long n) {return (k==n?1:fact[n]*ifact[n-k]%mod*ifact[k]%mod);} 
} 
using namespace mathematics; 
mt19937_64 generator1(steady_clock::now().time_since_epoch().count()); 
mt19937_64 generator2(high_resolution_clock::now().time_since_epoch().count()); 
inline long long rnd1(long long a, long long b) {return a+generator1()%(b-a+1);} 
inline long long rnd2(long long a, long long b) {return a+generator2()%(b-a+1);} 
auto imp_st=high_resolution_clock::now(); 
inline void start_timer() {imp_st=high_resolution_clock::now();} 
inline void get_execution_time() { auto imp_en=high_resolution_clock::now(); cerr << "Implementation Time: "<< duration_cast<milliseconds>(imp_en-imp_st).count() << " ms\n"; } 
int n,k;
vector<pair<int,long long>>adj[maxn];
namespace soup1{
    long long d[maxn];
    inline void dijkstra(vector<int>st) {
        for(int i=1; i<=n; ++i) d[i]=LLONG_MAX;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i:st) {
            d[i]=0;
            pq.push({0,i});
        }
        while(!pq.empty()) {
            auto[cd,u]=pq.top();pq.pop();
            if(cd>d[u]) continue;
            for(auto[v,w]:adj[u]) {
                if(d[v]>d[u]+w) {
                    d[v]=d[u]+w;
                    pq.push({d[v],v});
                }
            }
        }
    }
    void solve() {
        int fm=(1<<n);
        vector<int>ans;long long kq=LLONG_MAX;
        for(int mask=1; mask<fm; ++mask) {
            if(__builtin_popcount(mask)!=k) continue;
            vector<int>v;
            for(int i=0; i<n; ++i) {
                if((1<<i)&mask) v.pb(i+1);
            }
            dijkstra(v);
            long long tmp=0;
            for(int i=1; i<=n; ++i) tmp=max(tmp,d[i]);
            if(tmp<kq) {kq=tmp;ans=v;}
        }
        cout << kq << '\n';
        for(int i:ans) cout << i << ' ';
    }
}
namespace soup2{
    vector<pair<long long,long long>>mxd[maxn];
    long long d[maxn];
    void dijkstra(int st) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=1; i<=n; ++i) d[i]=LLONG_MAX;
        d[st]=0;
        pq.push({0,st});
        while(!pq.empty()) {
            auto[cd,u]=pq.top();pq.pop();
            for(auto [v,w]:adj[u]) {
                if(d[v]>d[u]+w) {d[v]=d[u]+w;pq.push({d[v],v});}
            }
        }
    }
    inline long long mxcd(vector<pair<long long,long long>>v) {sort(all(v));return (v.empty()?0:v[0].fi);}
    inline long long mxquery(vector<pair<long long,long long>>v,long long cd) {return (v.size()<1?0:(v[0].se==cd?v[1].fi:v[0].fi));}
    inline long long dfsinit(int u, int p) {
        long long tw;
        for(auto[v,w]:adj[u]) {
            if(v==p) {tw=w;continue;}
            mxd[u].pb({dfsinit(v,u),v});
        }
        long long cd=mxcd(mxd[u]);
        return cd+tw;
    }
    long long ans=LLONG_MAX,res;
    inline void dfs(int u, int p, long long t) {
        //t=max(t,mxcd(mxd[u]));
        long long tmp=max(t,mxcd(mxd[u]));
        if(tmp<ans) {
            ans=tmp;
            res=u;
        }
        for(auto[v,w]:adj[u]) {
            t=mxquery(mxd[u],v);
            dfs(v,u,t+w);
        }
    }
    void solve() {
        dijkstra(1);
        dfsinit(1,0);
        dfs(1,0,0);
        cout << ans << '\n' << res;
    }
}
int main(int argc, char** argv) { 
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); 
    file("park")
    cin >> n >> k;
    for(int i=1,a,b,w; i<n; ++i) {cin >> a >> b >> w;adj[a].pb({b,w});adj[b].pb({a,w});}
    if(n<=23) soup1::solve();
    // cout << '\n';
    // soup2::solve();
    return 0; 

} 
/**/
/*
9 3
1 2 5
1 3 1
3 4 10
3 5 9
5 6 8
2 7 1
2 8 2
8 9 7

5 2
1 2 3
2 3 7
3 4 3
4 5 3

7 4
1 3 1
1 4 1
2 3 1
5 3 1
4 7 1
4 6 1
*/