#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200001;
vector<int> adj[MAXN];
int dist[MAXN];

void dfs(int u, int parent, int& farthest, int& maxDist) {
    for (int v : adj[u]) {
        if (v != parent) {
            dist[v] = dist[u] + 1;
            if (dist[v] > maxDist) {
                maxDist = dist[v];
                farthest = v;
            }
            dfs(v, u, farthest, maxDist);
        }
    }
}

pair<int, int> findDiameter(int n) {
    int farthest = 0, maxDist = 0;
    dist[1] = 0;
    dfs(1, -1, farthest, maxDist);

    int start = farthest;
    maxDist = 0;
    dist[start] = 0;
    dfs(start, -1, farthest, maxDist);

    return {start, farthest};
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    pair<int, int> diameterEnds = findDiameter(n);
    int diameter = dist[diameterEnds.second];
    cout << "Đường kính của cây: " << diameter << endl;
    cout << "Hai đỉnh xa nhất: " << diameterEnds.first << " và " << diameterEnds.second << endl;

    return 0;
}
