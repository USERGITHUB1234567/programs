#include <bits/stdc++.h>
using namespace std;
const int maxn=100005,mlog=18;
int N,M,Q;
int r[maxn];
vector<int>adj[maxn];
int depth[maxn];
int up[maxn][mlog];
int pos[maxn];
int house[maxn];
void dfs(int u, int p) {
    up[u][0]=p;
    for(int i=1;i<mlog; i++) {
        up[u][i]=up[up[u][i-1]][i-1];
    }
    for(int v:adj[u]) {
        if (v!=p) {
            depth[v]=depth[u]+1;
            dfs(v, u);
        }
    }
}
int get_lca(int u, int v) {
    if(depth[u]<depth[v]) swap(u,v);
    int diff=depth[u]-depth[v];
    for(int i=0; i<mlog; i++) {
        if((diff>>i)&1) u=up[u][i];
    }
    if (u==v) return u;
    for (int i=mlog-1; i>=0; i--) {
        if (up[u][i]!=up[v][i]) {
            u=up[u][i];
            v=up[v][i];
        }
    }
    return up[u][0];
}
int solve_query(int p, int R, int dir) {
    int cur = pos[p];
    int mx = depth[pos[p]];
    int cnt = 1;
    int curr = p;
    while (cnt < M) {
        int nxt;
        if (dir==1) {
            nxt=(curr%M)+1;
        } else { 
            nxt=(curr==1)?M:curr-1;
        }
        int u = pos[nxt]; 
        int new_lca = get_lca(cur, u);
        int nm = max(mx, depth[u]);
        if (nm - depth[new_lca] <= R) {
            cur = new_lca;
            mx = nm;
            cnt++;
            curr = nxt;
        } else {
            break;
        }
    }
    return cnt;
}
int main() {
    freopen("party.inp", "r", stdin);
    freopen("party.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> Q;
    int root = 1;
    for (int i = 1; i <= N; i++) {
        cin >> r[i];
        if (r[i] == i) {
            root = i;
        } else {
            adj[r[i]].push_back(i); 
        }
    }
    for (int i = 1; i <= N; i++) {
        house[i] = 0;
    }
    for (int i = 1; i <= M; i++) {
        cin >> pos[i];
        house[pos[i]] = i;
    }
    depth[root] = 0;
    dfs(root, root);
    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int a, b;
            cin >> a >> b;
            int p1 = house[a];
            int p2 = house[b];
            if (p1 != 0) pos[p1] = b;
            if (p2 != 0) pos[p2] = a;
            house[a] = p2;
            house[b] = p1;
        } else if (type == 2) {
            int p, R;
            cin >> p >> R;
            int right = solve_query(p, R, 1);
            int left = solve_query(p, R, -1);
            cout << max(right, left) << "\n";
        }
    }
    
    return 0;
}