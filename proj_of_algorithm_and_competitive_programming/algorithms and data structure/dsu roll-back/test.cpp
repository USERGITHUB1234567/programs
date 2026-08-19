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
class disjoint_sets_union{
    private:
        vector<int>p,sz,his;
        int n;
    public:
        disjoint_sets_union(int _n) {
            n=_n;
            p.resize(n);sz.resize(n,1);
            iota(all(p),0);
        }
        inline int root(int u) {return (p[u]==u?u:root(p[u]));}
        inline void unite(int u, int v) {
            u=root(u),v=root(v);
            if(u==v) return;
            if(sz[u]<sz[v]) swap(u,v);
            his.pb(v);
            sz[u]+=sz[v];
            p[v]=u;
        }
        inline void rollback() {
            int v=his.back(),u=p[v];
            sz[u]-=sz[v];
            p[v]=v;
            his.pop_back();
        }

};
/* vector<pair<int,int>> segments[4 * N];

vector<array<int, 4>> edges; // (u, v, l, r)

Void add_edge(int u, int v, pair<int,int> e, int l, int r, int id){
	If (u <= l && r <= v){
		segments.push_back(e);
		return;
}
Int mid = (l + r) >> 1;
If (u <= mid) add_edge(u, v, e, l, mid, id * 2);
If (v > mid) add_edge(u, v, e, mid+1, r, id * 2 + 1);
}

Void traverse(DSU &graph, int l, int r, int id){
	Int current_version = graph.history.size();
	for(pair<int,int> e: segments[id])
		graph.join_set(e.first, e.second);
	If (l == r){
		Ans[l] = n - graph.history.size();
		while(graph.history.size() > current_version)
			graph.roll_back();
		return;
}
Int mid = (l + r) >> 1;
traverse(graph, l, mid, id * 2);
traverse(graph, mid+1, r, id * 2 + 1);

	while(graph.history.size() > current_version)
		graph.roll_back();
}


Void solve(){
	for(auto i: edges){
		add_edge(i[2], i[3], make_pair(i[0], i[1]), 1, n, 1);
}

DSU graph(n);
traverse(graph, 1, n, 1);
} */



int main(int argc, char** argv) { 
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); 
    // disjoint_sets_union dsu(10);
    // dsu.unite(1,2);
    // dsu.rollback();
    // cout << dsu.root(2);
    return 0; 

} 
/*
5 3 3
1 4
2 3
3 5
1 2 5
2 3 5
1 1 2
*/