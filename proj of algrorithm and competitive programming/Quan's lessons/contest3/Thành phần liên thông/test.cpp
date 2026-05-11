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
const int maxn=200005,mod=1000000007,maxb=320; 

namespace utilities{ 
    long long fact[maxn],ifact[maxn]; 
    long long __uiagcd(long long a, long long b) { if(a<b) swap(a,b); while(a%b!=0) {long long c=a%b;a=b,b=c;} return b; } 
    inline ll __logarit(ll k, ll n){ll res=0;while(n>0){n/=k;++res;}return res;} 
    inline ll modexp(ll b, ll e, ll m) { ll res=1%m; while(e>0) { if(e&1) res=(res*b)%m; b=(b*b)%m; e>>=1; } return res; } 
    inline int maxi(int a, int b) {return (a>b?a:b);} 
    inline int mini(int a, int b) {return (a<b?a:b);} 
    inline ll maxill(ll a, ll b) {return (a>b?a:b);} 
    inline ll minill(ll a, ll b) {return (a<b?a:b);} 
    void setUpFactor() { fact[0]=1; for(int i=1; i<maxn; ++i) fact[i]=fact[i-1]*i%mod; int tc=maxn-1; ifact[tc]=modexp(fact[tc],mod-2,mod); for(int i=tc; i>=1; --i) ifact[i-1]=ifact[i]*i%mod; } 
    inline long long ncr(long long k, long long n) {return (k==n?1:fact[n]*ifact[n-k]%mod*ifact[k]%mod);} 
} 

// Global variables for problem
int n, m, q;
ll w[maxn], current_w[maxn], ans[maxn];
pair<int, int> edge[maxn];
bool is_removed[maxn];
multiset<ll> component_sums;

struct query {
    char type;
    int i;
    ll k;
    ll pv; // previous value for 'C' type
} qu[maxn];

class disjoint_sets_union {
    private:
        int p[maxn];
    public:
        ll sz[maxn];
        disjoint_sets_union() { forw(i, 1, maxn-1) p[i] = i; }
        inline int root(int u) { return p[u] == u ? u : p[u] = root(p[u]); }
        
        inline void unite(int u, int v) {
            u = root(u); v = root(v);
            if (u == v) return;
            // Xóa tổng cũ của 2 thành phần khỏi multiset
            component_sums.erase(component_sums.find(sz[u]));
            component_sums.erase(component_sums.find(sz[v]));
            
            if (sz[u] < sz[v]) swap(u, v);
            p[v] = u;
            sz[u] += sz[v];
            
            // Thêm tổng mới sau khi gộp
            component_sums.insert(sz[u]);
        }
        
        inline void update_weight(int u, ll delta) {
            int r = root(u);
            component_sums.erase(component_sums.find(sz[r]));
            sz[r] += delta;
            component_sums.insert(sz[r]);
        }
} dsu;

int main(int argc, char** argv) { 
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); 
    
    if (!(cin >> n >> m >> q)) return 0;
    
    forw(i, 1, n) {
        cin >> w[i];
        current_w[i] = w[i];
    }
    
    forw(i, 1, m) {
        cin >> edge[i].fi >> edge[i].se;
        is_removed[i] = false;
    }
    
    forw(i, 1, q) {
        cin >> qu[i].type;
        if (qu[i].type == 'D') {
            cin >> qu[i].i;
            is_removed[qu[i].i] = true;
        } else {
            cin >> qu[i].i >> qu[i].k;
            qu[i].pv = current_w[qu[i].i]; // Lưu trọng số trước khi thay đổi
            current_w[qu[i].i] = qu[i].k;  // Cập nhật trọng số hiện tại
        }
    }

    // Khởi tạo DSU với trạng thái SAU KHI thực hiện tất cả các thao tác
    forw(i, 1, n) {
        dsu.sz[i] = current_w[i];
        component_sums.insert(dsu.sz[i]);
    }
    
    forw(i, 1, m) {
        if (!is_removed[i]) {
            dsu.unite(edge[i].fi, edge[i].se);
        }
    }

    // Xử lý ngược từ Q về 1
    forb(i, q, 1) {
        // Đáp án tại thời điểm sau thao tác i là giá trị lớn nhất trong multiset
        ans[i] = *component_sums.rbegin();
        
        if (qu[i].type == 'D') {
            // "Hoàn tác" việc xóa cạnh bằng cách thêm cạnh vào DSU
            dsu.unite(edge[qu[i].i].fi, edge[qu[i].i].se);
        } else {
            // "Hoàn tác" việc đổi trọng số: thay đổi từ k về pv
            ll delta = qu[i].pv - qu[i].k;
            dsu.update_weight(qu[i].i, delta);
        }
    }

    // In kết quả theo thứ tự thời gian thực
    forw(i, 1, q) {
        cout << ans[i] << "\n";
    }

    return 0; 
} 
/**/