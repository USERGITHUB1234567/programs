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
const int maxn=100005,mod=1000000007,maxb=320; 
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
int tc,n,pos[maxn],head[maxn],heavy[maxn],p[maxn],d[maxn],rev[maxn],a[maxn],eid[maxn],cur;
struct edge{int v,w,id;};
vector<edge>adj[maxn];
class segment_tree{
    private:
        int st[maxn<<2];
    public:
        void build(int id, int l, int r) {
            if(l==r) {
                st[id]=a[rev[l]];
                return;
            }
            int mid=(l+r)>>1;
            build(id<<1,l,mid);
            build(id<<1|1,mid+1,r);
            st[id]=max(st[id<<1],st[id<<1|1]);
        }
        void update(int id, int l, int r, int i, int v) {
            if(l==r) {
                st[id]=v;
                return;
            }
            int mid=(l+r)>>1;
            if(i<=mid) update(id<<1,l,mid,i,v);
            else update(id<<1|1,mid+1,r,i,v);
            st[id]=max(st[id<<1],st[id<<1|1]);
        }
        int query(int id, int l, int r, int i, int j) {
            if(l>j || r<i) return 0;
            if(l>=i && r<=j) return st[id];
            int mid=(l+r)>>1;
            return max(query(id<<1,l,mid,i,j),query(id<<1|1,mid+1,r,i,j));
        }
}seg;
int dfs(int u, int par) {
    int sz=1,szm=0,csz;
    for(auto[v,w,i]:adj[u]) {
        if(v==par) continue;
        a[v]=w;
        eid[i]=v;
        p[v]=u;
        d[v]=d[u]+1;
        csz=dfs(v,u);
        if(csz>szm) {szm=csz,heavy[u]=v;}
        sz+=csz;
    }
    return sz;
}
void decompose(int u, int h) {
    head[u]=h;
    pos[u]=++cur;
    if(heavy[u]) decompose(heavy[u],h);
    for(auto[v,w,i]:adj[u]) {
        if(v!=heavy[u] && !head[v]) decompose(v,v);
    }
}
int hld_query(int u, int v) {
    int res=0;
    for(;head[u]!=head[v];v=p[head[v]]) {
        if(d[head[u]]>d[head[v]]) swap(u,v);
        res=max(res,seg.query(1,1,n,pos[head[v]],pos[v]));
    }
    if(u!=v) {
        if(d[u]>d[v]) swap(u,v);
        res=max(res,seg.query(1,1,n,pos[u]+1,pos[v]));
    }
    return res;
}
int main(int argc, char** argv) { 
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); 
    cin >> tc;
    while(tc--) {
        cin >> n;
        for(int i=1; i<=n; ++i) {adj[i].clear();eid[i]=0; heavy[i]=head[i]=p[i]=d[i]=pos[i]=rev[i]=a[i]=0;}
        for(int i=1,u,v,w; i<n; ++i) {
            cin >> u >> v >> w;
            adj[u].pb({v,w,i});
            adj[v].pb({u,w,i});
        }
        a[1]=0; cur=0;
        dfs(1,0);
        decompose(1,1);
        for(int i=1; i<=n; ++i) rev[pos[i]]=i;
        seg.build(1,1,n);
        string s;
        while(cin >> s) {
            if(s=="DONE") break;
            if(s=="QUERY") {
                int u,v;cin >> u >> v;
                cout << hld_query(u,v) << '\n';
            }
            else {
                int i,ti;cin >> i >> ti;
                int u=eid[i];
                seg.update(1,1,n,pos[u],ti);
            }
        }
    }
    return 0; 

} 
/**/