#include <bits/stdc++.h>
using namespace std;
const int maxn=200005;
int n,d,b[maxn],s[maxn],h[maxn];
vector<int>adj[maxn];
namespace soup1{
    int par[maxn],cnt[maxn];
    void dfs(int u, int p) {
        for(int v:adj[u]) {
            if(v!=p) {
                par[v]=u;
                dfs(v,u);
            }
        }
    }
    int query(int k) {
        int home=h[k];
        set<int>st;
        while(home!=1) {
            //cerr << home << '\n';
            if(cnt[home]<b[home]) {
                ++cnt[home];
                st.insert(s[home]);
            }
            home=par[home];
        }
        if(cnt[1]<b[1]) {++cnt[1];st.insert(s[1]);}
        return st.size();
    }
    void implement() {
        dfs(1,0);
        //for(int i=1; i<=n; ++i) cout << par[i] << ' ';
        for(int i=1; i<=d; ++i) {
            cout << query(i) << ' ';
        }
    }
}
namespace soup2{
    void implement() {
        
    }
}
namespace soupfull{
    void implement() {

    }
}
int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    freopen("dragonfly.inp", "r", stdin);
    freopen("dragonfly.out", "w", stdout);
    cin >> n >> d;
    for(int i=1; i<=n; ++i) cin >> b[i];
    for(int i=1; i<=n; ++i) cin >> s[i];
    for(int i=1; i<=d; ++i) cin >> h[i];
    for(int i=1,u,v; i<n; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    soup1::implement();
}