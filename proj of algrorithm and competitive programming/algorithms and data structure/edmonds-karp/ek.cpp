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
const int maxn=1003,mod=1000000007,maxb=320; 
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
int n,m;
vector<int>adj[maxn];
class edmonds_karp{
    private:
        int c[maxn][maxn],f[maxn][maxn],trace[maxn],maxflow=0,s,t,n;
vector<vector<int>>ans;
    public:
        edmonds_karp(int _n):n(_n){s=1,t=n; memset(c,0,sizeof(c)); memset(f,0,sizeof(f));}
        inline void change(int &u,int &v, int k) {c[u][v]=k;}
        inline bool check() {return trace[t]!= 0;}

        void bfs() {
            fill(trace+1,trace+1+n,0);
            trace[s]=-1;
            queue<int>q;
            q.push(s);
            while(!q.empty()) {
                int u=q.front();q.pop();
                for(int v:adj[u]) {
                    if(trace[v] || f[u][v]-c[u][v]==0) continue;
                    trace[v]=u;
                    q.push(v);
                }
            }
        }
        inline void increase() {
            int delta=INT_MAX;
            int v=t;
            while(v!=s) {
                int u=trace[v];
                delta=min(delta,c[u][v]-f[u][v]);
                v=u;
            }
            maxflow+=delta;
            v=t;
            while(v!=s) {
                int u=trace[v];
                f[u][v]+=delta;
                f[v][u]-=delta;
                //path.push_back(v);
                v=u;
            }

        }
        vector<vector<int>>res() {
            for(int i=1; i<=maxflow; ++i) {
                vector<int>path;
                int u=s;
                path.pb(u);
                while(u!=t) {
                    bool ck=false;
                    for(int v:adj[u]) {
                        if(c[u][v]>0 && f[u][v]>0) {--f[u][v];u=v;path.pb(u);ck=true;break;}
                    }
                    if(!ck) break;
                }
                ans.pb(path);
            }
            return ans;
    }
};
int main(int argc, char** argv) { 
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); 
    cin >> n >> m;
    //s=1,t=n;
    edmonds_karp ed(n);
    for(int i=1,u,v; i<=m; ++i) {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
        ed.change(u,v,1);
    }
    while(true) {
        ed.bfs();
        if(!ed.check()) break;
        ed.increase();
    }
    vector<vector<int>>ans=ed.res();
    cout << ans.size() << '\n';
    for(int i=0; i<ans.size(); ++i) {
        cout << ans[i].size() << '\n';
        for(int j:ans[i]) cout << j << ' ';
        cout << '\n';
    }
    return 0; 

} 
/**/