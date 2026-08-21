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
int r,c,m;
string s;
unordered_map<char,int>di,dj;
char grid[502][502];
bool mk[502][502];
inline void bfs(int a, int b) {
    queue<pair<int,pair<int,int>>>q;
    q.push({0,{a,b}});
    while(!q.empty()) {
        auto[c,p]=q.front();q.pop();
        auto[x,y]=p;
        if(c==m) {
            mk[x][y]=true;
            break;
        }
        int u=x+di[s[c]],v=y+dj[s[c]];
    }
}
namespace soup1 {
    inline void bfs(int a, int b) {
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{a,b}});
        while(!q.empty()) {
            auto[cr,p]=q.front();q.pop();
            auto[x,y]=p;
            //cout << x << ' ' << y << '\n';
            if(cr==m) {
                mk[x][y]=true;
                //cout << x << ' ' << y << '\n';
                //break;
                continue;
            }
            int u=x+di[s[cr]],v=y+dj[s[cr]];
            if(u>r || u<1 || v>c || v<1 || grid[u][v]=='#') {
                //cout << x << ' ' << y << ' ' << c << ' ' << u << ' ' << v << ' ' << grid[u][v] << '\n';
                continue;
            }
            q.push({cr+1,{u,v}});
        }
    }
    void solve() {
        for(int i=1; i<=r; ++i) {for(int j=1; j<=c; ++j) {if(grid[i][j]!='#')bfs(i,j);}}
        int kq=0;
        for(int i=1; i<=r; ++i) {
            for(int j=1; j<=c; ++j) {
                if(mk[i][j]) ++kq;
            }
        }
        cout << kq;
    }
}
namespace soup2 {
    int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
    int f[102][102][102];
    void solve() {
        for(int i=1; i<=r; ++i) {
            for(int j=1; j<=c; ++j){
                if(grid[i][j]!='#') f[i][j][0]=1;
            }
        }
        for(int cr=0; cr<m; ++cr) {
            for(int i=1; i<=r; ++i) {
                for(int j=1; j<=c; ++j) {
                    if(grid[i][j]=='#' || f[i][j][cr]==0) continue;
                    if(s[cr]!='?') {
                        int x=i+di[s[cr]],y=j+dj[s[cr]];
                        if(x>r || x<1 || y>c || y<1 || grid[x][y]=='#') continue;
                        f[x][y][cr+1]=f[i][j][cr];
                    }
                    else {
                        int x,y;
                        for(int k=0; k<4; ++k) {
                            x=i+dx[k],y=j+dy[k];
                            if(x>r || x<1 || y>c || y<1 || grid[x][y]=='#') continue;
                            f[x][y][cr+1]=f[i][j][cr];
                        }
                    }
                }
            }
        }
        int ans=0;
        for(int i=1; i<=r; ++i) {
            for(int j=1; j<=c; ++j) {
                if(f[i][j][m]) ++ans;
            }
        }
        printf("%d",ans);
    }
}
int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    file("3177")
    cin >> r >> c >> m;
    di['N']=-1,di['E']=0,di['S']=1,di['W']=0;
    dj['N']=0,dj['E']=1,dj['S']=0,dj['W']=-1;
    for(int i=1; i<=r; ++i) for(int j=1; j<=c; ++j) cin >> grid[i][j];
    cin >> s;
    /* for(int i=1; i<=r; ++i) {
        for(int j=1; j<=c; ++j) cout << grid[i][j];
        cout << '\n';
    } */
    soup2::solve();
    //cout << di[s[1]];
    return 0;
}