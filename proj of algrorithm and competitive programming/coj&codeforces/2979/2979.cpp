#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
#define int long long
using namespace std;
const int maxn=200005;
int n,q,v[maxn],timer=0,st[maxn],en[maxn];
long long ft[maxn];
vector<int>adj[maxn];
void dfs(int u, int p) {
    st[u]=++timer;
    for(int v:adj[u]) {
        if(v==p) continue;
        dfs(v,u);
    }
    en[u]=timer;
}
long long sum(int i) {
    int res=0;
    while(i>0) {
        res+=ft[i];
        i-=i&-i;
    }
    return res;
}
void upd(int i, int v) {
    while(i<=n) {
        ft[i]+=v;
        i+=i&-i;
    }
}
signed main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> q;
    for(int i=1; i<=n; i++) cin >> v[i]; 
    for(int i=1; i<n; i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    for(int i=1; i<=n; i++) {
        upd(st[i],v[i]);
        upd(en[i]+1,-v[i]);
    }
    while(q--) {
        int t;
        cin >> t;
        if(t==1) {
            int s,x;
            cin >> s >> x;
            upd(st[s],x-v[s]);
            upd(en[s]+1,-(x-v[s]));
            v[s]=x;
        }
        else {
            int s;
            cin >> s;
            cout << sum(st[s]) << "\n";
        }
    }
}