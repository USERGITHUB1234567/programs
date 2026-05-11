#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n, p[100001][17],a[100001],logn;
bool isnode[100001];
/*int lca(int u,int v)
{
    if(u>v) swap(u,v);
    for(int j=logn; j>=0; j--) {
        if(d[p[u][j]]>=d[v]) u=p[u][j];
    }
    if(u==v) return ;
    for(int j=lognn; j>=0; j--) {
        if(p[u][j]!=d[v][j]) {
            u=p[u][j];
            v=p[v][j];
        }
    }
    return p[u][0];
}*/
int main()
{
    cin >> n;
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    for(logn=1; (1<<logn)<=n; logn++);
    logn--;
    memset(a,0,sizeof(a));
    memset(p,0,sizeof(p));
    memset(isnode,false,sizeof(isnode));

    for(int i=1; i<=n; i++) {
        int x,y;
        cin >> x >> y;
        a[i]=x;
        p[x][0]=y;
        isnode[x]=true;
    }
    for(int j=1; j<=logn; j++) {
        for(int i=0; i<=n; i++) {
            p[a[i]][j]=p[p[a[i]][j-1]][j-1];
        }
    }
    int q;
    cin >> q;
    while(q--) {
        int t;
        cin >> t;
        if(t==0) {
            int y,x;
            cin >> y >> x;
            isnode[x]=true;
            p[x][0]=y;
            for(int j=1; j<=16; j++) p[x][j]=p[p[x][j-1]][j-1];
        }
        else {
            if(t==1) {
                int x;
                cin >> x;
                isnode[x]=false;
                for(int j=1; j<=16; j++) p[x][j]=0;
            }
            else {
                int x,k;
                cin >> x >> k;
                if(!isnode[x]) cout << 0 << "\n";
                else {
                    for(int j=0; j<=16; j++) {
                        if(((k>>j)&1)==1) x=p[x][j];

                    }
                    cout << x << "\n";
                }
            }
        }
    }
    return 0;
}
