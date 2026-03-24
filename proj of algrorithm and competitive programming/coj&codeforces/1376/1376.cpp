#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n,a[1003];
vector<int>adj[1003],topo;
int in[1003],d[1003];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    memset(d,-1,sizeof(d));
    queue<int>q;
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    sort(a+1,a+1+n);
    for(int i=1; i<=n; i++) {
        for(int j=i+1; j<=n; j++) {
            int t=a[i]+a[j];
            int p=lower_bound(a+1,a+1+n,t)-a;
            /*while(a[p]==a[i]+a[j]) {
                int u=a[i],v=a[j],y=a[p];
                adj[u].push_back(y);
                adj[v].push_back(y);
                in[y]+=2;
            }*/
            for(int k=p; k<=n; k++) {
                if(a[i]+a[j]!=a[k]) break;
                int u=a[i],v=a[j],y=a[p];
                adj[u].push_back(y);
                adj[v].push_back(y);
                in[y]+=2;
            }
        }
    }
    for(int i=1; i<=n; i++) {
        if(in[i]==0) {
            q.push(i);
            d[i]=0;
        }
    }
    while(!q.empty()) {
        int u=q.front();
        q.pop();
        topo.push_back(u);
        for(int v:adj[u]) {
            in[v]--;
            if(in[v]==0) q.push(v);
            d[v]=max(d[v],d[u]+1);
        }
    }
    cout << *max_element(d+1,d+1+n);
}
