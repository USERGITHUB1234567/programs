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
const int maxn=400005,mod=1000000007,maxb=320; 
namespace mathematics{ 
    long long fact[maxn],ifact[maxn]; 
    long long __gcd(long long a, long long b) { if(a<b) swap(a,b); while(a%b!=0) {long long c=a%b;a=b,b=c;} return b; } 
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
int n,ans[maxn];
struct time_range{
    long long x,y,id;
    bool operator<(time_range o) {return x<o.x || (x==o.x && y>o.y);}
}t[maxn];
namespace soup2{
    /// @brief 
    void solve() {
        sort(t+1,t+1+n,[](time_range a, time_range b) {return a<b;});
        for(int i=1; i<=n; ++i) {
            int y=t[i].y,cur=ans[t[i].id];
            for(int j=i+1; j<=n; ++j) {
                if(t[j].y>y) continue;
                ans[t[j].id]=max(ans[t[j].id],1+cur);
            }
        }
        for(int i=1; i<=n; ++i) {cout << ans[i] << (i<n?" ":"");}
    }
}
struct segment_tree{
    const int segsz=maxn<<2;
    int st[maxn<<2],laz[maxn<<2];
    segment_tree() {memset(st,-1,sizeof(st));memset(laz,-1,sizeof(laz));}
    inline void down(int id) {
        int l=laz[id];
        if((id<<1)>segsz) return; 
        st[id<<1]=max(st[id<<1],l);
        st[id<<1|1]=max(st[id<<1|1],l);
        laz[id<<1]=max(laz[id<<1],l);
        laz[id<<1|1]=max(laz[id<<1|1],l);
        laz[id]=-1;
    }
    inline void update(int id, int l, int r, int i, int j, int v) {
        down(id);
        if(l>j || r<i) return;
        if(l>=i && r<=j) {
            //cout << id << ' ' << l << ' ' << r << '\n';
            st[id]=max(st[id],v);
            laz[id]=max(laz[id],v);
            return;
        }
        int mid=(l+r)>>1;
        if(i<=mid) update(id<<1,l,mid,i,j,v);
        if(j>mid) update(id<<1|1,mid+1,r,i,j,v);
        st[id]=min(st[id<<1],st[id<<1|1]);
    }
    inline int query(int id, int l, int r, int i, int j) {
        down(id);
        if(l>j || r<i) return INT_MAX;
        if(l>=i && r<=j) {
            //cout << id << ' ' << st[id] << ' ' << l << ' ' << r << '\n';
            return st[id];
        }
        int mid=(l+r)>>1;
        return min(query(id<<1,l,mid,i,j),query(id<<1|1,mid+1,r,i,j));
    }
}seg;
namespace soupfull{
    void solve() {
        sort(t+1,t+1+n,[](time_range a, time_range b) {return a<b;});
        memset(ans,0,sizeof(ans));
        vector<int>val;
        unordered_map<int,int>ump;
        for(int i=1; i<=n; ++i) {
            int u=t[i].x,v=t[i].y;
            val.pb(u),val.pb(v);
        }
        sortunique(val);
        int m=0;
        for(int i=0; i<val.size(); ++i) {
            ump[val[i]]=i+1;
        }
        m=val.size();
        for(int i=1; i<=n; ++i) {
            int j=t[i].id,x=ump[t[i].x],y=ump[t[i].y];
            int k=seg.query(1,1,m,x,y);
            ans[j]=max(ans[j],1+k);
            //cout << k << ' ' << ans[j] << ' ' << x << ' ' << y << '\n';
            seg.update(1,1,m,x,y,ans[j]);
        }
        for(int i=1; i<=n; ++i) {cout << ans[i] << (i<n?" ":"");}
        //k1.clear();
        // seg.update(1,1,m,1,8,0);
        // cout << seg.query(1,1,m,8,10);
        // for(int i=1; i<=20; ++i) cout << seg.st[i] << ' ';
    }
}
// namespace check{
//     void solve() {
//         for(int i=1; i<=100; ++i) {
//             system("g++ -std=c++23 test.cpp -o prog");
//             system("./prog");
//             cerr << (k1==k2?"AC":"WA") << '\n';
//         }
//     }
// }
int main(int argc, char** argv) { 
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); 
    file("justice")
    cin >> n;
    for(int i=1; i<=n; ++i) {
        int u,v;cin >> u >> v;
        t[i]={u,u+v,i};
    }
    // soup2::solve();
    // cout << '\n';
    // soupfull::solve();
    // cout << '\n';
    //check::solve();
    if(n<=1000) soup2::solve();
    else soupfull::solve();
    //soupfull::solve();
    return 0; 

} 
/**/
/*
4
2 8
1 7
4 5
5 2

5
2 4
3 3
2 2
4 2
4 1
*/