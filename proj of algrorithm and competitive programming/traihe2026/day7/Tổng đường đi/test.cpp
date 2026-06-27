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
mt19937_64 generator1(steady_clock::now().time_since_epoch().count()); 
mt19937_64 generator2(high_resolution_clock::now().time_since_epoch().count()); 
inline long long rnd1(long long a, long long b) {return a+generator1()%(b-a+1);} 
inline long long rnd2(long long a, long long b) {return a+generator2()%(b-a+1);} 
auto imp_st=high_resolution_clock::now(); 
inline void start_timer() {imp_st=high_resolution_clock::now();} 
inline void get_execution_time() { auto imp_en=high_resolution_clock::now(); cerr << "Implementation Time: "<< duration_cast<milliseconds>(imp_en-imp_st).count() << " ms\n"; } 

int n, a[maxn];
vector<int> adj[maxn];

int main(int argc, char** argv) { 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr); 
    
    if (!(cin >> n)) return 0;
    
    for(int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    
    map<int, int> tot;                 // Total occurrences of each color in the tree
    map<int, long long> sum_depth;     // Sum of depths for all nodes of a specific color
    vector<map<int, int>> cnt(n + 1); 
    long long lca_penalty = 0;         // Will store: 2 * depth(LCA) for every valid pair
    
    // We now pass 'd' (depth) along with the DFS state
    auto dfs = [&](auto& self, int u, int p, int d) -> void {
        tot[a[u]]++;
        sum_depth[a[u]] += d;
        cnt[u][a[u]] = 1;
        
        for(int v : adj[u]) {
            if(v == p) continue;
            self(self, v, u, d + 1);
            
            // Small to Large Merging
            if(cnt[u].size() < cnt[v].size()) {
                swap(cnt[u], cnt[v]);
            }
            
            for(auto const& [x, y] : cnt[v]) {
                // Using .find() avoids inserting 0 just to check existence, saving time
                auto it = cnt[u].find(x);
                if(it != cnt[u].end()) {
                    // Number of pairs formed with LCA `u` is (it->second * y)
                    lca_penalty += 2LL * d * it->second * y;
                    it->second += y;
                } else {
                    cnt[u].insert({x, y});
                }
            }
            cnt[v].clear();
        }
    };
    
    // Root is node 1, its parent is 0, its depth is 0
    dfs(dfs, 1, 0, 0);
    
    long long total_ans = 0;
    for(auto const& [c, count] : tot) {
        if(count > 1) {
            // (Total nodes of this color - 1) * (Sum of their depths)
            total_ans += 1LL * (count - 1) * sum_depth[c];
        }
    }
    
    // Subtract the LCA intersections from the raw depths
    total_ans -= lca_penalty;
    
    cout << total_ans << "\n";
    return 0; 
} 
/**/