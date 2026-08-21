#include <bits/stdc++.h>
using namespace std;

vector<int> adj[101];
vector<int> leafNodes;
bool visited[101];
int kq = 0;
void dfs(int node) {
    visited[node] = true;
    if (adj[node].empty()) {
        leafNodes.push_back(node);
        return;
    }
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            kq += neighbor;
            dfs(neighbor);
        }
    }
}
int main() {
    memset(visited, false, sizeof(visited));
    int n, m;
    cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    while (m--) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            kq += i;
            dfs(i);
        }
    }
    if (!leafNodes.empty()) {
        int maxLeaf = *max_element(leafNodes.begin(), leafNodes.end());
        kq -= maxLeaf;
    }
    cout << kq;
    return 0;
}
