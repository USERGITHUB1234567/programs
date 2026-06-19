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
const int maxn=100005,mod=1000000007,maxb=320; // Đã tăng maxn để vượt qua Subtask 3
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

int n, m, q;
vector<pair<int, long long>> adj[maxn];
const long long INF = 1e18;
long long dist1[maxn];
long long best[maxn];

inline void precalculate() {
    for(int i = 1; i <= n; ++i) {
        dist1[i] = INF;
        best[i] = INF;
    }
    
    // 1. Dijkstra 1: Tìm đường đi ngắn nhất chuẩn từ 1 đến các đỉnh
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    dist1[1] = 0;
    pq.push({0, 1});
    
    while(!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if(d > dist1[u]) continue;
        for(auto [v, w] : adj[u]) {
            if(dist1[v] > d + w) {
                dist1[v] = d + w;
                pq.push({dist1[v], v});
            }
        }
    }
    
    // 2. Khởi tạo giá trị nâng cấp cho các đỉnh kề
    for(int u = 1; u <= n; ++u) {
        if(dist1[u] == INF) continue;
        for(auto [v, w] : adj[u]) {
            if(dist1[u] < best[v]) {
                best[v] = dist1[u];
            }
        }
    }
    
    // 3. Dijkstra 2 (Multi-source): Lan truyền chi phí nâng cấp
    for(int i = 1; i <= n; ++i) {
        if(best[i] != INF) {
            pq.push({best[i], i});
        }
    }
    
    while(!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if(d > best[u]) continue;
        for(auto [v, w] : adj[u]) {
            if(best[v] > d + w) {
                best[v] = d + w;
                pq.push({best[v], v});
            }
        }
    }
}

int main(int argc, char** argv) { 
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); 
    
    cin >> n >> m >> q;
    for(int i = 1, u, v; i <= m; ++i) {
        long long w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        // adj[v].pb({u,w}); // Nếu đồ thị là vô hướng thì bỏ comment dòng này
    }
    
    precalculate();
    
    // 4. Trả lời truy vấn O(1)
    while(q--) {
        int s;
        long long t;
        cin >> s >> t;
        
        long long ans = dist1[s];
        if(best[s] != INF) {
            ans = min(ans, best[s] + t);
        }
        
        if(ans >= INF) cout << -1 << '\n';
        else cout << dist1[s] << ' ' << ans << '\n';
    }
    
    return 0; 
} 
/**/

/* #pragma GCC optimize("O3","Ofast","unroll-loops")
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const long long INF = LLONG_MAX;

struct EdgeDest {
    int v;
    long long w;
};

int n, m, q;
vector<vector<EdgeDest>> adj;
vector<long long> dist1;
vector<long long> W_dist;

int main() {
    // Fast I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    if (!(cin >> n >> m >> q)) return 0;
    
    adj.resize(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    
    // 1. First Dijkstra: Shortest path from source node 1.
    dist1.assign(n + 1, INF);
    dist1[1] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq1;
    pq1.push({0, 1});
    
    while (!pq1.empty()) {
        auto [d, u] = pq1.top();
        pq1.pop();
        
        if (d > dist1[u]) continue;
        
        for (auto& edge : adj[u]) {
            int v = edge.v;
            long long w = edge.w;
            if (dist1[v] > d + w) {
                dist1[v] = d + w;
                pq1.push({dist1[v], v});
            }
        }
    }
    
    // 2. Setup Multi-Source initialization simulating taking at most 1 free edge
    W_dist.assign(n + 1, INF);
    for (int u = 1; u <= n; ++u) {
        if (dist1[u] == INF) continue;
        for (auto& edge : adj[u]) {
            int v = edge.v;
            if (W_dist[v] > dist1[u]) {
                W_dist[v] = dist1[u];
            }
        }
    }
    
    // 3. Second Dijkstra: Multi-source to simulate the remainder of the optimal path 
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq2;
    for (int i = 1; i <= n; ++i) {
        if (W_dist[i] != INF) {
            pq2.push({W_dist[i], i});
        }
    }
    
    while (!pq2.empty()) {
        auto [d, u] = pq2.top();
        pq2.pop();
        
        if (d > W_dist[u]) continue;
        
        for (auto& edge : adj[u]) {
            int v = edge.v;
            long long w = edge.w;
            if (W_dist[v] > d + w) {
                W_dist[v] = d + w;
                pq2.push({W_dist[v], v});
            }
        }
    }
    
    // 4. O(1) Answering per query
    while (q--) {
        int s;
        long long t0;
        cin >> s >> t0;
        long long ans = dist1[s];
        
        if (W_dist[s] != INF) {
            long long upgraded_cost = W_dist[s] + t0;
            if (ans > upgraded_cost) {
                ans = upgraded_cost;
            }
        }
        
        cout << ans << "\n";
    }
    
    return 0;
} */