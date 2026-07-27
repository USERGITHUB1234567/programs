#pragma GCC optimize("O3","Ofast")
#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;
int n,m,c[maxn],ans[maxn];
vector<int>adj[maxn];
unordered_map<int,int>cnt[maxn];
unordered_map<int,bool>mk[maxn];
multiset<int>st[maxn];
vector<pair<int,int>>query[maxn];
void dfs(int u, int p) {
    cnt[u][c[u]]=1;
    mk[u][c[u]]=true;
    st[u].insert(1);
    for(int v:adj[u]) {
        if(v!=p) {
            dfs(v,u);
            if(cnt[u].size()<cnt[v].size()) {
                cnt[u].swap(cnt[v]);
                mk[u].swap(mk[v]);
                st[u].swap(st[v]);
            }
            for(auto[a,b]:cnt[v]) {
                if(mk[u][a]) {
                    auto it=st[u].find(cnt[u][a]);
                    if(it!=st[u].end()) st[u].erase(it);
                    cnt[u][a]+=b;
                    st[u].insert(cnt[u][a]);
                } else {
                    cnt[u][a]=b;
                    mk[u][a]=true;
                    st[u].insert(b);
                }
            }
            st[v].clear();
            mk[v].clear();
            cnt[v].clear();
        }
    }
    for(auto[k,i]:query[u]) {
        auto it=st[u].lower_bound(k);
        ans[i]=distance(it, st[u].end());
    }
}
int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> m;
    for(int i=1; i<=n; ++i) cin >> c[i];
    for(int i=1,u,v; i<n; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1; i<=m; ++i) {
        int v,k;cin >> v >> k;
        query[v].push_back({k,i});
    }
    dfs(1,0);
    for(int i=1; i<=m; ++i) cout << ans[i] << '\n';
}