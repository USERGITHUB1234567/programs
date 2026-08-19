/**/ 
#pragma GCC optimize("O3","Ofast","unroll-loops") 
#include <bits/stdc++.h> 
#define file(name) if(fopen(name".inp", "r")) {freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);} 
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
int x,y,z,n,board[maxn][3];
long long ans=LLONG_MIN;
namespace souptrau{
    int choose[maxn];
    void backtrack(int id, int dx, int dy, int dz) {
        if(id>n) {
            long long sum=0;
            for(int i=1; i<=n; ++i) sum+=board[i][choose[i]];
            ans=max(ans,sum);
            return;
        }
        for(int i=0; i<3; ++i) {
            if(i==0) {
                int ndx=dx+1;
                if(ndx<=x) {choose[id]=i;backtrack(id+1,ndx,dy,dz);}
            }
            else if(i==1) {
                int ndy=dy+1;
                if(ndy<=y) {choose[id]=i;backtrack(id+1,dx,ndy,dz);}
            }
            else {
                int ndz=dz+1;
                if(ndz<=z) {choose[id]=i;backtrack(id+1,dx,dy,ndz);}
            }
        }
    }
    void solve() {
        backtrack(1,0,0,0);
        printf("%lld",ans);
    }
}
namespace soupfull {
    struct row{long long a,b,c;};
    void solve() {
        vector<row>v(n);
        long long base=0;
        for(int i=0; i<n; ++i) {
            v[i].a=board[i+1][0];
            v[i].b=board[i+1][1];
            v[i].c=board[i+1][2];
            base+=v[i].c;
        }
        sort(all(v),[](const row& a, const row& b) {return (a.a-a.b)>(b.a-b.b);});
        vector<long long>f(n+1,0);
        priority_queue<long long ,vector<long long>, greater<long long>>pq;
        long long sumx=0;
        for(int i=0; i<n; ++i) {
            long long val=v[i].a-v[i].c;
            if(x) {
                pq.push(val);
                sumx+=val;
                if(pq.size()>x) {
                    sumx-=pq.top();
                    pq.pop();
                }
            }
            if(i+1>=x) f[i+1]=sumx;
        }
        while(!pq.empty()) pq.pop();
        long long sumy=0;
        vector<long long>g(n+1,0);
        for(int i=n-1; i>=0; --i) {
            long long val=v[i].b-v[i].c;
            if(y) {
                pq.push(val);
                sumy+=val;
                while(pq.size()>y) {
                    sumy-=pq.top();
                    pq.pop();
                }
            }
            if(n-i>=y) g[i]=sumy;
        }
        long long ans=LLONG_MIN;
        for(int i=x; i<=n-y; ++i) ans=max(ans,base+f[i]+g[i]);
        printf("%lld",ans);
    }
}
int main(int argc, char** argv) { 
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); 
    scanf("%d%d%d",&x,&y,&z);
    n=x+y+z;
    for(int i=1; i<=n; ++i) scanf("%d%d%d",&board[i][0],&board[i][1],&board[i][2]);
    soupfull::solve();
    return 0; 

} 
/**/