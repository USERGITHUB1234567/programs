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
const int maxn=1005,mod=1000000007,maxb=320;
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
class a{};
class disjoint_sets_union{
    private:
        struct edge{
            int u,v;
            edge()=default;
            edge(int _u, int _v):u(_u),v(_v){}
        };
        vector<vector<edge>> new_edges;
        vector<int>ans,sz,p,total;
        struct update{
            int node,old_sz;
            update()=default;
            update(int _n, int _o):node(_n),old_sz(_o){}
        };
        stack<update>rollback;
        int root(int u) {while(p[u]!=u) u=p[u]; return u;}
        int cur_comp;
        void merge(int id, int u, int v) {
            u=root(u), v=root(v);
            if(u==v) return;
            if(sz[u]<sz[v]) swap(u,v);
            rollback.push({u,sz[u]}); rollback.push({v,sz[v]});
            total[id]+=2;
            sz[u]+=sz[v];
            p[v]=u;
        }
    public:
        // _n = number of vertices, seg_sz = size for segment-tree arrays (4*m+5)
        disjoint_sets_union(int _n, int seg_sz=0) {
            cur_comp=_n;
            p.resize(_n+1); sz.resize(_n+1); ans.resize(_n+1);
            for(int i=1; i<=_n; ++i) p[i]=i, sz[i]=1;
            if(seg_sz>0) {
                new_edges.assign(seg_sz, vector<edge>());
                total.assign(seg_sz, 0);
                // ans will be resized later to m+1 by caller if needed
            }
        }
        // initialize segment-tree storage if not provided in constructor
        void init_segment(int seg_sz, int m) {
            new_edges.assign(seg_sz, vector<edge>());
            total.assign(seg_sz, 0);
            ans.assign(m+2, 0);
        }
        void upd(int id, int l, int r, int i, int j, edge cur) {
            if(l>j || r<i) return;
            if(l>=i && r<=j) { new_edges[id].pb(cur); return; }
            int mid=(l+r)>>1;
            upd(id<<1,l,mid,i,j,cur);
            upd(id<<1|1,mid+1,r,i,j,cur);
        }
        void get(int id, int l, int r) {
            for(const auto &e : new_edges[id]) { merge(id,e.u,e.v); }
            cur_comp -= (total[id]>>1);
            if(l==r) {
                if(l < (int)ans.size()) ans[l]=cur_comp;
            } else {
                int mid=(l+r)>>1;
                get(id<<1,l,mid);
                get(id<<1|1,mid+1,r);
            }
            cur_comp += (total[id]>>1);
            while(total[id]) {
                update up = rollback.top(); rollback.pop();
                p[up.node]=up.node;
                sz[up.node]=up.old_sz;
                --total[id];
            }
        }
        int show_ans(int i) { return (i < (int)ans.size() ? ans[i] : 0); }
};
struct appear{int l,r,u,v;};
int n,m;
int main(int argc, char** argv) {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> m;
    // prepare DSU with n vertices and segment-tree sized for m operations
    int seg_sz = (m+5)<<2;
    disjoint_sets_union dsu(n, seg_sz);
    dsu.init_segment(seg_sz, m);

    map<pair<int,int>,int> ump;
    vector<char> op(m+2);
    vector<bool> question(m+2,false);
    vector<appear> store;

    for(int i=1; i<=m; ++i) {
        char t; cin >> t; op[i]=t;
        if(t=='?') { question[i]=true; continue; }
        int u,v; cin >> u >> v;
        pair<int,int> key = (u<v?make_pair(u,v):make_pair(v,u));
        if(t=='+') {
            ump[key]=i;
        } else if(t=='-') {
            auto it = ump.find(key);
            if(it!=ump.end()) {
                int l = it->second;
                // active from l to i-1 (edge removed at i)
                if(l <= i-1) store.pb({l,i-1,u,v});
                ump.erase(it);
            } else {
                // unmatched removal: ignore
            }
        }
    }
    for(auto &x : ump) {
        int u = x.first.first, v = x.first.second;
        int l = x.second;
        if(l <= m) store.pb({l,m,u,v});
    }
    // add intervals to segment tree over time 1..m
    for(auto &it : store) {
        if(it.l <= it.r) dsu.upd(1,1,m,it.l,it.r,{it.u,it.v});
    }
    // process segment tree and compute answers
    dsu.get(1,1,m);

    for(int i=1; i<=m; ++i) {
        if(question[i]) cout << dsu.show_ans(i) << '\n';
    }
    return 0;
}
/**/
