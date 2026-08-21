#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
#define foutput(name) freopen(name, "w", stdout);
#define finput(name) freopen(name,"r", stdin);
#define all(x) x.begin(), x.end()
#define sortunique(x) sort(all(x)); x.erase(unique(all(x)), x.end());
#define forw(i,a,b) for(int (i)=(a); (i)<=(b); ++(i))
#define forb(i,a,b) for(int (i)=(a); (i)>=(b); --(i))
#define eb emplace_back
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
static const int maxd=1003;
typedef short bignum[maxd];
typedef long long ll;
typedef long double ld;
const int maxn=200005,mod=1000000007;
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
inline ll log_bad(ll k, ll n){ll res=0;while(n>0){n/=k;++res;}return res;} // không dùng nữa
void setupfactor() {
    fact[0]=1;
    for(int i=1; i<maxn; ++i) fact[i]=fact[i-1]*i%mod;
    int tc=maxn-1;
    ifact[tc]=modexp(fact[tc],mod-2,mod);
    for(int i=tc; i>=1; --i) ifact[i-1]=ifact[i]*i%mod; 
}
inline long long ncr(long long k, long long n) {return (k==n?1:fact[n]*ifact[n-k]%mod*ifact[k]%mod);}
mt19937_64 generator1(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 generator2(chrono::high_resolution_clock::now().time_since_epoch().count());
inline long long rnd1(long long a, long long b) {return a+generator1()%(b-a+1);}
inline long long rnd2(long long a, long long b) {return a+generator2()%(b-a+1);}
int n,m;
struct fol{int s,e;};
fol p[maxn*4]; // dư chút để an toàn
unordered_map<int,int>ump;
vector<int>a;

namespace soupfull {
    int N, nxt[maxn*4], jump[maxn*4][20], logn;

    inline int get_logn(int x) {
        int lg=0;
        while((1<<lg) <= x) ++lg;
        return max(0, lg-1);
    }

    inline int cover(int st) {
        ll te = 1ll * p[st].s + m; // đích cần phủ đến
        int cur = st, cnt = 1;
        // nhảy lớn trước
        for(int k=logn; k>=0; --k) {
            int i = jump[cur][k];
            if (i >= cur && p[i].e < te) {
                cur = i;
                cnt += (1<<k);
            }
        }
        // thêm một bước cuối
        cur = jump[cur][0];
        ++cnt;
        if (p[cur].e >= te) return cnt;
        return (int)1e9;
    }

    void solve() {
        // 1) Chuẩn hóa đoạn: nếu s > e (vòng) => e += m
        vector<fol> v;
        v.reserve(n);
        for(int i=0; i<n; ++i) {
            int s=p[i].s, e=p[i].e;
            if (s<=e) v.pb({s,e});
            else v.pb({s, e+m});
        }

        // 2) Sắp xếp theo s rồi e
        sort(all(v), [](const fol& A, const fol& B){
            if (A.s==B.s) return A.e<B.e;
            return A.s<B.s;
        });

        // 3) Loại bỏ đoạn bị chứa (giữ e tăng dần)
        vector<fol> w;
        w.reserve(v.size());
        int lastE = -1;
        for(auto &seg : v) {
            if (seg.e > lastE) {
                w.pb(seg);
                lastE = seg.e;
            }
        }

        // Nếu rỗng => không thể phủ
        if (w.empty()) { printf("-1"); return; }

        // 4) Nhân đôi
        N = (int)w.size();
        for(int i=0; i<N; ++i) p[i] = w[i];
        for(int i=0; i<N; ++i) p[i+N] = {w[i].s + m, w[i].e + m};
        int tot = 2*N;

        // 5) Xây nxt bằng two-pointer
        int j=0;
        for(int i=0; i<tot; ++i) {
            if (j<i) j=i;
            while(j<tot && p[j].s <= p[i].e) ++j;
            nxt[i] = j-1;
            jump[i][0] = nxt[i];
        }

        // 6) Tính logn và build jump
        logn = get_logn(tot);
        for(int k=1; k<=logn; ++k) {
            for(int i=0; i<tot; ++i) {
                int mid = jump[i][k-1];
                jump[i][k] = (mid>=0 ? jump[mid][k-1] : mid);
            }
        }

        // 7) Thử bắt đầu ở mỗi đoạn trong [0..N-1]
        int ans = (int)1e9;
        for(int i=0; i<N; ++i) {
            ans = min(ans, cover(i));
        }

        printf("%d", (ans== (int)1e9 ? -1 : ans));
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    file("3184")
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; ++i) scanf("%d%d",&p[i].s,&p[i].e),a.pb(p[i].s),a.pb(p[i].e);
    a.pb(0);
    a.pb(m);
    sortunique(a);
    sort(p,p+n,[](fol a,fol b) {
        if(a.s==b.s) return a.e<b.e;
        return a.s<b.s;
    });
    soupfull::solve();
    return 0;
}
