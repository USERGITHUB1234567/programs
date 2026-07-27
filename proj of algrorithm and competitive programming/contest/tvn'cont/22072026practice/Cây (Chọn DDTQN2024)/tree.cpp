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
int n,m,k,logn,d[maxn],up[maxn][21],tin[maxn],tout[maxn],timer,mk[maxn],dif[maxn],ans[maxn];
vector<pair<int,int>>adj[maxn];
void dfs_lca(int u, int p) {
    tin[u]=++timer;
    for(auto[v,i]:adj[u]) {
        if(v==p) continue;
        d[v]=d[u]+1;
        up[v][0]=u;
        mk[v]=i;
        for(int i=1; i<=logn; ++i) up[v][i]=up[up[v][i-1]][i-1];
        dfs_lca(v,u);
    }
    
    tout[u]=++timer;
}
bool ancestor(int u, int v) {
    if(!u) return true;
    return tin[u]<=tin[v] && tout[u]>=tout[v];
}
int get_lca(int u, int v) {
    if(ancestor(u,v)) return u;
    if(ancestor(v,u)) return v;
    for(int i=logn; i>=0; --i) {
        if(up[u][i]!=0 && !ancestor(up[u][i],v)) u=up[u][i];
    }
    return up[u][0];
}
void add_edge(int u, int v) {
    ++dif[v];
    --dif[u];
}
void dfs_sum(int u, int p) {
    for(auto[v,i]:adj[u]) {
        if(v!=p) {
            dfs_sum(v,u);
            dif[u]+=dif[v];
        }
    }
    if(u!=1) ans[mk[u]]=dif[u];
}
int main(int argc, char** argv) { 
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); 
    cin >> n >> m >> k;
    for(int i=1,u,v; i<n; ++i) {
        cin >> u >> v;
        adj[u].pb({v,i});
        adj[v].pb({u,i});
    }
    logn=32-__builtin_clz(n);
    tin[0]=0;tout[0]=1000000000;
    dfs_lca(1,0);
    for(int i=1; i<=m; ++i) {
        int s;cin >> s;
        vector<int>node(s);
        for(int j=0; j<s; ++j) cin >> node[j];
        sort(all(node),[](int a, int b) {return tin[a]<tin[b];});
        //node.erase(unique(all(node)),node.end());
        vector<int>st;
        if(node.empty()) continue;
        st.push_back(node[0]);
        for(int j=1; j<node.size(); ++j) {
            int u=node[j],lca=get_lca(st.back(),u);
            while(st.size()>1 && d[st[st.size()-2]]>=d[lca]) {
                add_edge(st[st.size()-2],st.back());
                st.pop_back();
            }
            if(st.back()!=lca) {
                add_edge(lca,st.back());
                st.pop_back();
                st.push_back(lca);
            }
            st.push_back(u);
        }
        while(st.size()>1) {
            add_edge(st[st.size()-2],st.back());
            st.pop_back();
        }
    }
    dfs_sum(1,0);
    vector<int>res;
    for(int i=1; i<n; ++i) {
        if(ans[i]>=k) res.pb(i);
    }
    cout << res.size() << '\n';
    for(int i:res) cout << i << ' ';
    return 0; 

} 
/**/