#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
#define all(x) x.begin(),x.end()
#define eb emplace_back
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
const int maxn = 102;

vector<pair<int,int>> ans;
vector<pair<long double,int>> adj[maxn];

struct tower {
    long double x, y;
    int s, a[maxn];
} tow[maxn];

int n;
long double res[maxn];

long double dist(tower A, tower B) {
    return sqrt((A.x - B.x)*(A.x - B.x) + (A.y - B.y)*(A.y - B.y));
}

void bfs(int u) {
    priority_queue<
        pair<long double,int>,
        vector<pair<long double,int>>,
        greater<pair<long double,int>>
    > pq;
    
    pq.push({res[u], u});
    
    while (!pq.empty()) {
        auto [d, cur] = pq.top();
        pq.pop();
        if (d > res[cur]) continue;
        
        for (auto &e : adj[cur]) {
            long double w = e.fi;
            int v = e.se;
            if (res[v] > res[cur] + w) {
                res[v] = res[cur] + w;
                pq.push({res[v], v});
                ans.pb({cur, v});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    file("truyentin")
    cin >> n;
    for (int i = 1; i <= n; i++) {
        res[i] = 1e18L;
        adj[i].clear();
    }
    res[1] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> tow[i].x >> tow[i].y >> tow[i].s;
        for (int j = 1; j < n; j++) {
            cin >> tow[i].a[j];
        }
    }
    for (int i = 1; i <= n; i++) {
        vector<pair<long double,int>> tmp;
        tmp.reserve(n-1);
        for (int j = 1; j < n; j++) {
            int v = tow[i].a[j];
            long double d = dist(tow[i], tow[v]);
            tmp.eb(d, v);
        }
        sort(all(tmp));
        for (int k = 0; k < tow[i].s && k < (int)tmp.size(); k++) {
            adj[i].eb(tmp[k]);
        }
    }
    
    bfs(1);
    cout << fixed << setprecision(10);
    for (int i = 1; i <= n; i++) {
        cout << res[i] << "\n";
    }
    for (auto &p : ans) {
        cout << p.fi << " " << p.se << "\n";
    }
    return 0;
}
