#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int n;
int adj[200005];
vector<bool> kq;
bool vis[200005];

void bfs(int s) {
    queue<pair<int, int>> q;
    q.push({s, 0});
    vis[s] = true;
    while (!q.empty()) {
        int u = q.front().first, cd = q.front().second;
        q.pop();
        int v = adj[u];
        if (!vis[v]) {
            q.push({v, cd + 1});
            vis[v] = true;
        } else {
            if (v != s || (v==s && cd<2))
                kq.push_back(true);
            else
                kq.push_back(false);
        }
    }
}
int main() {
    memset(vis, false, sizeof(vis));
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        adj[i] = x;
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            bfs(i);
        }
    }

    int d = 0;
    for (bool i : kq) {
        if (i) d++;
        //cout << i << " ";
    }
    int t = kq.size();
    if(d==0) cout << t << " ";
    else cout << t-d+1 << " ";
    cout << t;
    return 0;
}
