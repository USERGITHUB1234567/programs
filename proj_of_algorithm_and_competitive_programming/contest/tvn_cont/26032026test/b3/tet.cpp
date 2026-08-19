#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
const int INF = 1000000007;
int n,m,q;
pair<int,int> edge[maxn];
pair<int,int> queries[maxn];
pair<int,int> rangeQ[maxn];
int first_connect[maxn];
int parent[maxn], sz[maxn];
vector<int> comp[maxn];
int st[18][maxn];
int lg2[maxn];

int findp(int x) {
    return parent[x]==x ? x : parent[x]=findp(parent[x]);
}

void unite(int u, int v, int e) {
    u=findp(u); v=findp(v);
    if(u==v) return;
    if(sz[u] < sz[v]) swap(u,v);
    for(int x : comp[v]) {
        if(x > 1 && findp(x-1) == u) {
            first_connect[x-1] = min(first_connect[x-1], e);
        }
        if(x < n && findp(x+1) == u) {
            first_connect[x] = min(first_connect[x], e);
        }
    }
    for(int x : comp[v]) comp[u].push_back(x);
    parent[v] = u;
    sz[u] += sz[v];
}

int rmq(int l, int r) {
    if(l > r) return 0;
    int k = lg2[r-l+1];
    return max(st[k][l], st[k][r - (1<<k) + 1]);
}

bool check(int qi, int mid) {
    int l = queries[qi].first;
    int r = queries[qi].second;
    if(l > r) swap(l,r);
    if(l == r) return true;
    return rmq(l, r-1) <= mid;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // file("vertices"); // nếu dùng file io
    cin >> n >> m >> q;
    for(int i=1;i<=m;i++) cin >> edge[i].first >> edge[i].second;
    for(int i=1;i<=q;i++) cin >> queries[i].first >> queries[i].second;

    for(int i=1;i<=n;i++) {
        parent[i]=i; sz[i]=1;
        comp[i] = vector<int>({i});
    }
    for(int i=1;i<n;i++) first_connect[i] = INF;
    for(int i=1;i<=m;i++) {
        unite(edge[i].first, edge[i].second, i);
    }

    lg2[1]=0;
    for(int i=2;i<=n;i++) lg2[i]=lg2[i>>1]+1;
    int len=n-1;
    for(int i=1;i<=len;i++) st[0][i] = first_connect[i];
    for(int k=1;(1<<k)<=len;k++){
        for(int i=1;i+(1<<k)-1<=len;i++){
            st[k][i] = max(st[k-1][i], st[k-1][i + (1<<(k-1))]);
        }
    }

    for(int i=1;i<=q;i++) {
        int l=queries[i].first, r=queries[i].second;
        if(l==r) {
            rangeQ[i].first = rangeQ[i].second = 0;
        } else {
            rangeQ[i].first = 1;
            rangeQ[i].second = m;
        }
    }

    bool dirty=true;
    vector<vector<int>> bucket;
    bucket.reserve(m+2);

    while(dirty) {
        dirty=false;
        bucket.assign(m+2, vector<int>());
        for(int i=1;i<=q;i++){
            if(rangeQ[i].first < rangeQ[i].second){
                dirty=true;
                int mid = (rangeQ[i].first + rangeQ[i].second) >> 1;
                bucket[mid].push_back(i);
            }
        }
        if(!dirty) break;
        for(int mid=1; mid<=m; mid++){
            for(int qi : bucket[mid]){
                if(check(qi, mid)) rangeQ[qi].second = mid;
                else rangeQ[qi].first = mid+1;
            }
        }
    }
    for(int i=1; i<=n; ++i) cout << first_connect[i] << ' ';
    for(int i=1;i<=q;i++){
        int ans = rangeQ[i].first;
        if(queries[i].first == queries[i].second) ans = 0;
        if(ans > m) ans = -1; // không nối được
        cout << ans << '\n';
    }

    return 0;
}