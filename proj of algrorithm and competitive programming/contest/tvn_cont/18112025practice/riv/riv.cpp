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
int r,c,n;
string grid[502];
int d[502][502],di[8]={-1,-1,0,1,1,1,0,-1},dj[8]={0,1,1,1,0,-1,-1,-1};
void dijkstra(int a, int b) {
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    for(int i=1; i<=r; ++i) for(int j=1; j<=c; ++j) d[i][j]=INT_MAX;
    d[a][b]=0;
    pq.push({0,{a,b}});
    while(!pq.empty()) {
        auto[cd,p]=pq.top();pq.pop();
        auto[x,y]=p;
        if(cd>d[x][y]) continue;
        for(int i=0; i<8; ++i) {
            int w,t=grid[x][y]-'0';
            if(i==t) w=0;else w=1;
            int u=x+di[i],v=y+dj[i];
            if(u>r || u<1 || v>c || v<1) continue;
            if(d[u][v]>d[x][y]+w) {
                d[u][v]=d[x][y]+w;
                pq.push({d[u][v],{u,v}});
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    file("riv")
    scanf("%d%d",&r,&c);
    for(int i=1; i<=r; ++i) cin >> grid[i],grid[i]='*'+grid[i];
    scanf("%d",&n);
    for(int i=1,rs,cs,rd,cd; i<=n; ++i) {
        scanf("%d%d%d%d",&rs,&cs,&rd,&cd);
        dijkstra(rs,cs);
        printf("%d\n",d[rd][cd]);
    }
    return 0;
}