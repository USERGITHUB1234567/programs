#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define fi first
#define se second
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define file(x) freopen(x".inp", "r", stdin);freopen(x".out", "w", stdout);
#define pb push_back

using namespace std;

typedef long long ll;
const int N = 1505;
const int Q = 1e5 + 5;
const ll INF = 1e18;
const int MOD = 1e9 + 7;
const int LOG = 20;
const int di[4] = {1, 0, -1, 0};
const int dj[4] = {0, 1, 0, -1};

int n, m, q, w, stx, sty, ex, ey;

namespace sub12
{
ll a[N][N], d[N][N];
void bfs(int s, int e)
{
 queue<pair<int, int>> q;
 q.push({s, e});
 d[s][e] = 0;
 while (!q.empty()) {
  int u = q.front().fi, v = q.front().se;
  q.pop();
  for (int k = 0; k < 4; k++) {
   int x = u + di[k], y = v + dj[k];
   if (x < 1 || x > n || y < 1 || y > m) continue;
   if (d[x][y] == INF) q.push({x, y});
   d[x][y] = min(d[x][y], d[u][v] + a[u][v]);
  }
 }
}
void solve()
{
 for (int i = 1; i <= n; i++) {
  for (int j = 1; j <= m; j++) {
   cin >> a[i][j];
   d[i][j] = INF;
  }
 }
 cin >> stx >> sty >> ex >> ey;
 bfs(stx, sty);
 cout << d[ex][ey];
}
}

namespace sub345
{
   vector<pair<int, int>> adj[Q];
   ll a[N][N], d[N][N], id[1000006], fd[Q];

   void dijkstra()
   {
       d[stx][sty] = 0;
       priority_queue<pair<ll, pair<int, int>>> pq;
       pq.push({0, {stx, sty}});
       while (!pq.empty()) {
           ll cur_d = -pq.top().fi;
           auto [u, v] = pq.top().se;
           pq.pop();
           if (v == 0) {
               if (cur_d < fd[u]) continue;
               for (auto [x, y] : adj[u]) {
                   if (d[x][y] > fd[u] + w) {
                       d[x][y] = fd[u] + w;
                       pq.push({-d[x][y], {x, y}});
                   }
               }
           }
           else {
               if (cur_d < d[u][v]) continue;
               int pos = id[a[u][v]];
               if (pos != 0) {
                   if (fd[pos] > d[u][v]) {
                       fd[pos] = d[u][v];
                       pq.push({-fd[pos], {pos, 0}});
                   }
               }
               for (int k = 0; k < 4; k++) {
                   int x = u + di[k], y = v + dj[k];
                   if (x < 1 || x > n || y < 1 || y > m) continue;
                   if (d[x][y] > d[u][v] + a[u][v]) {
                       d[x][y] = d[u][v] + a[u][v];
                       pq.push({-d[x][y], {x, y}});
                   }
               }
           }
       }
   }

   void solve()
   {
       cin >> n >> m >> q >> w;
       for (int i = 1; i <= n; i++) {
           for (int j = 1; j <= m; j++) {
               cin >> a[i][j];
               d[i][j] = INF;
           }
       }
       for (int i = 1; i <= q; i++) {
           int l, r;
           cin >> l >> r;
           fd[i] = INF;
           for (int j = l; j <= r; j++)
               id[j] = i;
       }
       for (int i = 1; i <= n; i++) {
           for (int j = 1; j <= m; j++) {
               adj[id[a[i][j]]].pb({i, j});
           }
       }
       cin >> stx >> sty >> ex >> ey;
       dijkstra();
       cout << d[ex][ey];
   }
}

int main()
{
fast
file("thamhiem");
sub345 :: solve();
return 0;
}