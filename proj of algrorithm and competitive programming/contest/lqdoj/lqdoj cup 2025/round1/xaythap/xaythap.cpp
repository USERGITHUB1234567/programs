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
const int maxn=100005,mod=1000000007;
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
struct stage{long long c,s,id;}st[maxn];
int t,n,m;
vector<pair<long long,ll>>process[maxn];
vector<long long>pre[maxn];
vector<int>cor;
bool cmp(pair<long long,ll>a, pair<long long,ll>b) {return a.fi>b.fi;}
namespace soup2 {
    long long kq=0,k1,k2,sz;
    bool equ=false;
    void solve() {
        kq=0;
        for(int i=1; i<=m; ++i) {
            for(int j=i+1; j<=m; ++j) {
                int l=min(pre[i].size(),pre[j].size());
                long long t1,t2;
                //cout << i << " " << j << " " << pre[i].size() << " " << pre[j].size() << '\n';
                if(pre[i].size()>pre[j].size()) {
                    t1=pre[i][l];t2=pre[j][l-1];
                    k1=j;k2=i;sz=l;
                    equ=false;
                }
                else if(pre[i].size()<pre[j].size()) {
                    t1=pre[i][l-1];t2=pre[j][l];
                    k1=i;k2=j;sz=l;
                    equ=false;
                }
                else {
                    t1=pre[i][l-1];t2=pre[j][l-1];
                    k1=i;k2=j;sz=l;
                    equ=true;
                }
                kq=max(kq,t1+t2);
                //cout << l << " " << i << ' ' << j << "\n";
            }
        }
        int fsz=2*sz;
        if(!equ) ++fsz;
        cout << kq << "\n" << fsz << "\n";
        vector<int>fid;
        int j1=0,j2=0;
        for(int i=0; i<2*sz; ++i) {
            if(!(i&1)) {
                fid.push_back(process[k2][j2].se);
                ++j2;
            }
            else {
                fid.push_back(process[k1][j1].se);
                ++j1;
            }
        }
        if(!equ) fid.pb(process[k2][sz].se);
        for(int i:fid) cout << i << ' ';
        cout << "\n"; 
    }
}
int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    file("tower")
    cin >> t;
    while(t--) {
        cin >> n;
        cor.clear();
        for(int i=1; i<=n; ++i) {
            cin >> st[i].c >> st[i].s;
            st[i].id=i;
            cor.push_back(st[i].c);
        }
        sortunique(cor);
        for(int i=1; i<=n; ++i) {
            int l=(lower_bound(all(cor),st[i].c)-cor.begin())+1;
            st[i].c=l;
            process[i].clear();
        }
        for(int i=1; i<=n; ++i) {
            process[st[i].c].push_back({st[i].s,st[i].id});
        }
        m=cor.size();
        //cout << m << " " << n << "\n";
        for(int i=1; i<=m; ++i) sort(all(process[i]),cmp);
        for(int i=1; i<=m; ++i) {
            for(int j=0; j<process[i].size(); ++j) {
                pre[i].resize(process[i].size());
                if(j==0) pre[i][j]=process[i][j].fi;
                else pre[i][j]=process[i][j].fi+pre[i][j-1];
            }
        }
        soup2::solve();
        //cout << "\n";
    }
    //cout << "a";
    return 0;
}