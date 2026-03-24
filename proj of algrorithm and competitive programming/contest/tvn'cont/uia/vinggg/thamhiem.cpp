#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define forw(i,a,b) for(int (i)=(a); (i)<=(b); ++(i))
#define forb(i,a,b) for(int (i)=(a); (i)>=(b); --(i))
#define pb push_back
#define eb emplace_back
#define uni(x) sort(all(x)); x.erase(unique(all(x)), x.end())
#define mp make_pair
#define fi first
#define se second
#define file(n) freopen(n".inp", "r", stdin); freopen(n".out", "w", stdout);
using namespace std;
typedef long long ll;
const int maxn=1503, maxq=100005,inf=INT_MAX/2;
inline int maxi(int a, int b) {return (a>b?a:b);}
inline int mini(int a, int b) {return (a<b?a:b);}
inline long long maxill(ll a, ll b) {return (a>b?a:b);}
inline long long minill(ll a, ll b) {return (a<b?a:b);}
inline long long modexp(ll b, ll e, ll m)
{
    long long res=0;
    while(e>0) {
        if(e&1) res=(res*b)%m;
        b=(b*b)%m;
        e>>=1;
    }
    return res;
}
int n,m,q,w,s,t,ue,ve;
int a[maxn][maxn];
pair<int,int>p[maxq];
namespace soup2
{
    bool check()
    {
        return (n<=1500 && m<=1500 && !q);
    }
    int d[maxn][maxn],dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
    void dijkstra(pair<int,int>s)
    {
        for(int i=1; i<=n; ++i)
            for(int j=1; j<=n; ++j) d[i][j]=inf;
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
        d[s.fi][s.se]=0;
        pq.push({0,s});
        while(!pq.empty()) {
            auto[cd,t]=pq.top();
            auto[u,v]=t;
            pq.pop();
            if(cd>d[u][v]) continue;
            for(int i=0; i<4; ++i) {
                int x=u+dx[i],y=v+dy[i];
                if(x<=0 || x>n || y<=0 || y>n) continue;
                /*if(x==ue && y==ve) {
                    d[x][y]=mini(d[x][y],d[u][v]);
                    continue;
                }*/
                if(d[u][v]+a[u][v]<d[x][y]) {
                    d[x][y]=d[u][v]+a[u][v];
                    pq.push({d[x][y],{x,y}});
                }
            }
        }
    }
    void solve()
    {
        dijkstra({s,t});
        cout << d[ue][ve];
    }
}
/*namespace soup3
{
    bool check()
    {
        return (n<=1500 && m<=1500 && q==1);
    }
    int d[maxn][maxn],dx[4]={1,0,-1,0},dy[4]={0,1,0,-1},t1=p[1].fi,t2=p[1].se;
    void dijkstra(pair<int,int>s)
    {
        for(int i=1; i<=n; ++i)
            for(int j=1; j<=n; ++j) d[i][j]=inf;
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
        d[s.fi][s.se]=0;
        pq.push({0,s});
        while(!pq.empty()) {
            auto[cd,t]=pq.top();
            auto[u,v]=t;
            pq.pop();
            if(cd>d[u][v]) continue;
            for(int i=0; i<4; ++i) {
                int x=u+dx[i],y=v+dy[i];
                if(x<=0 || x>n || y<=0 || y>n) continue;
                /*if(x==ue && y==ve) {
                    d[x][y]=mini(d[x][y],d[u][v]);
                    continue;
                }*/
                /*if(d[u][v]+a[u][v]<d[x][y]) {
                    d[x][y]=d[u][v]+a[u][v];
                    pq.push({d[x][y],{x,y}});
                }
            }
            int x=u+p[1].se,y=v+p[1].fi;
            if(x<=0 || x>n || y<=0 || y>n) continue;
            //cout << x << " " << y << " " << u << " " << v << "\n";
            /*if(x==ue && y==ve) {
                d[x][y]=mini(d[x][y],d[u][v]);
                continue;
            }*/
            /*if(d[u][v]+w<d[x][y]) {
                d[x][y]=d[u][v]+w;
                pq.push({d[x][y],{x,y}});
            }
        }
    }
    void solve()
    {
        dijkstra({s,t});
        cout << d[ue][ve];
    }
}*/
void implement()
{
    return soup2::solve();
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    file("thamhiem")
    cin >> n >> m >> q >> w;
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=m; ++j) cin >> a[i][j];
    }
    for(int i=1; i<=q; ++i) cin >> p[i].fi >> p[i].se;
    cin >> s >> t >> ue >> ve;
    //cout << p[1].fi << " " << p[]
    implement();
}
