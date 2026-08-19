#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n,m,d1[100001],w1[100001], p1[100001],d2[100001],w2[100001],p2[100001];
vector<pair<int,int>> adj[100001];
void bfs(int s,int d[100001],int w[100001], int p[100001])
{
    //memset(d,-1,sizeof(d));
    fill(d,d+n+1,-1);
    fill(w,w+n+1,-2e9);
    fill(p,p+n+1,0);
    d[s]=0;
    vector<int>q;
    q.push_back(s);
    for(int i=0; i<q.size(); i++) {
        int u=q[i];
        for(auto[v,c]:adj[u]) {
            if(d[v]==-1) {
                d[v]=d[u]+1;
                q.push_back(v);
            }
        }
    }

    for(int i=0; i<q.size(); i++) {
        int u=q[i];
        for(auto[v,c]:adj[u]) {
            if(d[v]==d[u]+1 and w[v]<max(w[u],c)) {
                w[v]=max(w[u],c);
                p[v]=u;
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for(int i=1; i<=m; i++) {
        int u,v,c;
        cin >> u >> v >> c;
        adj[u].push_back({v,c});
        adj[v].push_back({u,c});
    }
    int u,dif=-1;
    vector<int>ans;
    for(int k=1; k<=2; k++) {
        bfs(1,d1,w1,p1);
        if(d1[n]==1) {
            cout << 1 << "\n";
            cout << 1 << " " << n;
            return 0;
        }
        for(int u=1; u<=n; u++) {
            for(int i=0; i<adj[u].size(); i++)
                adj[u][i].second=-adj[u][i].second;
        }
        bfs(n,d2,w2,p2);
        int dif_cur=-1;
        for(int i=2; i<=n-1; i++) {
            if(d1[i]+d2[i]==d1[n])
            if(dif_cur<w1[i]+w2[i]) {
                u=i;
                dif_cur=w1[i]+w2[i];
            }
        }
        if(dif_cur>dif) {
            ans.clear();
            int v=p2[u];
            while(u!=0) {
                ans.push_back(u);
                u=p1[u];
            }
            reverse(ans.begin(),ans.end());
            while(v!=0) {
                ans.push_back(v);
                v=p2[v];
            }
        }
    }
    cout << d1[n] << "\n";
    for(int i=0; i<ans.size()-1; i++)
        cout << ans[i] << " ";
    cout << ans.back();
    return 0;
}
