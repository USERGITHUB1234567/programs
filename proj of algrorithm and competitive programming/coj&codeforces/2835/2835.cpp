#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int maxn=1000006;
int q;
struct disjseu
{
    int p[maxn],d[maxn];
    bool ck[maxn];
    void setup()
    {
        for(int i=0; i<maxn; i++) {
            p[i]=i;
            d[i]=0;
        }
    }
    int findset(int u)
    {
        if(p[u]==u) return u;
        int pold=p[u],pnew=findset(p[u]);
        d[u]+=d[pold];
        return p[u]=pnew;
    }
    void unite(int u, int v)
    {
        u=findset(u);
        v=findset(v);
        if(u!=v) p[u]=v;
    }
} dsu;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> q;
    dsu.setup();
    int ord=1;
    while(q--) {
        char c;
        cin >> c;
        dsu.p[ord]=ord;
        dsu.d[ord]=0;
        if(c=='+') {
            int n;
            cin >> n;
            for(int i=1; i<=n; i++) {
                int x;
                cin >> x;
                dsu.p[x]=ord;
                dsu.d[x]=1;
            }
            ord++;
        }
        else {
            int x;
            cin >> x;
            dsu.findset(x);
            if(dsu.d[x]%2==0) cout << 1;
            else cout << 0;
        }
    }
}
