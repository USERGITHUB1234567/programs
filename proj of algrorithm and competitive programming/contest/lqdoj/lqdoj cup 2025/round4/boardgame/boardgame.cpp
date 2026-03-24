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
inline ll log(ll k, ll n){ll res=0;while(n>0){n/=k;++res;}return res;}
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
int t,m,n,q,kq=0;
string board[maxn];
struct status {int i,j,kt,pi,pj,cur;};
namespace soup1 {
    int di[4]={1,0,-1,0},dj[4]={0,1,0,-1};
    void bfs(int i, int j,string mo) {
        queue<status>q;
        q.push({i,j,0,-1,-1,1});
        //cout << mo << '\n';
        //if(cur==mo.size()) ++kt;
        while(!q.empty()) {
            auto[x,y,kt,pi,pj,cur]=q.front();q.pop();
            //printf("%d %d %d \n" ,x,y,kt); 
            for(int i=0,u,v; i<4; ++i) {
                u=x+di[i],v=y+dj[i];
                //printf("%d %d %d %d\n",x,y,u,v);
                //printf("%d %d \n" ,u,v);
                if(!(cur%mo.size())) ++kt;
                //printf("%d \n", cur%mo.size());
                //cout << mo[cur] << ' ' << x << ' ' << y << '\n';
                //cout << s << '\n';
                int p=cur%mo.size();
                kq=max(kq,kt);
                //++cur;
                if(u>0 && u<=m && v>0 && v<=n && board[u][v]==mo[p] && u!=pi && v!=pj) {
                    q.push({u,v,kt,x,y,cur+1});
                }
            }
        }
    }
    void solve() {
        while(q--) {
            string qu;
            cin >> qu;
            kq=0;
            for(int i=1; i<=m; ++i) {
                for(int j=1; j<=n; ++j) {
                    if(board[i][j]==qu[0]) {
                        //printf("%d %d \n",i,j);
                        bfs(i,j,qu);
                    }
                }
            }
            printf("%d ",(kq==0?-1:kq*qu.size()));
        }
    }
}
int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    file("boardgame")
    scanf("%d",&t);
    while(t--) {
        scanf("%d%d%d",&m,&n,&q);
        for(int i=1; i<=m; ++i) {cin >> board[i];board[i]='.'+board[i];}
        soup1::solve();
        cout << '\n';
    }
    return 0;
}