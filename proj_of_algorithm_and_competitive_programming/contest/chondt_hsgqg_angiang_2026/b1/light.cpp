#include <bits/stdc++.h>
using namespace std;
int m,n,q;
struct fenwick_tree {
    vector<vector<int>>bit;
    int m,n;
    fenwick_tree(int _m, int _n):m(_m),n(_n) {bit.assign(m+1,vector<int>(n+1,0));}
    void add(int u, int v_init, int x) {
        for(; u<=m; u+=u&-u) {
            for(int v = v_init; v<=n; v+=v&-v) bit[u][v]+=x;
        }
    }
    int sum(int u, int v) {
        int res=0;
        for(; u; u-=u&-u) {
            for(int vc=v; vc; vc-=vc&-vc) res+=bit[u][vc];
        }
        return res;
    }
    void rect_update(int a, int b, int u, int v, int x) {
        add(a,b,x);
        add(u+1,v+1,x);
        add(u+1,b,-x);
        add(a,v+1,-x);
    }
    int rect_sum(int a, int b, int u, int v) {
        return sum(u,v)-sum(u,b-1)-sum(a-1,v)+sum(a-1,b-1);
    }
};
int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> m >> n >> q;
    //fenwick_tree fen(m,n);
    int ans=0;
    vector<vector<int>>dif;
    dif.assign(m+2,vector<int>(n+2,0));
    while(q--) {
        int x,y,u,v;cin >> x >> y >> u >> v;
        dif[x][y]^=1;
        dif[x][v+1]^=1;
        dif[u+1][y]^=1;
        dif[u+1][v+1]^=1;
    }
    for(int i=1; i<=m; ++i) for(int j=1; j<=n; ++j) {
        dif[i][j]^=dif[i][j-1]^dif[i-1][j]^dif[i-1][j-1];
        if(dif[i][j]) ++ans;
    }
    cout << ans;
}