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
    vector<int>dist,cnt,usefuld;
    vector<vector<int>>adj;
    vector<bool>f[2],flower,dest;
    void bfs(int st) {
        queue<int>q;
        q.push(st);
        dist[st]=0;
        //++cnt[0];
        while(!q.empty()) {
            int u=q.front();q.pop();
            //cerr << u << ' ' << dist[u] << '\n';
            for(int v:adj[u]) {
                if(v!=st && dist[v]==0) {dist[v]=dist[u]+1;q.push(v);}
            }
        }
    }
    void solve(int& n, int& m, int& k, int& l, vector<int>&s, vector<int>&d, vector<pair<int,int>>&edge) {
        dist.assign(n+1,0);
        cnt.assign(n,0);
        adj.assign(n+1,vector<int>{});
        usefuld.clear();
        for(auto[u,v]:edge) {adj[u].pb(v),adj[v].pb(u);}
        for(int i=0; i<2; ++i) f[i].assign(n+1,false);
        bfs(1);
        int mxs=0;
        flower.assign(n+1,false);
        dest.assign(n+1,false);
        for(int i:s) {
            ++cnt[dist[i]];
            //cerr << cnt[d[i]] << ' ' << d[i] << ' ' << i;
            flower[i]=true;
            mxs=max(mxs,dist[i]);
            if(cnt[dist[i]]>1) {
                for(int i=1; i<n; ++i) cout << 0;
                cout << '\n';
                return;
            }
        }
        for(int i:d) {if(dist[i]>mxs) {usefuld.pb(i);dest[i]=true;}}
        if(usefuld.size()==0) {for(int i=1; i<=n; ++i) {cout << 0;}cout << '\n';return;}
        vector<bool>vis(n+1,false);
        auto bfsroot=[&](int st)->void {
            queue<int>q;
            q.push(st);
            vis[st]=true;
            f[0][st]=true;
            while(!q.empty()) {
                int u=q.front();q.pop();
                //if(vis[u]) continue;
                //cerr << u << ' ' << cnt[d[u]] << '\n';
                for(int v:adj[u]) {
                    if(cnt[dist[v]] && !flower[v]) {f[0][v]=false;}
                    else if(cnt[dist[v]] && flower[v]) {f[0][v]=true;if(!vis[v]){q.push(v),vis[v]=true;}}
                    else {
                        f[0][v]=true;
                        if(!vis[v]) {q.push(v),vis[v]=true;}
                    }
                }
            }
        };
        
        //cerr << vis[6] << '\n';
        auto bfsdest=[&](const vector<int>&st)->void{
            queue<int>q;fill(all(vis),false);
            //for(int i=1; i<=n; ++i) cerr << vis[i] << ' ' ;
            for(int i:st) {q.push(i);vis[i]=true;f[1][i]=true;}
            while(!q.empty()) {
                int u=q.front();q.pop();
                //cerr << u << ' ';
                for(int v:adj[u]) {
                    if(cnt[dist[v]] && !flower[v]) {f[1][v]=false;}
                    else if(cnt[dist[v]] && flower[v]) {f[1][v]=true;if(!vis[v]) {q.push(v);vis[v]=true;}}
                    else {
                        //cerr << vis[v] << ' ' << v << '\n';
                        f[1][v]=true;
                        if(!vis[v]) {q.push(v);vis[v]=true;}
                    }
                }
            }
        };
        bfsroot(1);
        bfsdest(usefuld);
        //cerr << d[8] << ' ' << cnt[3] << '\n';
        for(int i=1; i<=n; ++i) {
            cout << (f[0][i]&&f[1][i]?1:0);
            //cout << f[0][i] << ' ' << f[1][i] << '\n';
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