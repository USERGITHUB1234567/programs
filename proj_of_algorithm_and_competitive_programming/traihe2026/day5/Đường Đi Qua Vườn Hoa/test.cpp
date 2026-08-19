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
int tc;
namespace solver{
    vector<int> dist_arr, fw, bw;
    vector<bool> valid;
    vector<vector<int>> adj;
    int epoch_fw = 0, epoch_bw = 0;

    void solve(int& n, int& m, int& k, int& l, vector<int>&s, vector<int>&d, vector<pair<int,int>>&edge) {
        adj.assign(n+1, vector<int>{});
        dist_arr.assign(n+1, -1);
        valid.assign(n+1, false);
        
        fw.assign(n+1, 0);
        bw.assign(n+1, 0);
        epoch_fw = 0;
        epoch_bw = 0;

        for(auto& p : edge) {
            adj[p.fi].pb(p.se);
            adj[p.se].pb(p.fi);
        }

        queue<int> q;
        q.push(1);
        dist_arr[1] = 0;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(int v : adj[u]) {
                if(dist_arr[v] == -1) {
                    dist_arr[v] = dist_arr[u] + 1;
                    q.push(v);
                }
            }
        }

        bool ok = true;
        for(int x : s) {
            if(dist_arr[x] == -1) ok = false;
        }

        if(ok) {
            sort(all(s), [&](int a, int b) {
                return dist_arr[a] < dist_arr[b];
            });
            for(int i = 0; i < (int)s.size() - 1; ++i) {
                if(dist_arr[s[i]] == dist_arr[s[i+1]]) {
                    ok = false;
                    break;
                }
            }
        }

        if(!ok) {
            for(int i = 2; i <= n; ++i) cout << 0;
            cout << '\n';
            return;
        }

        vector<int> FF;
        FF.pb(1);
        for(int x : s) FF.pb(x);
        int K_new = FF.size() - 1;

        for(int i = 0; i < K_new; ++i) {
            int A = FF[i];
            int B = FF[i+1];
            
            epoch_fw++;
            queue<int> q_fw;
            q_fw.push(A);
            fw[A] = epoch_fw;
            vector<int> vis_fw;
            vis_fw.pb(A);
            
            while(!q_fw.empty()) {
                int u = q_fw.front(); q_fw.pop();
                if(dist_arr[u] == dist_arr[B]) continue;
                for(int v : adj[u]) {
                    if(dist_arr[v] == dist_arr[u] + 1 && dist_arr[v] <= dist_arr[B]) {
                        if(fw[v] != epoch_fw) {
                            fw[v] = epoch_fw;
                            q_fw.push(v);
                            vis_fw.pb(v);
                        }
                    }
                }
            }
            
            if(fw[B] != epoch_fw) {
                ok = false; break;
            }
            
            epoch_bw++;
            queue<int> q_bw;
            q_bw.push(B);
            bw[B] = epoch_bw;
            
            while(!q_bw.empty()) {
                int u = q_bw.front(); q_bw.pop();
                if(dist_arr[u] == dist_arr[A]) continue;
                for(int v : adj[u]) {
                    if(dist_arr[v] == dist_arr[u] - 1 && dist_arr[v] >= dist_arr[A]) {
                        if(bw[v] != epoch_bw) {
                            bw[v] = epoch_bw;
                            q_bw.push(v);
                        }
                    }
                }
            }
            
            for(int u : vis_fw) {
                if(dist_arr[A] < dist_arr[u] && dist_arr[u] < dist_arr[B]) {
                    if(bw[u] == epoch_bw) {
                        valid[u] = true;
                    }
                }
            }
        }

        if(ok) {
            int A = FF[K_new];
            epoch_fw++;
            queue<int> q_fw;
            q_fw.push(A);
            fw[A] = epoch_fw;
            vector<int> vis_fw;
            vis_fw.pb(A);
            
            while(!q_fw.empty()) {
                int u = q_fw.front(); q_fw.pop();
                for(int v : adj[u]) {
                    if(dist_arr[v] == dist_arr[u] + 1) {
                        if(fw[v] != epoch_fw) {
                            fw[v] = epoch_fw;
                            q_fw.push(v);
                            vis_fw.pb(v);
                        }
                    }
                }
            }
            
            epoch_bw++;
            queue<int> q_bw;
            for(int x : d) {
                if(dist_arr[x] >= dist_arr[A]) {
                    if(bw[x] != epoch_bw) {
                        bw[x] = epoch_bw;
                        q_bw.push(x);
                    }
                }
            }
            
            while(!q_bw.empty()) {
                int u = q_bw.front(); q_bw.pop();
                if(dist_arr[u] == dist_arr[A]) continue;
                for(int v : adj[u]) {
                    if(dist_arr[v] == dist_arr[u] - 1 && dist_arr[v] >= dist_arr[A]) {
                        if(bw[v] != epoch_bw) {
                            bw[v] = epoch_bw;
                            q_bw.push(v);
                        }
                    }
                }
            }
            
            if(bw[A] != epoch_bw) {
                ok = false;
            } else {
                for(int u : vis_fw) {
                    if(dist_arr[u] > dist_arr[A]) {
                        if(bw[u] == epoch_bw) {
                            valid[u] = true;
                        }
                    }
                }
            }
        }

        if(!ok) {
            for(int i = 2; i <= n; ++i) cout << 0;
            cout << '\n';
            return;
        }

        for(int x : s) valid[x] = true;

        for(int i = 2; i <= n; ++i) {
            cout << (valid[i] ? 1 : 0);
        }
        cout << '\n';
    }
}
int main(int argc, char** argv) { 
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); 
    cin >> tc;
    while(tc--) {
        int n,m,k,l;cin >> n >> m >> k >> l;
        vector<int>s,d;
        vector<pair<int,int>>edge;
        s.reserve(k),d.reserve(l),edge.reserve(m);
        for(int i=1,x; i<=k; ++i) {cin >> x;s.pb(x);}
        for(int i=1,x; i<=l; ++i) {cin >> x;d.pb(x);}
        for(int i=1,u,v; i<=m; ++i) {cin >> u >> v;edge.pb({u,v});}
        solver::solve(n,m,k,l,s,d,edge);
    }
    return 0; 
} 
/**/