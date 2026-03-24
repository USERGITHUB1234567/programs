#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long INF = 1e18;

struct Edge {
    int u, v;
    long long w;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for(int i = 0; i < m; i++){
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    vector<long long> dist(n + 1, 0);
    vector<int> parent(n + 1, -1);
    int x = -1;

    for (int i = 0; i < n; i++){
        x = -1;
        for(auto edge : edges){
            if(dist[edge.u] + edge.w < dist[edge.v]){
                dist[edge.v] = dist[edge.u] + edge.w;
                parent[edge.v] = edge.u;
                x = edge.v;
            }
        }
    }

    if(x == -1){
        cout << "NO";
    } else {
        int y = x;
        for (int i = 0; i < n; i++){
            y = parent[y];
        }

        vector<int> cycle;
        for (int cur = y;; cur = parent[cur]){
            cycle.push_back(cur);
            if(cur == y && cycle.size() > 1)
                break;
        }
        reverse(cycle.begin(), cycle.end());

        cout << "YES\n";
        for (int v : cycle)
            cout << v << " ";
    }

    return 0;
}
