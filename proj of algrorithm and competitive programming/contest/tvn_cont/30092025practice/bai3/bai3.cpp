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
int n,m,st[maxn],en[maxn],d[maxn];
vector<int>adj[maxn];
pair<int,int>ro;
struct fenwick_tree {
    long long bit[maxn];
    void init() {
        for(int i=0; i<maxn; ++i) bit[i]=0;
    }
    long long sum(int i) {
        long long res=0;
        while(i>0) {
            res+=bit[i];
            i-=i&-i;
        }
    }
    void upd(int i, long long v) {
        while(i<=n) {
            bit[i]+=v;
            i+=i&-i;
        }
    }
}ft;
namespace soup2 {
    bool check() {return m==1;}
    int timer=0;
    long long query(int u) {return ft.sum(en[u])-ft.sum(st[u]-1);}
    void dfseu(int u, int p) {
        st[u]=++timer;
        for(int v:adj[u]) {
            if(v==p) continue;
            dfseu(v,u);
        }
        en[u]=timer;
        //cout << u << ' ' << en[u] << "\n";
    }
    void bfs(int s) {
        for(int i=0; i<maxn; ++i) d[i]=INT_MAX;
        queue<int>q;
        q.push(s);
        d[s]=0;
        while(!q.empty()) {
            int u=q.front();q.pop();
            vector<pair<int,int>>ke;
            for(int v:adj[u]) {
                ke.eb(query(v),v);
            }
            sort(all(ke),greater<pair<int,int>>());
            int delta=0;
            for(auto[w,v]:ke) {
                if(d[v]>d[u]+1+delta) {
                    d[v]=d[u]+1+delta;
                    ++delta;
                    //cout << d[v] << ' ';
                    q.push(v);
                }
            }
        }
    }
    void solve() {
        int g=ro.fi;
        ft.init();
        dfseu(g,0);
        for(int i=1; i<=n; ++i) {
            ft.upd(st[i],1);
            cout << ft.sum(i) << " ";
        }
        bfs(g);
        cout << st[2] << " " << en[2] << ft.sum(4);
        //cout << query(2);
        //cout << 'a';
        //for(int i=1; i<=n; ++i) cout << d[i] << " ";
        //cout << *max_element(d+1,d+1+n);
    }
}
int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    file("bai3")
    cin >> n;
    for(int i=1,u,v; i<n; ++i) {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    cin >> m;
    if(m==1) cin >> ro.fi;
    else cin >> ro.fi >> ro.se;
    //cout << "a";
    //soup2::solve();
    return 0;
}