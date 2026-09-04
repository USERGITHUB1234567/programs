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
namespace cookedsoup{
    int d[2][maxn],g[2][maxn][2];
    bool vis[maxn];
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
                    g[type][v][d[type][v]&1]=d[type][v];
                    q.push(v);
                }else if(((d[type][u]+1)&1) != (d[type][v]&1) && !vis[v]) {
                    g[type][v][(d[type][u]+1)&1]=d[type][u]+1;
                    vis[v]=true;
                }
            }
        }
    }
    void implement() {
        bfs(1,0);
        bfs(1,1);

    }
}
namespace cookedsoupfinale {
    const int mx_dist=200005;
    int dist[2][maxn][2];
    void bfs(int type) {
        for(int i=1; i<=n[type]; ++i) {
            dist[type][i][0]=1e9;
            dist[type][i][1]=1e9;
        }
        queue<pair<int,int>>q;
        dist[type][1][0]=0; 
        q.push({1,0});
        while(!q.empty()) {
            auto [u,p]=q.front();
            q.pop();
            for(int v:adj[type][u]) {
                if(dist[type][v][p^1]==1e9) {
                    dist[type][v][p^1]=dist[type][u][p]+1;
                    q.push({v,p^1});
                }
            }
        }
    }
    void implement() {
        bfs(0);
        bfs(1);
        vector<long long> cnt1_even(mx_dist,0),cnt2_even(mx_dist,0),cnt1_odd(mx_dist,0),cnt2_odd(mx_dist,0),cnt1_max(mx_dist,0),cnt2_max(mx_dist,0);
        for(int i=1; i<=n[0]; ++i) {
            if(dist[0][i][0]<1e9) cnt1_even[dist[0][i][0]]++;
            if(dist[0][i][1]<1e9) cnt1_odd[dist[0][i][1]]++;
            int mx=max(dist[0][i][0],dist[0][i][1]);
            if(mx<1e9) cnt1_max[mx]++;
        }
        for(int i=1; i<=n[1]; ++i) {
            if(dist[1][i][0]<1e9) cnt2_even[dist[1][i][0]]++;
            if(dist[1][i][1]<1e9) cnt2_odd[dist[1][i][1]]++;
            int mx=max(dist[1][i][0], dist[1][i][1]);
            if(mx<1e9) cnt2_max[mx]++;
        }
        for(int i=1; i<mx_dist; ++i) {
            cnt1_even[i]+=cnt1_even[i-1];
            cnt2_even[i]+=cnt2_even[i-1];
            cnt1_odd[i]+=cnt1_odd[i-1];
            cnt2_odd[i]+=cnt2_odd[i-1];
            cnt1_max[i]+=cnt1_max[i-1];
            cnt2_max[i]+=cnt2_max[i-1];
        }
        long long sumchan=0,sumle=0,summax=0;
        for(int i=0; i<mx_dist; i+=2) {
            long long cur=(cnt1_even[i]%mod)*(cnt2_even[i]%mod)%mod;
            long long prev=(i>=2)?(cnt1_even[i-2]%mod)*(cnt2_even[i-2]%mod)%mod:0;
            long long pairs=(cur-prev+mod)%mod;
            sumchan=(sumchan+pairs*i)%mod;
        }
        for(int i=1; i<mx_dist; i+=2) {
            long long cur=(cnt1_odd[i]%mod)*(cnt2_odd[i]%mod)%mod;
            long long prev=(i>=2)?(cnt1_odd[i-2]%mod)*(cnt2_odd[i-2]%mod)%mod:0;
            long long pairs=(cur-prev+mod)%mod;
            sumle=(sumle+pairs*i)%mod;
        }
        for(int i=0; i<mx_dist; ++i) {
            long long cur=(cnt1_max[i]%mod)*(cnt2_max[i]%mod)%mod;
            long long prev=(i>=1)?(cnt1_max[i-1]%mod)*(cnt2_max[i-1]%mod)%mod:0;
            long long pairs=(cur-prev+mod)%mod;
            summax=(summax+pairs*i)%mod;
        }
        long long ans=(sumchan+sumle-summax)%mod;
        if(ans<0) ans+=mod;
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
    cookedsoupfinale::implement();
}