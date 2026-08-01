#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int maxn=100005;
bool vis[maxn];
vector<int>adj[maxn],com;
long long n,m,p,re=1;
long long modexp(long long ba,long long e, long long mod)
{
    long long kq=1;
    while(e>0) {
        if(e&1) kq=(kq*ba)%mod;
        ba=(ba*ba)%mod;
        e>>=1;
    }
    return kq;
}
void bfs(int s, int &k)
{
    queue<int>q;
    q.push(s);
    vis[s]=true;
    while(!q.empty()) {
        int u=q.front();
        q.pop();
        k++;
        for(int v:adj[u]) {
            if(!vis[v]) {
                q.push(v);
                vis[v]=true;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> m >> p;
    for(int i=1; i<=m; i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1; i<=n; i++) {
        if(!vis[i]) {
            int k=0;
            bfs(i,k);
            com.push_back(k);
        }
    }
    long long pro=1;
    for(int i:com) pro=(pro*(i%p))%p;
    long long c=com.size();
    if(c<=1) {
        cout << 1LL%p;
        return 0;
    }
    long long w=modexp(n,c-2,p);
    re=(pro*w)%p;
    cout << re;
}
