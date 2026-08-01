#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#define int long long
#define file(name) freopen(name".inp","r",stdin); freopen(name".out","w",stdout)
using namespace std;
int n, m, k, a[200005], dl[200005], dr[200005];
vector<pair<int,int>> ke[200005];
void dijkstra(int s, int dist[]) {
    for(int i = 1; i <= n; i++)
        dist[i] = 4e18;
    dist[s] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({dist[s], s});
    while(!pq.empty()) {
        auto [curd, u] = pq.top();
        pq.pop();
        if(curd > dist[u]) continue;
        for(auto [v, w] : ke[u])
            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for(int i=1;i<=k;i++)
        cin >> a[i];
    for(int i=1;i<=m;i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        ke[x].push_back({y,w});
        ke[y].push_back({x,w});
    }
    dijkstra(a[1], dl);
    int goc=a[1];  
    for(int i=1;i<=k;i++)
        if(dl[a[i]]>dl[goc])
            goc=a[i];
    dijkstra(goc, dl);
    int bot=goc;
    for(int i=1;i<=k;i++)
        if(dl[a[i]]>dl[bot])
            bot=a[i];
    dijkstra(bot, dr);
    int dist=dl[bot];
    for(int i=1;i<=k;i++)
        if(dl[a[i]]+dr[a[i]]!=dist)
        {
            cout << 0;
            return 0;
        }
    vector<int> ans;
    for(int i=1;i<=n;i++)
        if(dl[bot]+dr[i]==dl[i] || dr[goc]+dl[i]==dr[i])
            ans.push_back(i);
    cout << ans.size() << "\n";
    for(int i=0;i<ans.size();i++)
        cout << ans[i] << " ";
    return 0;
}