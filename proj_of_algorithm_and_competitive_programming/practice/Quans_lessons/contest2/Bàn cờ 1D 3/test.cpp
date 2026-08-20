#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

int n;
map<vector<int>, int> dist;

void bfs(const vector<int>& start) {
    queue<vector<int>> q;
    q.push(start);
    while (!q.empty()) {
        auto u = q.front(); q.pop();
        int d = dist[u];
        // u has exactly 3 elements
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (i == j) continue;
                int t = u[j] * 2 - u[i];               // corrected arithmetic
                if (t <= 0 || t > n) continue;
                vector<int> v;
                v.push_back(t);
                for (int k = 0; k < 3; ++k) if (k != i) v.push_back(u[k]); // push values, not indices
                sort(v.begin(), v.end());
                if (dist.count(v)) continue;           // check presence without creating entry
                dist[v] = d + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> st(3), en(3);
    if (!(cin >> n)) return 0;
    for (int i = 0; i < 3; ++i) cin >> st[i];
    for (int i = 0; i < 3; ++i) cin >> en[i];
    sort(st.begin(), st.end());
    sort(en.begin(), en.end());

    dist.clear();
    dist[st] = 0;   // mark start visited with distance 0
    bfs(st);

    if (dist.count(en)) cout << dist[en] << '\n';
    else cout << -1 << '\n';
    return 0;
}
