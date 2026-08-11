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
const int maxn=200005,mod=1000000007,maxb=320; 
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
int n,q,v[maxn],head[maxn],pos[maxn],heavy[maxn],sz[maxn],p[maxn],d[maxn],rev[maxn],cur=0;
vector<int>adj[maxn];
class segment_tree{
    private:
        long long st[maxn<<2];
    public:
        void build(int id, int l, int r) {
            if(l==r) {
                st[id]=v[rev[l]];
                return;
            }
            int mid=(l+r)>>1;
            build(id<<1,l,mid);
            build(id<<1|1,mid+1,r);
            st[id]=st[id<<1]+st[id<<1|1];
        }
        void update(int id, int l, int r, int i, int val) {
            //if(l>i || r<i) return;
            if(l==r) {
                st[id]=val;
                v[l]=val;
                return;
            }
            int mid=(l+r)>>1;
            if(i<=mid) update(id<<1,l,mid,i,val);
            else update(id<<1|1,mid+1,r,i,val);
            st[id]=st[id<<1]+st[id<<1|1];
        }
        long long query(int id, int l, int r, int i, int j) {
            if(l>j || r<i) return 0;
            if(l>=i && r<=j) return st[id];
            int mid=(l+r)>>1;
            return query(id<<1,l,mid,i,j)+query(id<<1|1,mid+1,r,i,j);
        }
}seg;
int dfs(int u, int par) {
    sz[u]=1;
    int szm=0,csz;
    for(int v:adj[u]) {
        if(v==par) continue;
        p[v]=u;
        d[v]=d[u]+1;
        csz=dfs(v,u);
        if(csz>szm) {szm=csz,heavy[u]=v;}
        sz[u]+=csz;
    }
    return sz[u];
}
void decompose(int u, int h) {
    head[u]=h;
    pos[u]=++cur;
    if(heavy[u]) decompose(heavy[u],h);
    for(int v:adj[u]) {
        if(v!=heavy[u] && !head[v]) decompose(v,v);
    }
}
long long hld_query(int a, int b) {
    long long res=0;
    for(;head[a]!=head[b];b=p[head[b]]) {
        if(d[head[a]]>d[head[b]]) swap(a,b);
        res+=seg.query(1,1,n,pos[head[b]],pos[b]);
    }
    if(d[a]>d[b]) swap(a,b);
    res+=seg.query(1,1,n,pos[a],pos[b]);
    return res;
}
int main(int argc, char** argv) { 
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); 
    cin >> n >> q;
    for(int i=1; i<=n; ++i) cin >> v[i];
    for(int i=1,u,v; i<n; ++i) {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,0);
    decompose(1,1);
    for(int i=1; i<=n; ++i) {rev[pos[i]]=i;}
    seg.build(1,1,n);
    // for(int i=1; i<=n; ++i) {
    //     seg.update(1,1,n,pos[i],v[i]);
    // }
    while(q--) {
        int t,s,x;
        cin >> t;
        if(t==1) {
            cin >> s >> x;
            seg.update(1,1,n,pos[s],x);
        }
        else {
            cin >> s;
            cout << hld_query(1,s) << '\n';
        }
    }
    return 0; 

} 
/**/