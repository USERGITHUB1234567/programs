#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
#define int long long
using namespace std;
const int maxn=502,inf=INT_MAX;
int n,m1,m2,d1[maxn][maxn],d2[maxn][maxn],d3[maxn][maxn];
vector<int>adj1[maxn],adj2[maxn];
void floyd_warshall(int type) {
    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(type==1) {
                    d1[i][j]=min(d1[i][j],d1[i][k]+d1[k][j]);
                }
                else if(type==2) {
                    d2[i][j]=min(d2[i][j],d2[i][k]+d2[k][j]);
                }
                else if(type==3){
                    d3[i][j]=min(d3[i][j],d3[i][k]+d3[k][j]);
                }
            }
        }
    }
}
void setup() {
    for(int i=0; i<maxn; i++) {
        for(int j=0; j<maxn; j++) {
            d1[i][j]=d2[i][j]=d3[i][j]=inf;
            if(i==j) d1[i][j]=d2[i][j]=d3[i][j]=0;
        }
    }
}
signed main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> m1;
    setup();
    for(int i=1; i<=m1; i++) {
        int u,v;
        cin >> u >> v;
        //adj1[u].push_back(v);
        //adj1[v].push_back(u);
        d1[u][v]=1;
        d1[v][u]=1;
    }
    cin >> m2;
    for(int i=1; i<=m2; i++) {
        int u,v;
        cin >> u >> v;
        //adj2[u].push_back(v);
        //adj2[v].push_back(u);
        d2[u][v]=1;
        d2[v][u]=1;
    }
    floyd_warshall(1);
    floyd_warshall(2);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            d3[i][j]=max(d1[i][j]+d2[i][j]-1,0LL);
            //cout << d1[i][j] << " " << d2[i][j] << "\n";
        }
    }
    floyd_warshall(3);
    int kq=0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            kq+=d3[i][j];
            //cout << d3[i][j] << "\n";
        }
    }
    cout << kq;
}