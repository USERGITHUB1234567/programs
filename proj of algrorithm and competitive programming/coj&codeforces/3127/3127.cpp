#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
using namespace std;
const int maxn=200005;
int n,q,st[maxn],en[maxn],timer=0,d[maxn];
vector<int>adj[maxn],ld[maxn];
void dfs(int u) {
    st[u]=++timer;
    ld[d[u]].push_back(st[u]);
    for(int v:adj[u]) {
        d[v]=d[u]+1;
        dfs(v);
    }
    en[u]=timer;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n;
    for(int i=2; i<=n; i++) {
        int x;
        cin >> x;
        adj[x].push_back(i);
    }
    d[1]=0;
    dfs(1);
    cin >> q;
    while(q--) {
        int u,de;
        cin >> u >> de;
        if(d[u]>de) {
            cout << 0 << "\n";
            continue;
        }
        auto &v=ld[de];
        int l=int(lower_bound(v.begin(),v.end(),st[u])-v.begin()),r=int(upper_bound(v.begin(),v.end(),en[u])-v.begin());
        cout << r-l << "\n";
    }
}