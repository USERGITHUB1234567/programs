#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n,m,p[1001],h[1001];
void makeset()
{
    for(int i=1; i<=n; i++) {
        h[i]=0;
        p[i]=i;
    }
}
int findset(int u)
{
    if(p[u]==u) return u;
    return p[u]=findset(p[u]);
}
void unionset(int u, int v)
{
    u=findset(u);
    v=findset(v);
    if(u==v) return;
    if(h[u]<h[v]) swap(u,v);
    p[v]=u;
    if(h[u]==h[v]) h[u]++;
}
int main()
{
    cin >> n >> m;
    makeset();
    map<int ,int>en;
    for(int i=1; i<=m; i++) {
        char c;
        cin >> c;
        int u,v;
        cin >> u >> v;
        if(c=='F') {
            unionset(u,v);
        }
        else {
            if(en[u]!=0) unionset(en[u],v);
            if(en[v]!=0) unionset(en[v],u);
            en[u]=v;
            en[v]=u;
        }
    }
    set<int>st;
    st.insert(findset(1));
    for(int i=2; i<=n; i++) {
        st.insert(findset(i));
    }
    cout << st.size();
}
