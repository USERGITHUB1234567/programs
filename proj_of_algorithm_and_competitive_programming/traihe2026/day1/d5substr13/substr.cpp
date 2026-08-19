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
int n,m,k,szx,szy,nx[202][26],ny[202][26];
long long f[202][202][202];
string x,y,s[202];
long long process(int id, int px, int py) {
    if(id>n) {return py==szy+1;}
    if(f[id][px][py]!=-1) return f[id][px][py];
    long long res=0;
    for(int c=0; c<26; ++c) {
        int npx=nx[px][c];
        if(npx==szx+1) continue;
        int npy=ny[py][c];
        res=(res+process(id+1,npx,npy))%k;
    }
    return f[id][px][py]=res;
}
int main(int argc, char** argv) { 
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); 
    memset(f,-1,sizeof(f));
    cin >> m >> n >> k >> x >> y;
    for(int i=1; i<=m; ++i) cin >> s[i];
    szx=x.size(),szy=y.size();
    for(int i=0; i<=szx+1; ++i) fill(nx[i],nx[i]+26,szx+1);
    for(int i=1; i<=szy+1; ++i) fill(ny[i],ny[i]+26,szy+1);
    for(int i=szx-1; i>=0; --i) {
        for(int j=0; j<26; ++j) {
            nx[i][j]=nx[i+1][j];
        }
        nx[i][x[i]-'a']=i+1;
    }
    for(int i=szy-1; i>=0; --i) {
        for(int j=0; j<26; ++j) ny[i][j]=ny[i+1][j];
        ny[i][y[i]-'a']=i+1;
    }
    //cout << ny[2][1];
    for(int i=1; i<=m; ++i) {
        long long ans=1;
        int px=0,py=0;
        bool ck=true;
        for(char c:s[i]) {
            px=nx[px][c-'a'],py=ny[py][c-'a'];
            if(px==szx+1) {ck=false;break;}
        }
        if(!ck || py!=szy+1) {cout << -1 << '\n';continue;}
        px=0,py=0;
        for(int j=0; j<n; ++j) {
            int t=s[i][j]-'a';
            for(int c=0; c<t; ++c) {
                int npx=nx[px][c],npy=ny[py][c];
                if(npx==szx+1) continue;
                ans=(ans+process(j+2,npx,npy))%k;
            }
            px=nx[px][t],py=ny[py][t];
        }
        cout << ans << '\n';
    }
    return 0; 

} 
/**/