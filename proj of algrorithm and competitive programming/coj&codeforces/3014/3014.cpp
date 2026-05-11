#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int n, k;
bool marked[100001];
int d[200001]; // Distance array
vector<int> adj[100001];

// Depth-first search to calculate distances
void dfs(int u, int p) {
    for (auto v : adj[u]) {
        if (v == p) continue; // Skip the parent
        d[v] = d[u] + 1;      // Update distance
        dfs(v, u);
    }
}

void sub2() {
    // Step 1: Find the farthest marked node from an arbitrary marked node
    int start = 0;
    for (int i = 1; i <= n; i++) {
        if (marked[i]) {
            start = i;
            break;
        }
    }

    // First DFS to calculate distances from the start node
    memset(d, 0, sizeof(d));
    dfs(start, -1);

    int farthestNode = start;
    for (int i = 1; i <= n; i++) {
        if (marked[i] && d[i] > d[farthestNode]) {
            farthestNode = i;
        }
    }

    // Step 2: Second DFS to calculate the diameter of the tree
    memset(d, 0, sizeof(d));
    dfs(farthestNode, -1);

    int diameter = 0;
    for (int i = 1; i <= n; i++) {
        if (marked[i]) {
            diameter = max(diameter, d[i]);
        }
    }

    // Step 3: Output the radius of the tree
    cout << (diameter + 1) / 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    vector<int> markedNodes(k);
    for (int i = 0; i < k; i++) {
        cin >> markedNodes[i];
        marked[markedNodes[i]] = true;
    }

    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    sub2();
    return 0;
}
/*#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n, k;
bool marked[100001];
int parent[100001];
bool visited[100001];
int d[100001];
vector<int> adj[100001];
void dfs(int u,int p) {
    visited[u]=true;
    for(auto v:adj[u]) {
        if(v==p) continue;
        d[v]=d[u]+1;
        dfs(v,u);
    }
}
void sub2()
{
    d[adj[1]]=0;
    dfs(adj[1],0);
    int u=adj[1];
    for(int i=1; i<=k; i++) {
        if(d[a[i]]>d[u]) u=a[i];
    }
    d[u]=0;
    dfs(u,0);
    int diameter=0;
    for(int i=1; i<=k; i++) {
        if(d[a[i]]>diameter) diameter=a[i];
    }
    cout << (diameter+1)/2;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    memset(marked, false, sizeof(marked));
    memset(parent, 0, sizeof(parent));
    cin >> n >> k;
    vector<int> markedNodes(k);
    for (int i = 0; i < k; i++) {
        cin >> markedNodes[i];
        marked[markedNodes[i]] = true;
    }
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    sub2();
    return 0;
}*/
