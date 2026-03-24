#include <bits/stdc++.h>
using namespace std;
typedef array<int,3> State;

int n[3], a[3], r[3];

State doo(const State &s, int i, int j) {
    State nxt = s;
    int give = min(s[i], n[j] - s[j]);
    nxt[i] -= give;
    nxt[j] += give;
    return nxt;
}

int bfs() {
    State start = {a[0], a[1], a[2]};
    State target = {r[0], r[1], r[2]};

    set<State> goals;
    State t = target;
    sort(t.begin(), t.end());
    do {
        goals.insert(t);
    } while (next_permutation(t.begin(), t.end()));
    map<State, int> dist;
    queue<pair<State,int>> q;
    dist[start] = 0;
    q.push({start, 0});

    while (!q.empty()) {
        auto [cur, steps] = q.front(); q.pop();

        if (goals.count(cur))
            return steps;

        for (int i = 0; i < 3; i++) {
            if (cur[i] == 0) continue;
            for (int j = 0; j < 3; j++) {
                if (i == j || cur[j] == n[j]) continue;
                State nxt = doo(cur, i, j);
                if (!dist.count(nxt)) {
                    dist[nxt] = steps + 1;
                    q.push({nxt, steps + 1});
                }
            }
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 3; i++) cin >> n[i];
    for (int i = 0; i < 3; i++) cin >> a[i];
    for (int i = 0; i < 3; i++) cin >> r[i];

    cout << bfs() << '\n';
    return 0;
}
