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
const int maxn=200005,mod=1000000007,maxb=320;
long long fact[maxn],ifact[maxn];
inline int maxi(int a, int b) {return (a>b?a:b);}
inline int mini(int a, int b) {return (a<b?a:b);}
inline ll maxill(ll a, ll b) {return (a>b?a:b);}
inline ll minill(ll a, ll b) {return (a<b?a:b);}
inline double maxid(double a, double b) {return (a>b?a:b);}
inline double minid(double a, double b) {return (a<b?a:b);}
inline ld maxild(ld a, ld b) {return (a>b?a:b);}
inline ld minild(ld a, ld b) {return (a<b?a:b);}
inline ll modexp(ll b, ll e, ll m) {
    ll res=1%m;
    while(e>0) {
        if(e&1) res=(res*b)%m;
        b=(b*b)%m;
        e>>=1;
    }
    return res;
}
inline ll logarit(ll k, ll n){ll res=0;while(n>0){n/=k;++res;}return res;}
void setupfactor() {
    fact[0]=1;
    for(int i=1; i<maxn; ++i) fact[i]=fact[i-1]*i%mod;
    int tc=maxn-1;
    ifact[tc]=modexp(fact[tc],mod-2,mod);
    for(int i=tc; i>=1; --i) ifact[i-1]=ifact[i]*i%mod; 
}
inline long long ncr(long long k, long long n) {return (k==n?1:fact[n]*ifact[n-k]%mod*ifact[k]%mod);}
mt19937_64 generator1(steady_clock::now().time_since_epoch().count());
mt19937_64 generator2(high_resolution_clock::now().time_since_epoch().count());
inline long long rnd1(long long a, long long b) {return a+generator1()%(b-a+1);}
inline long long rnd2(long long a, long long b) {return a+generator2()%(b-a+1);}
auto imp_st=high_resolution_clock::now();
inline void start_timer() {imp_st=high_resolution_clock::now();}
inline void get_execution_time() {
    auto imp_en=high_resolution_clock::now();
    cerr << "Implementation Time: "<< duration_cast<milliseconds>(imp_en-imp_st).count() << " ms\n";
}
int n,t;
long long a[maxn];
namespace soup1lo{
    long long ans=0,mx=0,k;
    void solve() {
        for(int i=1; i<=n; ++i) {
            long long sum=0;
            if(a[i]<=mx) continue;
            k=mx;
            for(int j=i; j<=n; ++j) {
                if(a[j]>k) {
                    sum+=a[j]-k;
                    j+=t;
                }
            }
            mx=max(mx,a[i]);
            ans=max(ans,sum);
        }
        cout << ans;
    }
}
namespace soup2{
    bool check() {
        for(int i=1; i<=n; ++i) {
            if(a[i]!=i) return false;
        }
        return true;
    }
    void solve() {
        long long ans=0,mn=LLONG_MAX;
        int cnt=0;
        for(int i=1; i<=n; i+=t+1) ans+=a[i];
        cout << ans;
    }
}
namespace soup3 {
    bool check() {return t==1;}
    void solve() {
        long long s1=0,s2=0;
        for(int i=1; i<=n; i+=2) s1+=a[i];
        int st,mx=a[1];
        for(int i=2; i<=n; ++i) {
            if(a[i]>mx && !(i&1)) {st=i;break;}
            mx=max(mx,(int)a[i]);
        }
        for(int i=st; i<=n; i+=2) if(a[i]>mx) {s2+=a[i]-mx;}
        cout << max(s1,s2);
    }
}
namespace soup_destructive_brute{
    long long ans=0;
    bool check(int m) {
        return m*n<=1000000;
    }
    void solve() {
        long long m=*max_element(a+1,a+1+n);
        for(int i=1; i<=m; ++i) {
            long long sum=0;
            for(int j=1; j<=n; ++j) {
                if(a[j]>i) {
                    sum+=a[j]-i;
                    j+=t;
                }
            }
            ans=max(ans,sum);
        }
        cout << ans;
    }
};
namespace soup_brute_upgrade1{
    long long ans=0;
    int sz;
    void solve() {
        //long long m=*max_element(a+1,a+1+n);
        vector<long long>v;
        for(int i=1; i<=n; ++i) v.pb(a[i]);
        v.pb(0);
        sortunique(v);
        sz=v.size();
        for(long long i:v) {
            long long sum=0;
            for(int j=1; j<=n; ++j) {
                if(a[j]>i) {
                    sum+=a[j]-i;
                    j+=t;
                }
            }
            ans=max(ans,sum);
        }
        cout << ans;
    }
}
namespace soupfull{
    long long sumA[maxn],ans=0;
    int cntC[maxn],nxt[maxn],B;
    map<long long,vector<int>,greater<long long>>mp;
    inline void build(int id, int lim) {
        int bl=id/B;
        int st=(bl)*B,en=(bl+1)*B-1;
        for(int i=en; i>=st; --i) {
            int j=(a[i]>lim?i+t+1:i+1);
            int bl_j=j/B;
            if(bl_j!=bl || j>=n) {nxt[i]=j,sumA[i]=(a[i]>lim?a[i]:0),cntC[i]=(a[i]>lim?1:0);}
            else {nxt[i]=nxt[j],sumA[i]=(a[i]>lim?a[i]:0)+sumA[j],cntC[i]=(a[i]>lim?1:0)+cntC[j];}
        }
    }
    inline long long fine(int k) {
        int cur=0,cnt=0;
        long long sum=0;
        while(cur<n) {sum+=sumA[cur],cnt+=cntC[cur],cur=nxt[cur];}
        return sum-1ll*k*cnt;
    }
    void solve() {
        for(int i=0; i<n; ++i) {a[i]=a[i+1];nxt[i]=i+1;}
        a[n]=0;
        for(int i=0; i<n; ++i) mp[a[i]].pb(i);
        B=sqrt(n);
        for(auto it:mp) {
            auto[v,p]=it;
            /// calculate total fine with k=v
            ans=max(ans,fine(v));
            /// re-calculate with k=v-1
            for(int i:p) build(i,v-1);
        }
        cout << max(ans,fine(0));
    }
}
int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    //file("patr")
    cin >> n >> t;
    for(int i=1; i<=n; ++i) cin >> a[i];
    // if(soup_destructive_brute::check(*max_element(a+1,a+1+n)))soup_destructive_brute::solve();
    // else if(soup3::check()) soup3::solve();
    // else if(soup2::check())soup2::solve();
    // else soup_brute_upgrade1::solve();
    soupfull::solve();
    return 0;
}
/*
7 2
1 2 6 3 1 9 2

10 3
5 3 7 1 8 10 2 8 1 11

#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fti(i, x, y) for (int i = x; i <= y; ++i)
#define ftd(i, x, y) for (int i = x; i >= y; --i)

const int MA = 2e5 + 5;

int a[MA];//, b[MA];
int n, t;

bool s2()
{
    fti(i, 1, n) if (a[i] != i) return 0;
    return 1;
}

ll f(ll k)
{
    int it = 1;
    ll r = 0;
    while (it <= n)
    {
        if (a[it] > k)
            r += a[it] - k, it += t;
        ++it;
    }
    return r;
}

void sub1()
{
    ll cur = f(0), res = 0;
    fti(i, 1, n)
    {
        ll C = f(a[i]);
        if (C > cur)
            cur = C, res = a[i];
    }
    cout << cur;
}

void sub2()
{
    cout << f(0);
}

void sub_rua()
{
    int l = 0, r = n;
    fti(i, 1, n) a[i] = b[i];
    sort(b + 1, b + 1 + n);
    while (r - l > 4)
    {
        ll c1 = b[l + (r - l) / 3];
        ll c2 = b[r - (r - l) / 3];
        if (f(c1) > f(c2))
            r = c2;
        else
            l = c1;
    }
    ll res = l, cur = f(l);
    fti(i, l, r)
    {
        ll C = f(b[i]);
        if (C > cur)
            cur = C, res = i;
    }
    cout << cur;
}

map <int, vector <int>, greater <int>> mp;
int B, nxt[MA], cntC[MA], bl[MA];
ll sumA[MA];

ll fine(int k)
{
    ll cnt = 0, s = 0;
    for (int cur = 0; cur <= n - 1; cur = nxt[cur])
        s += sumA[cur], cnt += cntC[cur];
    return s - k * cnt;
}

void recalc_pos(int i, int k)
{
    int j = (a[i] > k ? min(i + t + 1, n) : i + 1);
    if (j < n && bl[i] == bl[j])
        nxt[i] = nxt[j],
        sumA[i] = (a[i] > k ? a[i] : 0) + sumA[j],
        cntC[i] = (a[i] > k ? 1 : 0) + cntC[j];
    else
        nxt[i] = j,
        sumA[i] = (a[i] > k ? a[i] : 0),
        cntC[i] = (a[i] > k ? 1 : 0);
}

void recalc_block(int id, int k)
{
    int l = id * B, r = min((id + 1) * B - 1, n - 1);
    ftd(i, r, l)
        recalc_pos(i, k);
}

void sub5()
{
    fti(i, 0, n - 1) a[i] = a[i + 1];//, nxt[i] = i + 1;
    fti(i, 0, n - 1) mp[a[i]].push_back(i);
    int Bl = (n + B - 1) / B;
    ftd(i, Bl - 1, 0)
        recalc_block(i, 1e9);
    ll res = 0;
    for (auto it : mp)
    {
        int v = it.first;

        /// Tính tổng tiền phạt với k = v.
        res = max(res, fine(v));

        /// Tính lại với k = v - 1.
        for (int i : it.second)
            recalc_block(bl[i], v - 1);
    }
    cout << max(res, fine(0));
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen("patr.inp", "r", stdin);
//    freopen("patr.out", "w", stdout);
    cin >> n >> t;
    fti(i, 1, n) cin >> a[i];
    B = sqrt(n);
    fti(i, 0, n - 1) bl[i] = i / B;
    if (n <= 3000)
        sub1();
    else if (s2())
        sub2();
    else
        sub5();
//        sub_rua();
    return 0;
}
*/
/**/