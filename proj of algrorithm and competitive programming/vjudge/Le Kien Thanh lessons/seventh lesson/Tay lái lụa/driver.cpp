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
const int maxn=1003,mod=1000000007,maxb=320; 
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
int n,m,d[1003],p[maxn];
vector<int>children[maxn];
vector<pair<int,int>>adj[maxn];
void dfs(int u) {
    for(auto[v,w]:adj[u]) {
        if(v==p[u]) continue;
        d[v]=d[u]+1;
        p[v]=u;
        children[u].pb(v);
        dfs(v);
    }
}
int lca(int u, int v) {
    if(d[u]<d[v]) swap(u,v);
    while(d[u]>d[v]) u=p[u];
    while(u!=v) {u=p[u],v=p[v];}
    return u;
}
struct path{short id,child;};vector<path>passing[1003];
struct lcapath{short id,u,v;int w;};vector<lcapath>lcap[1003];
int val[1003][5003],f_arr[1003];
void solve(int u) {
    for(int c:children[u]) solve(c);
    int k=children[u].size(),base=0;
    //for(int c:children[u]) base+=fmax[c];
    for(int c:children[u]) base+=f_arr[c];
    vector<int>id(1003,-1);
    for(int i=0; i<k; ++i) id[children[u][i]]=i;
    int fm=1<<k;
    vector<int>f(fm,0);
    for(int mask=0; mask<fm; ++mask) {
        for(int i=0; i<k; ++i) {
            if(mask&(1<<i)) f[mask]=max(f[mask],f[mask^(1<<i)]);
        }
        for(auto& p:lcap[u]) {
            int m=0,add=p.w;
            if(p.u!=-1) {
                int i=id[p.u];
                m|=(1<<i);
                add+=val[p.u][p.id]-f_arr[p.u];
            }
            if(p.v!=-1) {
                int i=id[p.v];
                m|=(1<<i);
                add+=val[p.v][p.id]-f_arr[p.v];
            }
            if((mask&m)==m) f[mask]=max(f[mask],f[mask^m]+add);
        }
    }
    f_arr[u]=base+f[fm-1];
    for(auto& p:passing[u]) {
        if(p.child==-1) val[u][p.id]=f_arr[u];
        else {
            int i=id[p.child],avail=(fm-1)^(1<<i);
            val[u][p.id]=base-f_arr[p.child]+val[p.child][p.id]+f[avail];
        }
    }
}
int main(int argc, char** argv) { 
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); 
    cin >> n >> m;
    struct edge{int u,v,w;};
    vector<edge>dirt;
    long long t=0;
    for(int i=0,u,v,w; i<m; ++i) {
        cin >> u >> v >> w;
        if(w==0) adj[u].pb({v,w}),adj[v].pb({u,w});
        else {dirt.pb({u,v,w});t+=w;}
    }
    dfs(1);
    int p_id=0;
    long long rem=0;
    for(auto[u,v,w]:dirt) {
        if((d[u]&1)!=(d[v]&1)) {rem+=w;continue;}
        int l=lca(u,v),cur=u,cu=-1,cv=-1;
        while(cur!=l) {
            passing[cur].pb({(short)p_id,(short)cu});
            cu=cur;
            cur=p[cur];
        }
        cur=v;
        while(cur!=l) {
            passing[cur].pb({(short)p_id,(short)cv});
            cv=cur;
            cur=p[cur];
        }
        lcap[l].pb({(short)p_id,(short)cu,(short)cv,w});
        ++p_id;
    }
    solve(1);
    cout << t-f_arr[1];
    return 0; 

} 
/**/