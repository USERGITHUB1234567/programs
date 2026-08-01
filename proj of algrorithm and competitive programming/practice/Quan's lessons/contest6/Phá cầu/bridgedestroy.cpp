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
int t;
namespace solver{
    vector<int>bridge,vis;
    vector<vector<pair<int,int>>>adj;
    vector<vector<int>>tree;
    vector<int>low,num,d,comp;
    int n,m,ncomp=0,logn,timer=0;
    
    inline void dfs(int u, int p) {
        low[u]=num[u]=++timer;
        for(auto[v,i]:adj[u]) {
            if(i==p) continue;
            if(num[v]) low[u]=min(low[u],num[v]);
            else {
                dfs(v,i);
                low[u]=min(low[v],low[u]);
                if(low[v]>num[u]) bridge[i]=1;
            }
        }
    }
    
    inline void dfs1(int u) {
        comp[u]=ncomp;
        for(auto[v,i]:adj[u]) {
            if(!comp[v] && !bridge[i]) dfs1(v);
        }
    }
    
    void bfs(int st) {
        queue<int>q;
        q.push(st);
        vis[st]=1;
        while(!q.empty()) {
            int u=q.front();q.pop();
            for(int v:tree[u]) {
                if(vis[v]) continue;
                d[v]=d[u]+1;
                q.push(v);
                vis[v]=1;
            }
        }
    }
    
    void solve(int _n, int _m, vector<pair<int,int>>&e) {
        n=_n,m=_m;
        ncomp=0;
        timer=0;
        int ans=0;
        
        bridge.assign(m+1,0);
        adj.assign(n+1, {});
        low.assign(n+1,0);
        num.assign(n+1,0);
        comp.assign(n+1,0);
        
        for(int i=0; i<e.size(); ++i) {
            auto[u,v]=e[i];
            adj[u].pb({v,i+1});
            adj[v].pb({u,i+1});
        } 
        
        for(int i=1; i<=n; ++i) {
            if(!num[i]) dfs(i,0);
        }
        for(int i=1; i<=n; ++i) {
            if(!comp[i]) {++ncomp;dfs1(i);}
        }
        
        if(ncomp==1) {
            cout << 0 << '\n';
            return;
        }
        
        tree.assign(ncomp+1, {});
        d.assign(ncomp+1,0);
        vis.assign(ncomp+1,0);
        
        for(int i=1; i<=e.size(); ++i) {
            if(bridge[i]) {
                ++ans;
                auto[u,v]=e[i-1];
                u=comp[u],v=comp[v];
                tree[u].pb(v);
                tree[v].pb(u);
            }
        }
        
        int p1=1, p2=1, mx=0;
        
        bfs(p1);
        for(int i=1; i<=ncomp; ++i) {
            if(d[i]>mx) {
                p2=i;
                mx=d[i];
            }
        }
        
        d.assign(ncomp+1,0);
        vis.assign(ncomp+1,0);
        
        bfs(p2);
        mx=0;
        for(int i=1; i<=ncomp; ++i) {
            if(d[i]>mx) {
                p1=i;
                mx=d[i];
            }
        }
        
        cout << ans-mx << '\n';
    }
}
int main(int argc, char** argv) { 
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); 
    cin >> t;
    while(t--) {
        int n,m;
        cin >> n >> m;
        vector<pair<int,int>>e(m);
        for(int i=1,u,v; i<=m; ++i) {
            cin >> u >> v;
            e[i-1]={u,v};
        }
        solver::solve(n,m,e);
    }
    return 0; 

} 
/**/
/*
1
7 7
1 2
2 3
3 1
3 4
4 5
4 6
6 7


1
3 3
1 2
2 3
3 1
*/