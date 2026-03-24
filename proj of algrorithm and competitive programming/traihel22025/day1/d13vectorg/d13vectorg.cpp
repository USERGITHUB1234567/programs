#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
using namespace std;
#define all(x) x.begin(),x.end()
#define eb emplace_back
typedef long long ll;
const int maxn=1003,maxm=21;
int n,m;
int a[maxn][maxm];
vector<int>res[maxn];
struct disjoint_set {
    int p[maxn];
    void init() {
        for(int i=0; i<maxn; i++) p[i]=i;
    }
    int found(int u) {
        return (p[u]==u?u:p[u]=found(p[u]));
    }
    void unite(int u, int v) {
        u=found(u);
        v=found(v);
        if(u!=v) p[v]=u;
    }
}dsu;
bool check(int u, int v) {
    sort(a[u]+1,a[u]+1+m);
    sort(a[v]+1,a[v]+1+m);
    int side=0;
    if(a[u][1]>=a[v][1]) side=1;
    else side=2;
    bool ck=false;
    for(int i=1; i<=m; i++) {
        if(side==1 && a[u][i]>a[v][i]) {
            ck=true;
            break;
        }
        else if(side==2 && a[u][i]<a[v][i]) {
            ck=true;
            break;
        }
    }
    return ck;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    dsu.init();
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) cin >> a[i][j];
    }
    for(int i=1; i<=n; i++) {
        for(int j=i+1; j<=n; j++) {
            if(check(i,j)) {
                dsu.unite(i,j);
            }
        }
    }
    int kn=0;
    for(int i=1; i<=n; i++) {
        res[dsu.found(i)].push_back(i);
        kn=max(kn,dsu.found(i));
    }
    cout << kn << "\n";
    for(int i=1; i<=kn; i++) {
        if(res[i].empty()) continue;
        cout << res[i].size() << " ";
        for(int j=0; j<res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }
}