#include <bits/stdc++.h>
using namespace std;

const int NMAX = 100005;
int n, m;
vector<int> adj[NMAX];
bool visited[NMAX], inStack[NMAX];
int parent[NMAX];
bool found = false;
int cycle_start, cycle_end;

void dfs(int v) {
    visited[v] = true;
    inStack[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) {
            parent[u] = v;
            dfs(u);
            if (found) return;
        } else if (inStack[u]) {
            found = true;
            cycle_start = u;
            cycle_end = v;
            return;
        }
    }
    inStack[v] = false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("tri.inp", "r", stdin);
    freopen("tri.out", "w", stdout);

    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 1; i <= n; i++){
        if (!visited[i]) {
            dfs(i);
            if (found) break;
        }
    }

    if (!found) {
        cout << "IMPOSSIBLE";
    } else {
        vector<int> cycle;
        cycle.push_back(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = parent[v])
            cycle.push_back(v);
        cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());

        cout << cycle.size() << "\n";
        for (int v : cycle)
            cout << v << " ";
    }

    return 0;
}
