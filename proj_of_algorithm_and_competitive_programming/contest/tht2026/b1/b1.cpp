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
const int maxn=300005,mod=1000000007,maxb=320; 
namespace mathematics{ 
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
} 
using namespace mathematics; 
mt19937_64 generator1(steady_clock::now().time_since_epoch().count()); 
mt19937_64 generator2(high_resolution_clock::now().time_since_epoch().count()); 
inline long long rnd1(long long a, long long b) {return a+generator1()%(b-a+1);} 
inline long long rnd2(long long a, long long b) {return a+generator2()%(b-a+1);} 
auto imp_st=high_resolution_clock::now(); 
inline void start_timer() {imp_st=high_resolution_clock::now();} 
inline void get_execution_time() { auto imp_en=high_resolution_clock::now(); cerr << "Implementation Time: "<< duration_cast<milliseconds>(imp_en-imp_st).count() << " ms\n"; } 
int t;
pair<int,int>query[maxn];
unordered_map<int,int>ump;
struct segment_tree{
    int st[maxn<<2],laz[maxn<<2];
    segment_tree() {
        memset(st,0,sizeof(st));
        memset(laz,-1,sizeof(laz));
    }
    inline void down(int id, int l, int r) {
        if((id<<1)>(maxn<<2) || laz[id]==-1) return;
        int t=laz[id],mid=(l+r)>>1;
        st[id<<1]=t*(mid-l+1);
        st[id<<1|1]=t*(r-mid);
        laz[id<<1]=t;
        laz[id<<1|1]=t;
        laz[id]=-1;
    }
    void update(int id, int l, int r, int i, int v) {
        down(id,l,r);
        if(l>i || r<i) return;
        if(l==r) {
            st[id]+=v;
            return;
        }
        int mid=(l+r)>>1;
        if(i<=mid) update(id<<1,l,mid,i,v);
        else update(id<<1|1,mid+1,r,i,v);
        st[id]=st[id<<1]+st[id<<1|1];
    }
    void update_range(int id, int l, int r, int i, int j, int v) {
        down(id,l,r);
        if(l>j || r<i) return;
        if(l>=i && r<=j) {
            st[id]=v;
            laz[id]=v;
            return;
        }
        int mid=(l+r)>>1;
        if(i<=mid) update_range(id<<1,l,mid,i,j,v);
        if(j>mid) update_range(id<<1|1,mid+1,r,i,j,v);
        st[id]=st[id<<1]+st[id<<1|1];
    }
    int query(int id, int l, int r, int i, int j) {
        down(id,l,r);
        if(l>j || r<i) return 0;
        if(l>=i && r<=j) return st[id];
        int mid=(l+r)>>1;
        return query(id<<1,l,mid,i,j)+query(id<<1|1,mid+1,r,i,j);
    }
}seg;
struct fenwick_tree{
    int ft[maxn];
    inline int sum(int i) {
        int res=0;
        while(i>0) {
            res+=ft[i];
            i-=i&-i;
        }
        return res;
    }
    inline void upd(int i, int v) {
        while(i<=t) {
            ft[i]+=v;
            i+=i&-i;
        }
    }
}fen;
namespace alternative{
    void solve() {
        //cin >> t;
        vector<int>val;
        for(int i=1; i<=t; ++i) {val.pb(query[i].se);}
        sortunique(val);
        for(int i=0; i<val.size(); ++i) {
            ump[val[i]]=i+1;
        }
        int mn=0;
        for(int i=1; i<=t; ++i) {
            auto[tq,h]=query[i];
            h=ump[h];
            //cout << h << ' ' ;
            //seg.update(1,1,t,h,1);
            if(tq==2) {
                int cur=mn;
                mn+=max(fen.sum(h)-mn,0);
            }
            else {
                fen.upd(h,1);
            }
            cout << fen.sum(t)-mn << '\n';
        }
    }
}
int main(int argc, char** argv) { 
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); 
    cin >> t;
    vector<int>val;
    for(int i=1; i<=t; ++i) {cin >> query[i].fi >> query[i].se;val.pb(query[i].se);}
    sortunique(val);
    for(int i=0; i<val.size(); ++i) {
        ump[val[i]]=i+1;
    }
    for(int i=1; i<=t; ++i) {
        auto[tq,h]=query[i];
        h=ump[h];
        //cout << h << ' ' ;
        //seg.update(1,1,t,h,1);
        if(tq==1) {
            seg.update(1,1,t,h,1);
        }
        else {
            seg.update_range(1,1,t,1,h,0);
        }
        cout << seg.query(1,1,t,1,t) << '\n';
    }
    // seg.update(1,1,5,2,1);
    // seg.update(1,1,5,3,1);
    // seg.update(1,1,5,4,1);
    // seg.update_range(1,1,5,1,3,0);
    // seg.update(1,1,5,1,1);
    // cout << seg.query(1,1,5,1,5);
    // cout << '\n';
    // alternative::solve();
    return 0; 

} 
/**/
/*
5
1 5
1 7
1 8
2 7
1 3
*/