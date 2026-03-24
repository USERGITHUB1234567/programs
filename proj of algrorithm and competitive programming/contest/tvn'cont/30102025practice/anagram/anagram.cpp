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
using namespace std;
static const int maxd=1003;
typedef short bignum[maxd];
typedef long long ll;
typedef long double ld;
const int maxn=1003,mod=1000000007;
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
int n,m,q,cur=0;
long long d[maxn];
unordered_map<string,int>mp;
string u,v;
vector<pair<int,long long>>adj[maxn];
void dijkstra(int s) {
    priority_queue<pair<long long,int>,vector<pair<long long ,int>>,greater<pair<long long, int>>>pq;
    pq.push({0,s});
    for(int i=1; i<=n; ++i) d[i]=LLONG_MAX;
    d[s]=0;
    while(!pq.empty()) {
        auto[cd,u]=pq.top();pq.pop();
        if(cd>d[u]) continue;
        for(auto[v,w]:adj[u]) {
            if(d[v]>d[u]+w) {
                d[v]=d[u]+w;
                pq.push({d[v],v});
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    //file("anagram")
    scanf("%d%d",&n,&m);
    for(int i=1,x,y,t; i<=m; ++i) {
        cin >> u >> v;
        scanf("%d",&t);
        if(!mp[u]) {mp[u]=++cur;}
        if(!mp[v]) {mp[v]=++cur;}
        x=mp[u];y=mp[v];
        adj[x].pb({y,(ll)t});
        //adj[y].pb({x,(ll)t});
    }
    scanf("%d",&q);
    while(q--) {
        cin >> u >> v;
        dijkstra(mp[u]);
        printf("%lld\n",(d[mp[v]]!=LLONG_MAX?d[mp[v]]:-1));
    }
    return 0;
}
/*
3 2
novak goat 1
goat simulator 3
2
novak simulator
simulator goat

3 3
kile legend 4
legend beer 5
beer kile 6
2
kile beer
legend kile

4 5
rafael me 5
me ow 6
ow ausopenfinal 2012
ausopenfinal me 2
rafael ausopenfinal 2
3
rafael me
me rafael
ow me
*/