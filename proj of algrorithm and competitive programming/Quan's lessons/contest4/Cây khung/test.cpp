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
const int maxn=202,mod=1000000007,maxb=320; 
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

const long long uncon=123456789;

struct EdgeInfo {
    int u, v;
    long long w;
    int id;
};

// Cây khung hiện tại
vector<EdgeInfo> tree_adj[maxn];

class disjoint_set_union{
    private:
        int p[maxn];
    public:
        disjoint_set_union() {for(int i=0; i<maxn; ++i) p[i]=i;}
        int root(int u) {return(p[u]==u?u:p[u]=root(u));}
        void unite(int u, int v) {
            u=root(u),v=root(v);
            if(u==v) return;
            p[v]=u;
        }
        bool check(int u, int v) {return root(u)==root(v);}
} dsu;

int n, m, ncomp;

int main(int argc, char** argv) { 
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); 
    
    if (!(cin >> n >> m)) return 0;
    
    ncomp = n;
    long long mst_weight = 0;
    
    for(int i=1; i<=m; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        
        if (u == v) {
            // Không xét khuyên (Cạnh tự chỉ)
        } else if (!dsu.check(u, v)) {
            // 2 đỉnh thuộc 2 thành phần liên thông khác nhau -> Nối lại tạo rừng cây
            dsu.unite(u, v);
            tree_adj[u].push_back({u, v, w, i});
            tree_adj[v].push_back({v, u, w, i});
            mst_weight += w;
            ncomp--;
        } else {
            // Trường hợp đỉnh u và v đã thuộc cùng thành phần liên thông (tạo ra chu trình)
            int p[maxn];
            int p_id[maxn];
            long long p_weight[maxn];
            for(int j=1; j<=n; ++j) p[j] = 0;
            
            queue<int> q;
            q.push(u);
            p[u] = -1;
            
            // Tìm đường đi từ u đến v bằng BFS
            while(!q.empty()) {
                int curr = q.front(); q.pop();
                if(curr == v) break;
                for(auto& edge : tree_adj[curr]) {
                    if(p[edge.v] == 0) {
                        p[edge.v] = curr;
                        p_id[edge.v] = edge.id;
                        p_weight[edge.v] = edge.w;
                        q.push(edge.v);
                    }
                }
            }
            
            long long max_w = -2000000000000000000LL; 
            int max_id = -1, max_u = -1, max_v = -1;
            
            // Quét ngược lại để tìm cạnh có trọng số nặng nhất trên đường đi u -> v
            int curr = v;
            while(curr != u && curr != 0 && curr != -1) {
                int nxt = p[curr];
                if (nxt == 0 || nxt == -1) break;
                if(p_weight[curr] > max_w) {
                    max_w = p_weight[curr];
                    max_id = p_id[curr];
                    max_u = nxt;
                    max_v = curr;
                }
                curr = nxt;
            }
            
            // Tối ưu cạnh mới
            if(w < max_w) {
                mst_weight = mst_weight - max_w + w;
                
                // Xóa bỏ cạnh nặng nhất max_id khỏi danh sách kề
                for(int j=0; j<(int)tree_adj[max_u].size(); ++j) {
                    if(tree_adj[max_u][j].id == max_id) {
                        tree_adj[max_u].erase(tree_adj[max_u].begin() + j);
                        break;
                    }
                }
                for(int j=0; j<(int)tree_adj[max_v].size(); ++j) {
                    if(tree_adj[max_v][j].id == max_id) {
                        tree_adj[max_v].erase(tree_adj[max_v].begin() + j);
                        break;
                    }
                }
                
                // Kết nối cạnh mới vào
                tree_adj[u].push_back({u, v, w, i});
                tree_adj[v].push_back({v, u, w, i});
            }
        }
        
        // Output trả về kết quả
        if (ncomp > 1) {
            cout << uncon << "\n";
        } else {
            cout << mst_weight << "\n";
        }
    }
    return 0; 
} 
/**/