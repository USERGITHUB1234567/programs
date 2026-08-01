/**/ 
#pragma GCC optimize("O3","Ofast","unroll-loops") 
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
const int maxn=2003,mod=1000000007,maxb=320; 
namespace utilities{ 
    long long fact[maxn],ifact[maxn]; 
    long long __uiagcd(long long a, long long b) { if(a<b) swap(a,b); while(a%b!=0) {long long c=a%b;a=b,b=c;} return b; } 
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
    inline int lomuto_partition(vector<int>&a, int l, int r) {int pivot=a[r],i=l-1;for(int j=l; j<r; ++j) {if(a[j]<=pivot) {++i;swap(a[i],a[j]);}}swap(a[r],a[i+1]);return i+1;} 
    inline int hoare_partition(vector<int>&a, int l, int r) {int pivot=a[l],i=l,j=r;bool partition=true;while(partition) {while(a[i]<pivot) ++i;while(a[j]>pivot) --j;if(i<j) {swap(a[i],a[j]);++i,--j;}else partition=false;}return j;} 
    inline void quicksort_lomuto(vector<int>&a, int l, int r) {if(l>=r) return;int p=lomuto_partition(a,l,r);quicksort_lomuto(a,l,p-1);quicksort_lomuto(a,p+1,r);} 
    inline void quicksort_hoare(vector<int>&a, int l, int r) {if(l>=r) return;int p=hoare_partition(a,l,r);quicksort_hoare(a,l,p);quicksort_hoare(a,p+1,r);} 
} 
//using namespace utilities; 
mt19937_64 generator1(steady_clock::now().time_since_epoch().count()); 
mt19937_64 generator2(high_resolution_clock::now().time_since_epoch().count()); 
inline long long rnd1(long long a, long long b) {return a+generator1()%(b-a+1);} 
inline long long rnd2(long long a, long long b) {return a+generator2()%(b-a+1);} 
auto imp_st=high_resolution_clock::now(); 
inline void start_timer() {imp_st=high_resolution_clock::now();} 
inline void get_execution_time() { auto imp_en=high_resolution_clock::now(); cerr << "Implementation Time: "<< duration_cast<milliseconds>(imp_en-imp_st).count() << " ms\n"; } 
int n,m,q;
long long d[2][maxn][maxn];
vector<pair<int,int>>adj[maxn];
const long long inf=LLONG_MAX>>1;
namespace uiasoup{
    inline void dijkstra(int st, int t) {
        struct state{int u,cd;bool imp;bool operator>(const state& o) const {return cd>o.cd;}};
        priority_queue<state,vector<state>,greater<state>>pq;
        pq.push({st,0,false});
        for(int i=1; i<=n; ++i) d[0][i][t]=d[1][i][t]=inf;
        d[0][st][t]=0;
        while(!pq.empty()) {
            auto[u,cd,imp]=pq.top();pq.pop();
            //cerr << u << ' ' << cd << ' ' << imp << ' ' << d[imp][u][t] << '\n';
            if(cd>d[imp][u][t]) continue;
            for(auto[v,w]:adj[u]) {
                //cerr << v << ' ' << w << ' ' << t << ' ' << (d[imp][v][t]) << ' ' << cd+w << '\n';
                if(d[imp][v][t]>cd+w) {d[imp][v][t]=cd+w;pq.push({v,cd+w,imp});}
                //cerr << imp << ' ' << d[imp][v][t] << ' ';
                if(!imp) {
                    int nw=t;
                    imp=true;
                    if(d[imp][v][t]>cd+nw) {d[imp][v][t]=cd+nw;pq.push({v,cd+nw,imp});}
                    imp=false;
                }
                //cerr << imp << ' ' << d[imp][v][t] << '\n';
            }
        }
    }
    void solve() {
        for(int i=1; i<=2000; ++i) dijkstra(1,i);
        //dijkstra(1,14);
        while(q--) {
            int s,t;cin >> s >> t;
            cout << min(d[0][s][t],d[1][s][t]) << '\n';
        }
    }
}
namespace soupfull{
    long long d1[maxn],d2[maxn];
    void solve() {
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        pq.push({0,1});
        for(int i=1; i<=n; ++i) d1[i]=d2[i]=inf;
        d1[1]=0;
        while(!pq.empty()) {
            auto[cd,u]=pq.top();
            pq.pop();
            if(cd>d1[u]) continue;
            for(auto[v,w]:adj[u]) {
                if(d1[v]>d1[u]+w) {d1[v]=d1[u]+w,pq.push({d1[v],v});}
            }
        }
        //while(!pq.empty()) pq.pop();
        for(int i=1; i<=n; ++i) {
            if(d1[i]!=inf) {
                for(auto[v,w]:adj[i]) {
                    if(d2[v]>d1[i]) d2[v]=d1[i];
                }
            }
        }
        for(int i=1; i<=n; ++i) if(d2[i]!=inf) pq.push({d2[i],i});
        while(!pq.empty()) {
            auto[cd,u]=pq.top();pq.pop();
            if(cd>d2[u]) continue;
            for(auto[v,w]:adj[u]) {
                if(d2[v]>cd+w) {d2[v]=d2[u]+w,pq.push({d2[v],v});}
            }
        }
        while(q--) {
            int s,t;cin >> s >> t;
            cout << min(d1[s],d2[s]+t) << '\n';
        }
    }
}
int main(int argc, char** argv) { 
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); 
    cin >> n >> m >> q;
    for(int i=1,u,v,w; i<=m; ++i) {
        cin >> u >> v >> w;
        adj[u].pb({v,w});
    }
    soupfull::solve();
    //cout << d[1][3][14];
    return 0; 

} 
/**/