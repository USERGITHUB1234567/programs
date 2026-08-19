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
const int maxn=100005;
int n,q,v[maxn],st[maxn],en[maxn],timer=0;
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
    long long s=0;
    while(i>0) {
        s+=ft[i];
        i-=i&-i;
    }
    return s;
}
void upd(int i, long long v) {
    while(i<=n) {
        ft[i]+=v;
        i+=i&-i;
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> q;
    for(int i=1; i<=n; i++) cin >> v[i];
    for(int i=1; i<n; i++) {
        int u,v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
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