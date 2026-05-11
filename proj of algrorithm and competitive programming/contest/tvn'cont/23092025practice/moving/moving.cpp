#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(n) freopen(n".inp", "r", stdin); freopen(n".out", "w", stdout);
using namespace std;
const int maxn=100005;
long long n,m,d[maxn],df[102][102];
vector<pair<int,long long>>adj[maxn];
struct edge{int u,v,w;}ed[maxn];
/*void dijkstra(int s) {
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>>pq;
    for(int i=1; i<=n; ++i) d[i]=LLONG_MAX;
    pq.push({0,s});
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
}*/
namespace soup1 {
    bool checksoup1() {return n<=100 && m<=100;}
    void floyd_warshall() {
        for(int k=1; k<=n; ++k) {
            for(int i=1; i<=n; ++i) {
                for(int j=1; j<=n; ++j) {
                    df[i][j]=min(df[i][j],df[i][k]+df[k][j]);
                }
            }
        }
    }
    void solvesoup1() {
        for(int i=1; i<=n; ++i) {
            for(int j=1; j<=n; ++j) {
                if(i==j) df[i][j]=0;
                else df[i][j]=LLONG_MAX/2;
            }
        }
        for(int i=1; i<=m; ++i) {
            auto[u,v,w]=ed[i];
            df[u][v]=min(df[u][v],(long long)w);
            //df[v][u]=min(df[v][u],(long long)w);
        }
        floyd_warshall();
        long long res=LLONG_MAX;
        for(int i=2; i<=n; ++i) {
            res=LLONG_MAX/2;
            for(int j=1; j<=n; ++j) {
                res=min(res,df[1][j]+df[i][j]);
            }
            cout << (res==LLONG_MAX/2?-1:res) << " ";
        }
        //cout << df[2][2];
    }
}
namespace soupfull {
    void dijkstra(int s) {
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>>pq;
        for(int i=1; i<=n; ++i) d[i]=LLONG_MAX/2;
        pq.push({0,s});
        d[s]=0;
        while(!pq.empty()) {
            auto[cd,u]=pq.top();pq.pop();
            if(cd>d[u]) continue;
            for(auto[v,w]:adj[u]) {
                if(d[v]>d[u]+w) {
                    d[v]=d[u]+w;
                    //cout << u << " " << v << " " << d[v] << "\n";
                    pq.push({d[v],v});
                }
            }
        }
    }
    void solvesoupfull() {
        dijkstra(1);
        for(int i=2; i<=n; ++i) {
            cout << (d[i]==LLONG_MAX/2?-1:d[i]) << " ";
        }
    }
}
using namespace soup1;
using namespace soupfull;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    file("moving")
    cin >> n >> m;
    for(int i=1,u,v,w; i<=m; ++i) {
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
        ed[i]={u,v,w};
        //adj[v].push_back({u,w});
    }
    /*if(checksoup1()) {
        solvesoup1();
        return 0;
    }*/
    solvesoupfull();
}