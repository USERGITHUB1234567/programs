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
const int maxn=500005,mod=1000000007,maxb=320; 
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
int n;
pair<int,int>toy[maxn];
namespace souptrau{
    void solve() {
        int ans=INT_MAX,fm=(1<<n);
        for(int mask=0; mask<fm; ++mask) {
            int t=__builtin_popcount(mask);
            if(t==0 || t==n) continue;
            int mna=1e9,mxa=-1e9,mxb=-1e9,mnb=1e9;
            for(int i=0; i<n; ++i) {
                if((1<<i)&mask) {
                    mna=min(mna,toy[i+1].fi);
                    mxa=max(mxa,toy[i+1].fi);
                }
                else {
                    mnb=min(mnb,toy[i+1].se);
                    mxb=max(mxb,toy[i+1].se);
                }
            }
            ans=min(ans,(mxa-mna)+(mxb-mnb));
        }
        printf("%d",ans);
    }
}
namespace soup3{
    int sufmin[maxn],sufmax[maxn],premin[maxn],premax[maxn];
    void solve() {
        int ans=INT_MAX;
        sort(toy+1,toy+1+n);
        sufmin[n]=toy[n].se;sufmax[n]=toy[n].se;
        for(int i=n-1; i>=2; --i) {
            sufmin[i]=min(sufmin[i+1],toy[i].se);
            sufmax[i]=max(sufmax[i+1],toy[i].se);
        }
        premin[0]=INT_MAX;
        premax[0]=INT_MIN;
        for(int i=1; i<n; ++i) {
            premin[i]=min(premin[i-1],toy[i].se);
            premax[i]=max(premax[i-1],toy[i].se);
        }
        for(int l=1; l<=n; ++l) {
            for(int r=l; r<=n; ++r) {
                if(l==1 && r==n) continue;
                int pmx=premax[l-1],pmn=premin[l-1],smx=sufmax[r+1],smn=sufmin[r+1];
                int mx=max(pmx,smx),mn=min(pmn,smn);
                ans=min(ans,(mx-mn)+(toy[r].fi-toy[l].fi));
                //cerr << ans << '\n';
                ///cerr << pmn << ' ' << pmx << ' ' << smn << ' ' << smx << ' ' << mn << ' ' << mx << ' ' << l << ' ' << r << ' ' << toy[r].fi << ' ' << toy[l].fi << ' ' << ans << '\n';
            }
        }
        sort(toy+1,toy+1+n,[](pair<int,int>a,pair<int,int>b){return a.se<b.se;});
        sufmin[n]=toy[n].fi;sufmax[n]=toy[n].fi;
        for(int i=n-1; i>=2; --i) {
            sufmin[i]=min(sufmin[i+1],toy[i].fi);
            sufmax[i]=max(sufmax[i+1],toy[i].fi);
        }
        premin[0]=INT_MAX;
        premax[0]=INT_MIN;
        for(int i=1; i<n; ++i) {
            premin[i]=min(premin[i-1],toy[i].fi);
            premax[i]=max(premax[i-1],toy[i].fi);
        }
        for(int l=1; l<=n; ++l) {
            for(int r=l; r<=n; ++r) {
                if(l==1 && r==n) continue;
                int pmx=premax[l-1],pmn=premin[l-1],smx=sufmax[r+1],smn=sufmin[r+1];
                int mx=max(pmx,smx),mn=min(pmn,smn);
                ans=min(ans,(mx-mn)+(toy[r].se-toy[l].se));
                //cerr << ans << '\n';
                ///cerr << pmn << ' ' << pmx << ' ' << smn << ' ' << smx << ' ' << mn << ' ' << mx << ' ' << l << ' ' << r << ' ' << toy[r].fi << ' ' << toy[l].fi << ' ' << ans << '\n';
            }
        }
        printf("%d",ans);
    }
}
namespace soupfull{
    int sufmin[maxn],sufmax[maxn],premin[maxn],premax[maxn];
    int f(int l, int r) {
        int ans=INT_MAX;
        if(l==1 && r==n) return INT_MAX;
        int pmx=premax[l-1],pmn=premin[l-1],smx=sufmax[r+1],smn=sufmin[r+1];
        int mx=max(pmx,smx),mn=min(pmn,smn);
        ans=min(ans,(mx-mn)+(toy[r].se-toy[l].se));
        return ans;
    }
    void solve() {
        int ans=INT_MAX;
        sort(toy+1,toy+1+n);
        sufmin[n]=toy[n].se;sufmax[n]=toy[n].se;
        for(int i=n-1; i>=2; --i) {
            sufmin[i]=min(sufmin[i+1],toy[i].se);
            sufmax[i]=max(sufmax[i+1],toy[i].se);
        }
        premin[0]=INT_MAX;
        premax[0]=INT_MIN;
        for(int i=1; i<n; ++i) {
            premin[i]=min(premin[i-1],toy[i].se);
            premax[i]=max(premax[i-1],toy[i].se);
        }
        for(int i=1; i<=n; ++i) {
            int l=1,r=i;
            while(l<r) {
                int mid=(l+r)>>1;
                if(f(mid,i)<f(mid+1,i)) r=mid;
                else l=mid+1;
            }
            ans=min(ans,f(l,i));
            //cerr << l << ' ' << i << ' ' << ans << '\n';
            
        }
        //cerr << f(1,2) << '\n';
        sort(toy+1,toy+1+n,[](pair<int,int>a,pair<int,int>b){return a.se<b.se;});
        sufmin[n]=toy[n].fi;sufmax[n]=toy[n].fi;
        for(int i=n-1; i>=2; --i) {
            sufmin[i]=min(sufmin[i+1],toy[i].fi);
            sufmax[i]=max(sufmax[i+1],toy[i].fi);
        }
        premin[0]=INT_MAX;
        premax[0]=INT_MIN;
        for(int i=1; i<n; ++i) {
            premin[i]=min(premin[i-1],toy[i].fi);
            premax[i]=max(premax[i-1],toy[i].fi);
        }
        for(int i=1; i<=n; ++i) {
            int l=1,r=i;
            while(l<r) {
                int mid=(l+r)>>1;
                if(f(mid,i)<f(mid+1,i)) r=mid;
                else l=mid+1;
            }
            ans=min(ans,f(l,i));
        }
        printf("%d",ans);
    }
}
int main(int argc, char** argv) { 
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); 
    scanf("%d",&n);for(int i=1; i<=n; ++i) scanf("%d%d",&toy[i].fi,&toy[i].se);
    if(n<=20) souptrau::solve();
    else if(n<=2000) soup3::solve();
    else soupfull::solve();
    //soupfull::solve();
    return 0; 

} 
/**/
/*
0 0
1 1
3 4
5 5

*/