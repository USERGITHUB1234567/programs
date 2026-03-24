#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e15;
struct Node {
    long long d;
    int u, used;
    bool operator>(const Node &other) const {
        return d > other.d;
    }
};
int n, m;
vector<pair<int, long long>> adj[100005];
long long dp[2][100005];

void dijkstra(int s) {
    for (int i = 1; i <= n; i++){
        dp[0][i] = dp[1][i] = INF;
    }
    dp[0][s] = 0;
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push({0, s, 0});

    while(!pq.empty()){
        Node cur = pq.top();
        pq.pop();
        int u = cur.u, used = cur.used;
        long long d = cur.d;
        if(d > dp[used][u]) continue;

        for(auto &edge : adj[u]){
            int v = edge.first;
            long long w = edge.second;
            if(dp[used][v] > d + w) {
                dp[used][v] = d + w;
                pq.push({dp[used][v], v, used});
            }
            if(used == 0 && dp[1][v] > d + w/2) {
                dp[1][v] = d + w/2;
                pq.push({dp[1][v], v, 1});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    dijkstra(1);
    long long ans = min(dp[0][n], dp[1][n]);
    cout << ans;
    return 0;
}

/*#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n,m;
long long di[100005],pre[100005];
vector<pair<int,long long>>adj[100005];
vector<long long>kq;
void dijkstra(int s)
{
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
    di[s]=0;
    pre[s]=s;
    pq.push({di[s],s});
    while(!pq.empty()) {
        auto[cd,u]=pq.top();
        pq.pop();
        if(cd>di[u]) continue;
        for(auto[v,w]:adj[u]) {
            if(di[v]>di[u]+w) {
                di[v]=di[u]+w;
                pre[v]=u;
                pq.push({di[v],v});
            }
        }
    }
}
void trace(int u)
{
    kq.push_back(u);
    if(u!=1) trace(pre[u]);
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    fill(di,di+100005,1e15);
    cin >> n >> m;
    for(int i=1; i<=m; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
    }
    dijkstra(1);
    trace(n);
    vector<long long>kqt;

    long long re=0;
    for(int i=kq.size()-1; i>=0; i--) {
        if(i==0) break;
        int u=kq[i];
        for(auto[v,w]:adj[u]) {
            if(v==kq[i-1]) {
                //re+=w;
                kqt.push_back(w);
                break;
            }
        }
    }
    *max_element(kqt.begin(),kqt.end())/=2;
    for(int i:kqt) re+=i;
    cout << re;
    //for(int i=1; i<=n; i++) cout << di[i] << ' ';
}*/
