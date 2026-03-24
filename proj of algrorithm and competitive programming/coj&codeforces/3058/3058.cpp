#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n,m,pre[100005],vis[10];
vector<pair<int,int>>adj[100005];
long long in[100005],di[100005],sc=1;
vector<pair<long long,int>>wa;
void dijkstra(int s)
{
    priority_queue<tuple<long long,int,int>,vector<tuple<long long,int,int>>,greater<tuple<long long,int,int>>>pq;
    di[s]=0;
    in[s]=1;
    pq.push({di[s],s,0});
    while(!pq.empty()) {
        auto[cd,u,cr]=pq.top();
        pq.pop();
        vis[u]++;

        if(cd>di[u]) continue;
        for(auto[v,w]:adj[u]) {
            if(di[v]==di[u]+w) {
                in[v]++;
            }
            else if(di[v]>di[u]+w) {
                in[v]=1;
                pre[v]=u;
                di[v]=di[u]+w;
                pq.push({di[v],v,cr+1});
            }
            if(v==n) {
                wa.push_back({cd+w,cr+1});
            }
        }
    }
}
void trace(int u)
{
    sc*=in[u]%1000000007;
    if(u!=1) trace(pre[u]);
}
int main()
{
    fill(di,di+100005,1e15);
    cin >> n >> m;
    for(int i=1; i<=m; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
    }
    vector<long long>kq;
    dijkstra(1);
    trace(n);
    for(int i=0; i<wa.size(); i++) {
        if(wa[i].first==di[n]) {
            kq.push_back(wa[i].second);
        }
    }
    cout << di[n] << " " << sc << " " << *min_element(kq.begin(),kq.end()) << " " << *max_element(kq.begin(),kq.end());
    //cout << "\n";
    //for(int i=0; i<wa.size(); i++) cout << wa[i].first << " " << wa[i].second << "\n";
    //cout << kq.size();
}
/*#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e15;
const int MOD = 1e9 + 7;
const int MAXN = 100005;

int n, m;
vector<pair<int, int>> adj[MAXN];
long long dist[MAXN];
int countPaths[MAXN];
int minFlights[MAXN];
int maxFlights[MAXN];

void dijkstra(int s) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    fill(dist, dist + n + 1, INF);
    dist[s] = 0;
    countPaths[s] = 1;
    minFlights[s] = 0;
    maxFlights[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto [v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                countPaths[v] = countPaths[u];
                minFlights[v] = minFlights[u] + 1;
                maxFlights[v] = maxFlights[u] + 1;
                pq.push({dist[v], v});
            } else if (dist[v] == dist[u] + w) {
                countPaths[v] = (countPaths[v] + countPaths[u]) % MOD;
                minFlights[v] = min(minFlights[v], minFlights[u] + 1);
                maxFlights[v] = max(maxFlights[v], maxFlights[u] + 1);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    int S = 1, T = n;
    dijkstra(S);

    cout << dist[T] << " " << countPaths[T] << " " << minFlights[T] << " " << maxFlights[T] << "\n";

    return 0;
}
*/
