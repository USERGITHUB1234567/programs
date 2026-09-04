#include <bits/stdc++.h>
using namespace std;
const int maxn=40004,maxm=100005,mod=1000000007;
int n[2],m[2];
vector<int>adj[2][maxn];
namespace soupfull{
    int d[2][maxn];
    void bfs(int s, bool type) {
        queue<int>q;
        for(int i=1; i<=n[type]; ++i) d[type][i]=1e9;
        d[type][s]=0;
        q.push(s);
        while(!q.empty()) {
            int u=q.front();q.pop();
            for(int v:adj[type][u]) {
                if(d[type][v]==1e9) {
                    d[type][v]=d[type][u]+1;
                    q.push(v);
                }
            }
        }
    }
    void implement() {
        bfs(1,0);
        bfs(1,1);
        //long long sum=0,ans=0;for(int i=1; i<=n[1]; ++i) if(d[1][i]!=1e9)sum=(sum+d[1][i])%mod;
        // for(int i=1; i<=n[0]; ++i) {
        //     if(d[0][i]!=1e9)ans=(ans+sum+d[0][i])%mod;
        // }
        long long ans=0;
        for(int i=1; i<=n[0]; ++i) {
            for(int j=1; j<=n[1]; ++j) {
                //cout << d[0][i] << ' ' << d[1][j] << ' ' << i << ' ' << j << '\n';
                int mn=min(d[0][i],d[1][j]),mx=max(d[0][i],d[1][j]);
                if(!((mx-mn)&1)) ans=(ans+mx)%mod;
            }
        }
        cout << ans;
    }
}
int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    freopen("gen.inp", "r", stdin);
    freopen("gen.out", "w", stdout);
    cin >> n[0] >> m[0];
    for(int i=1; i<=m[0]; ++i) {
        int u,v;cin >> u >> v;
        adj[0][u].push_back(v);
        adj[0][v].push_back(u);
    }
    cin >> n[1] >> m[1];
    for(int i=1; i<=m[1]; ++i) {
        int u,v;cin >> u >> v;
        adj[1][u].push_back(v);
        adj[1][v].push_back(u);
    }
    soupfull::implement();
}