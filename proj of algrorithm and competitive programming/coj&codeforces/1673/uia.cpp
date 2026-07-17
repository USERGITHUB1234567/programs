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
const int maxn=35,mod=1000000007,maxb=320; 
namespace utilities{ 
    long long fact[maxn],ifact[maxn]; 
    long long __uiagcd(long long a, long long b) { if(a<b) swap(a,b); while(a%b!=0) {long long c=a%b;a=b,b=c;} return b; } 
    inline ll __logarit(ll k, ll n){ll res=0;while(n>0){n/=k;++res;}return res;} 
    inline ll modexp(ll b, ll e, ll m) { ll res=1%m; while(e>0) { if(e&1) res=(res*b)%m; b=(b*b)%m; e>>=1; } return res; } 
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
int n,m;
bool rem[1003];
//vector<pair<int,int>>adj[maxn];
int ans=0;
vector<int>res;
struct edge{int u,v,w,id;}e[1003];
struct dinitz{
    int cap[maxn][maxn],flow[maxn][maxn],d[maxn],ptr[maxn];
    int n,s,t;
    vector<int>adj[maxn];
    dinitz(int _n):n(_n){
        init();
    }
    void init() {
        memset(cap, 0, sizeof(cap));
        memset(flow, 0, sizeof(flow));
        for(int i=1; i<=n; ++i) adj[i].clear();
        for(int i=1; i<=m; ++i) {
            if(!rem[i]) {
                auto[u,v,w,id]=e[i];
                adj[u].pb(v);
                adj[v].pb(u);
                cap[u][v]+=w;
                //cap[v][u]+=w;
            }
        }
        s=1,t=n;
    }
    void bfs() {
        memset(d,-1,sizeof(d));
        memset(ptr, 0, sizeof(ptr));
        d[s]=0;
        queue<int>q;
        q.push(s);
        while(!q.empty()) {
            int u=q.front();q.pop();
            for(int v:adj[u]) {
                if(d[v]==-1 && cap[u][v]-flow[u][v]) {q.push(v);d[v]=d[u]+1;}
            }
        }
    }
    int dfs(int u,int f) {
        if(u==t || !f) return f;
        for(;ptr[u]<adj[u].size(); ++ptr[u]) {
            int v=adj[u][ptr[u]];
            if(d[v]!=d[u]+1 || flow[u][v]==cap[u][v]) continue;
            int push=dfs(v,min(f,cap[u][v]-flow[u][v]));
            if(push) {
                flow[u][v]+=push;
                flow[v][u]-=push;
                return push;
            }
        }
        return 0;
    }
    int maxflow() {
        int total=0;
        while(true) {
            bfs();
            if(d[t]==-1) break;
            while(int push=dfs(s,INT_MAX)) total+=push;
        }
        return total;
    }
};
int main(int argc, char** argv) { 
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); 
    cin >> n >> m;
    for(int i=1,u,v,w; i<=m; ++i) {
        cin >> u >> v >> w;
        e[i]={u,v,w,i};
    }
    sort(e+1,e+1+m,[&](edge a, edge b){return (a.w>b.w)||(a.w==b.w && a.id<b.id);});
    dinitz d(n);
    ans=d.maxflow();
    int cur=ans;
    for(int i=1; i<=m; ++i) {
        rem[i]=true;
        dinitz tmp(n);
        int w=e[i].w,t=tmp.maxflow();
        if(t==cur-w) {cur=t;res.pb(e[i].id);}
        else rem[i]=false;
    }
    cout << ans << ' ' << res.size() << '\n';
    for(int i:res) cout << i << '\n';
    return 0; 

} 
/**/