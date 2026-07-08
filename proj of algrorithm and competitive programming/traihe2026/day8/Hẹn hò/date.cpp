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
const int maxn=300005,mod=1000000007,maxb=320; 
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
int n,k,tin[maxn],timer=0,d[maxn],up[maxn][20],logn,cur;
vector<int>adj[maxn];
set<pair<int,int>>st;
inline void dfs(int u, int p) {
    tin[u]=++timer;
    for(int v:adj[u]) {
        if(v!=p) {
            d[v]=d[u]+1;
            up[v][0]=u;
            dfs(v,u);
        }
    }
}
inline int lca(int u, int v) {
    if(d[u]<d[v]) swap(u,v);
    int dif=d[u]-d[v];
    for(int i=dif; i; i&=(i-1)) {
        int j=__builtin_ctz(i);
        u=up[u][j];
    }
    if(u==v) return u;
    for(int i=logn; i>=0; --i) {
        if(up[u][i]!=up[v][i]) u=up[u][i],v=up[v][i];
    }
    return up[u][0];
}
inline int dist(int u, int v) {return d[u]+d[v]-(d[lca(u,v)]<<1);}
inline void add(int u) {
    if(st.empty()) {st.insert({tin[u],u});return;}
    auto it=st.insert({tin[u],u}).fi,prv=it,nxt=it;
    if(prv==st.begin()) prv=st.end();
    --prv;
    ++nxt;
    if(nxt==st.end()) nxt=st.begin();
    int x=prv->second,y=nxt->second;
    cur+=dist(u,x)+dist(u,y)-dist(x,y);
}
inline void rem(int u) {
    auto it=st.find({tin[u],u});
    if(st.size()==1) {st.erase(it);return;}
    auto prv=it,nxt=it;
    if(prv==st.begin()) prv=st.end();
    --prv;
    ++nxt;
    if(nxt==st.end()) nxt=st.begin();
    int x=prv->second,y=nxt->second;
    cur-=dist(u,x)+dist(u,y)-dist(x,y);
    st.erase(it);
}
inline int get_sz() {return st.empty()?0:(cur>>1)+1;}
int main(int argc, char** argv) { 
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); 
    cin >> n >> k;
    for(int i=1,u,v; i<n; ++i) {cin >> u >> v;adj[u].pb(v),adj[v].pb(u);}
    logn=32-__builtin_clz(n);
    dfs(0,0);
    for(int j=1; j<=logn; ++j) {
        for(int i=0; i<n; ++i) {
            up[i][j]=up[up[i][j-1]][j-1];
        }
    }
    int ans=0;
    for(int l=0,r=0; r<n; ++r) {
        add(r);
        while(get_sz()>k) {
            rem(l++);
        }
        if(l>r) break;
        ans=max(ans,r-l+1);
    }
    cout << ans;
    return 0; 

} 
/**/