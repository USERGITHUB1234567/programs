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
const int maxn=11,mod=1000000007,maxb=320; 
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
using namespace utilities; 
mt19937_64 generator1(steady_clock::now().time_since_epoch().count()); 
mt19937_64 generator2(high_resolution_clock::now().time_since_epoch().count()); 
inline long long rnd1(long long a, long long b) {return a+generator1()%(b-a+1);} 
inline long long rnd2(long long a, long long b) {return a+generator2()%(b-a+1);} 
auto imp_st=high_resolution_clock::now(); 
inline void start_timer() {imp_st=high_resolution_clock::now();} 
inline void get_execution_time() { auto imp_en=high_resolution_clock::now(); cerr << "Implementation Time: "<< duration_cast<milliseconds>(imp_en-imp_st).count() << " ms\n"; } 
int t,n;
long long v[maxn];

namespace soup1{
    vector<int>status;
    map<vector<int>,pair<pair<int,int>,vector<int>>>trace;
    //unordered_map<vector<int>,int>d;
    int f(vector<int>&v) {return count(all(v),0);}
    vector<int> bfs(vector<int>&s) {
        queue<vector<int>>q;
        vector<int>res=s;
        int mx=f(s);
        q.push(s);
        int cnt=0;
        while(!q.empty() && cnt<=10000) {
            auto u=q.front();q.pop();
            ++cnt;
            // for(int j:u) cout << j << ' ';
            // cout << '\n';
            // cout << u.size() << '\n';
            for(int i=0; i<u.size(); ++i) {
                for(int j=0; j<u.size(); ++j) {
                    if(i==j) continue;
                    if(u[i]>=u[j] && u[i]!=0) {
                        //cout << 'a';
                        vector<int>v=u;
                        // for(int j:v) cout << j << '\n';
                        // cout << '\n';
                        v[i]-=v[j];v[j]<<=1;
                            if(trace[v].se.size()==0) {
                            trace[v]={{i,j},u};
                            q.push(v);
                        }
                        if(f(v)>mx) {
                            //cout << 'a';
                            mx=f(v);
                            res=v;
                            
                        }
                    }
                }
            }
        }
        return res;
    }
    vector<pair<int,int>>traverse(vector<int>&s) {
        vector<pair<int,int>>res;
        while(s!=status) {
            res.pb(trace[s].fi);
            s=trace[s].se;
        }
        reverse(all(res));
        return res;
    }
    void solve() {
        while(t--) {
            status.clear();
            trace.clear();
            cin >> n;for(int i=1; i<=n; ++i) {cin >> v[i];status.pb(v[i]);}
            vector<int>ans=bfs(status);
            vector<pair<int,int>>res=traverse(ans);
            cout << res.size() << '\n';
            for(auto[u,v]:res) cout << u+1 << ' ' << v+1 << '\n';
        }
    }
}
namespace soupfull{
    vector<pair<long long,int>>bottle;
    vector<pair<int,int>>res;
    long long tv,g=0;
    inline bool check(long long x) {
        while(x>1) {
            if(x&1) return false;
            x>>=1;
        }
        return true;
    }
    int f() {int cnt=0;for(auto[u,v]:bottle)cnt+=(u==1);return cnt;}
    inline void phase1() {
        int p;
        //cerr << 'a';
        for(int i=0; i<bottle.size(); ++i) if(bottle[i].fi!=0) {p=i;break;}
        long long &a=bottle[0+p].fi,b=bottle[1+p].fi,c=bottle[2+p].fi;
        long long q=b/a;
        int &id1=bottle[0+p].se,id2=bottle[1+p].se,id3=bottle[2+p].se;
        int lg=__logarit(2,q);
        for(int i=0; i<lg; ++i) {
            if((1<<i)&q) {
                b-=a;
                a<<=1;
                res.pb({id2,id1});
            }
            else {
                c-=a;
                a<<=1;
                res.pb({id3,id1});
            }
        }
    }
    inline void phase2() {
        if(!check(tv/g)) return;
        while(bottle[n-2].fi && bottle[n-1].fi) {
            if(bottle[n-2].fi>bottle[n-1].fi) swap(bottle[n-2],bottle[n-1]);
            bottle[n-1].fi-=bottle[n-2].fi;
            bottle[n-2].fi<<=1;
            res.pb({bottle[n-1].se,bottle[n-2].se});
        }
    }
    void solve() {
        while(t--) {
            cin >> n;
            bottle.clear();res.clear();
            bottle.reserve(n);
            for(int i=1; i<=n; ++i) {cin >> v[i];bottle.pb({v[i],i});tv+=v[i];g=__uiagcd(g,v[i]);}
            while(!(g&1)) g>>=1;
            while(f()>n-2) {sort(all(bottle));phase1();}
            phase2();
            cout << res.size() << '\n';
            for(auto[u,v]:res) cout << u << ' ' << v << '\n';
        }
    }
}
int main(int argc, char** argv) { 
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); 
    cin >> t;
    soupfull::solve();
    return 0; 

} 
/**/
/*
2
3
1 2 3
4
1 1 1 1

1
3
1 2 3

*/