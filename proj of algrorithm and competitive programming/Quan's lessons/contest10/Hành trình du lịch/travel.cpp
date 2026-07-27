#include <bits/stdc++.h>
using namespace std;
const int maxn=1003;
int n,m;
vector<pair<int,long double>>adj[maxn];
bool check(long double mid) {
    vector<long double>dist(n+1,0);
    vector<bool>inqueue(n+1,true);
    vector<int>cnt(n+1,0);
    queue<int>q;
    for(int i=1; i<=n; ++i) q.push(i);
    while(!q.empty()) {
        int u=q.front();q.pop();
        inqueue[u]=false;
        for(auto[v,c]:adj[u]) {
            long double w=c-mid;
            if(dist[v]>dist[u]+w) {
                dist[v]=dist[u]+w;
                cnt[v]=cnt[u]+1;
                if(cnt[v]>=n) return true;
                if(!inqueue[v]) {
                    inqueue[v]=true;
                    q.push(v);
                }
            }
        }
    }
    return false;
}
int main(int argc, char** argv) {
    cin >> n >> m;
    for(int i=1; i<=m; ++i) {
        int u,v;long double c;cin >> u >> v >> c;
        adj[u].push_back({v,c});
    }
    if(!check(1e10)) {cout << "NO TOUR";return 0;}
    long double l=0,r=1e9,ans;
    for(int i=1; i<=100; ++i) {
        long double mid=(l+r)/2;
        if(check(mid)) {
            ans=mid;
            r=mid;
        }
        else l=mid;
    }
    cout << fixed << setprecision(2) << ans;
}