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
const int maxn=51,mod=1000000007,maxb=320; 
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
int n,a[maxn],b[maxn];
class dinitz{
    private:
        struct edge{int to,rev,cap,flow;};
        int n;
        vector<int>d,ptr;
    public:
    vector<vector<edge>>g;
        dinitz(int _n=0) {init(_n);}
        inline void init(int _n) {
            n=_n;
            g.assign(n,{});
            d.assign(n,0);
            ptr.assign(n,0);
        }
        inline void add(int u, int v, int c) {
            edge a{v,(int)g[v].size(),c,0},b{u,(int)g[u].size(),0,0};
            g[u].pb(a);g[v].pb(b);
        }
        bool bfs(int s, int t) {
            fill(all(d),-1);
            queue<int>q;
            d[s]=0;
            q.push(s);
            while(!q.empty()) {
                int u=q.front();q.pop();
                for(auto[to,rev,cap,flow]:g[u]) {
                    if(d[to]==-1 && flow<cap) {
                        d[to]=d[u]+1;
                        q.push(to);
                    }
                }
            }
            return d[t]!=-1;
        }
        int dfs(int u, int t, int f) {
            if(!f || u==t) return f;
            for(;ptr[u]<g[u].size(); ++ptr[u]) {
                auto[to,rev,cap,flow]=g[u][ptr[u]];
                if(d[to]==d[u]+1 && flow<cap) {
                    int push=dfs(to,t,min(f,cap-flow));
                    if(push) {
                        g[u][ptr[u]].flow+=push;
                        g[to][rev].flow-=push;
                        return push;
                    }
                }
            }
            return 0;
        }
        long long maxflow(int s, int t) {
            long long ans=0;
            while(bfs(s,t)) {
                fill(all(ptr),0);
                while(int push=dfs(s,t,INT_MAX)) ans+=push;
            }
            return ans;
        }
};
int main(int argc, char** argv) { 
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); 
    cin >> n;
    long long sa=0,sb=0;
    for(int i=0; i<n; ++i) {cin >> a[i];sa+=a[i];}
    for(int i=0; i<n; ++i) {cin >> b[i];sb+=b[i];}
    if(sa!=sb) {cout << -1;return 0;}
    int s=(n<<1),t=(n<<1)+1;
    dinitz d((n<<1)+2);
    for(int i=0; i<n; ++i) d.add(s,i,a[i]);
    for(int i=0; i<n; ++i) d.add(n+i,t,b[i]);
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) d.add(i,n+j,1);
    }
    long long flow=d.maxflow(s,t);
    if(flow!=sa) {cout << -1;return 0;}
    vector<string>ans(n,string(n,'.'));
    for(int i=0; i<n; ++i) {
        for(auto &e:d.g[i]) {
            if(n<=e.to && e.to<(n<<1) && e.flow==1) {int j=e.to-n;ans[i][j]='X';}
        }
    }
    for(int i=0; i<n; ++i) cout << ans[i] << '\n';
    return 0; 

} 
/**/