#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define file(name) freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout);
#define fi first
#define se second
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
const int maxn=1000006;
int n,k,col[maxn],label[maxn],d[maxn],x[maxn],y[maxn],edge[maxn];
vector<pair<int,int>>adj[maxn];
pair<int,int>qu[maxn];
int prs1[maxn];
int mk[maxn];
struct disjointsets {
    int p[maxn];
    disjointsets() {
        for(int i=0; i<maxn; ++i) p[i]=i;
    }
    int found(int u) {
        return (u==p[u]?u:p[u]=found(p[u]));
    }
    int unite(int u, int v) {

    }
};
/*void soup1()
{
    stack<int>st;
    for(int i=1; i<=k; ++i) {
        auto[u,v]=qu[i];
        mk[u]=i;
        mk[v]=-1;
    }
    int cur=0;
    for(int i=1; i<n; ++i) {
        //cout << mk[i] << " ";
        if(mk[i]==-1) {
            cur=st.top();
            if(!st.empty) st.pop();
        }
        else {
            //cur=max(cur,mk[i]);
            if()
        }
        cout << cur << " ";
    }
}*/
void bfss2(int s, int en, int c)
{
    queue<int>q;
    bool vis[n+10];
    pair<int,int>tr[n+10];
    for(int i=0; i<n+10; i++) {
        tr[i]={0,0};
        vis[i]=false;
    }
    q.push(s);
    tr[s].fi=0;
    vis[s]=true;
    while(!q.empty()) {
        int u=q.front();
        q.pop();
        if(u==en) break;
        vis[u]=true;
        for(auto[v,i]:adj[u]) {
            if(!vis[v]) {
                q.push(v);
                tr[v]={u,i};
            }
        }
    }
    int u=en;
    while(tr[u].fi!=0) {
        col[tr[u].se]=c;
        u=tr[u].fi;
        //cout << col[tr[u].se] << "\n";
        //cout << "a";
    }
    //cout << tr[4].fi << tr[2].fi << tr[1].fi;
}
void soup1rua()
{
    for(int i=1; i<=k; ++i) {
        auto[u,v]=qu[i];
        if(u>v) swap(u,v);
        prs1[u]++;
        prs1[v]--;
    }
    for(int i=1; i<=n; ++i) prs1[i]+=prs1[i-1];
    for(int i=1; i<n; ++i) cout << prs1[i] << " ";
}
void soup2()
{
    for(int i=1; i<=k; ++i) {
        auto[u,v]=qu[i];
        bfss2(u,v,i);
    }
    for(int i=1; i<n; ++i) cout << col[i] << " ";
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    file("tree")
    cin >> n >> k;
    for(int i=1,u,v; i<n; ++i) {
        cin >> u >> v;
        adj[u].eb(v,i);
        adj[v].eb(u,i);
    }
    for(int i=1; i<=k; ++i) cin >> qu[i].fi >> qu[i].se;
    soup2();

}
/*
5 4
3 5
2 3
4 3
5 1
4 1
5 5
4 2
1 5


5 4
1 2
2 3
3 4
4 5
5 5
4 3
2 1
2 4



6 2
1 2
2 3
2 4
1 5
4 6
5 2
6
*/
