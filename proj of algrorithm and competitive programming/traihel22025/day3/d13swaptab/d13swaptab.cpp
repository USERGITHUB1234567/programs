#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
#define all(x) x.begin(),x.end()
#define eb emplace_back
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
const int maxn=55;
int t;
int c[maxn][maxn],pos[maxn][maxn];
struct ops {
    int u,v,s,t;
};
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> t;
    while(t--) {
        int m,n;
        cin >> m >> n;
        vector<ops>ans;
        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                cin >> c[i][j];
                pos[c[i][j]][i]=j;
            }
        }
        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                if(c[i][j]!=j) {
                    int u=i,v=j,s=i,t=pos[j][i];
                    ans.pb({u,v,s,t});
                    swap(c[i][j],c[s][t]);
                    pos[c[i][j]][u]=v;
                    pos[c[u][v]][i]=t;
                }
            }
        }
        cout << ans.size() << "\n";
        for(auto [u,v,s,t]:ans) {
            cout << u << " " << v << " " << s << " " << t << "\n";
        }
        /*for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
               cout << c[i][j] << " ";
            }
            cout << "\n";
        }*/
    }
}