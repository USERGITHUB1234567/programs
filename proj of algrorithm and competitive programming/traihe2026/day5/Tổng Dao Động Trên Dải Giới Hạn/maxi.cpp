// fix and complete the program to solve
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
const int maxn=200005,mod=1000000007,maxb=320; 
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
int n,q;
long long a[maxn],s0[maxn],s1[maxn],s2[maxn];
long long gets0(int l, int r) {
    long long ans=s0[r]-(l>0?s0[l-1]:0);
    return ans<0?ans+mod:ans;
}
long long gets1(int l, int r) {
    long long ans=s1[r]-(l>0?s1[l-1]:0);
    return ans<0?ans+mod:ans;
}
long long gets2(int l, int r) {
    long long ans=s2[r]-(l>0?s2[l-1]:0);
    return ans<0?ans+mod:ans;
}
class segment_tree{
    private:
        struct node{long long mul,sum0,sum1,sum2,laz;};
        node unite(const node& a, const node& b) {
            node res;
            res.mul=a.mul*b.mul%mod;
            res.sum0=(a.sum0+b.sum0)%mod;
            res.sum1=(a.sum1+b.sum1)%mod;
            res.sum2=(a.sum2+b.sum2)%mod;
            res.laz=-1;
            return res;
        }
        node st[maxn<<2];
    public:
        void build(int id, int l, int r) {
            st[id].laz=-1;
            if(l==r) {
                //st[id]={a[l]%mod,((a[l]+1)*500000004)%mod,l^2,l};
                long long v=a[l]%mod;
                st[id].sum0=v;
                st[id].sum1=v*l%mod;
                st[id].sum2=v*l%mod*l%mod;
                st[id].mul=(v+1)%mod;
                return;
            }
            int mid=(l+r)>>1;
            build(id<<1,l,mid);
            build(id<<1|1,mid+1,r);
            st[id]=unite(st[id<<1],st[id<<1|1]);
        }
        void apply(int id, int l, int r, long long v) {
            st[id].laz=v;
            long long vm=v%mod;
            st[id].sum0=vm*gets0(l,r)%mod;
            st[id].sum1=vm*gets1(l,r)%mod;
            st[id].sum2=vm*gets2(l,r)%mod;
            st[id].mul=modexp((vm+1)%mod,r-l+1,mod);
        }
        void push_down(int id, int l, int r) {
            if(st[id].laz!=-1) {
                int mid=(l+r)>>1;
                apply(id<<1,l,mid,st[id].laz);
                apply(id<<1|1,mid+1,r,st[id].laz);
                st[id].laz=-1;
            }
        }
        void update(int id, int l, int r, int i, int j, long long v) {
            if(l>=i && r<=j) {apply(id,l,r,v);return;}
            push_down(id,l,r);
            int mid=(l+r)>>1;
            if(i<=mid) update(id<<1,l,mid,i,j,v);
            if(j>mid) update(id<<1|1,mid+1,r,i,j,v);
            st[id]=unite(st[id<<1],st[id<<1|1]);
        }
        node query(int id, int l, int r, int i, int j) {
            if(l>=i && r<=j) return st[id];
            push_down(id,l,r);
            int mid=(l+r)>>1;
            if(j<=mid) return query(id<<1,l,mid,i,j);
            if(i>mid) return query(id<<1|1,mid+1,r,i,j);
            return unite(query(id<<1,l,mid,i,j),query(id<<1|1,mid+1,r,i,j));
        }
}seg;
int main(int argc, char** argv) { 
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); 
    cin >> n >> q;
    for(int i=0; i<n; ++i) cin >> a[i];
    s0[0]=1;
    for(int i=1; i<=n; ++i) {
        s0[i]=(s0[i-1]+1)%mod;
        s1[i]=(s1[i-1]+i)%mod;
        s2[i]=(s2[i-1]+1ll*i*i%mod)%mod;
    }
    seg.build(1,0,n-1);
    while(q--) {
        int type,l,r,v;
        cin >> type;
        if(type==1) {
            cin >> l >> r >> v;
            //++l,++r;
            seg.update(1,0,n-1,l,r,v);
        }
        else {
            cin >> l >> r;
            auto res=seg.query(1,0,n-1,l,r);
            long long t1=(mod-res.sum2)%mod,rl=(l+r)%mod,t2=rl*res.sum1%mod,ct=(1ll*(r+1))%mod*((l-1+mod)%mod)%mod,t3=(mod-ct)%mod*res.sum0%mod;
            long long sum=(t1+t2+t3)%mod;
            long long ans=sum*res.mul%mod;
            ans=ans*500000004%mod;
            cout << ans << '\n';
        }
    }
    return 0; 

} 
// fomular:-i^2 + (r+l)i - (r+1)(l-1)
/**/