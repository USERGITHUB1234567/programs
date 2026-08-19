#include <bits/stdc++.h>
using namespace std;
const int maxn=200005;
int n,q,a[maxn],tin[maxn],tout[maxn],timer;
vector<int>adj[maxn];
void dfs(int u, int p) {
    tin[u]=++timer;
    for(int v:adj[u]) {
        if(v!=p) dfs(v,u);
    }
    tout[u]=timer;
}
struct fenwick_tree{
    vector<long long>bit;
    int n;
    fenwick_tree(int _n):n(_n+1) {bit.assign(n+2,0);} 
    void add(int i, long long v) {
        while(i<=n) {
            bit[i]+=v;
            i+=i&-i;
        }
    }
    long long sum(int i) {
        long long res=0;
        while(i) {
            res+=bit[i];
            i-=i&-i;
        }
        return res;
    }
};
int main(int argc, char** argv) {
    cin >> n >> q;
    for(int i=1; i<=n; ++i) cin >> a[i];
    for(int i=1; i<n; ++i) {
        int u,v;cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    fenwick_tree ft(n);
    for(int i=1; i<=n; ++i) {ft.add(tin[i],a[i]);ft.add(tout[i]+1,-a[i]);}
    while(q--) {
        int t,s,x;cin >> t;
        if(t==1) {
            cin >> s >> x;
            ft.add(tin[s],x-a[s]);
            ft.add(tout[s]+1,a[s]-x);
            a[s]=x;
        }
        else {
            cin >> s;
            cout << ft.sum(tin[s]) << '\n';
        }
    }
}